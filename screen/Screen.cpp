# include "Screen.hh"
# include "Exception.hh"

Screen::Screen()
{
  _lockCam = true;
  _input_mapping.push_back( std::make_pair((int)SDLK_ESCAPE, std::make_pair(MENU, 0)));

  _input_mapping.push_back( std::make_pair((int)SDLK_UP, std::make_pair(MOVE_UP, 1)));
  _input_mapping.push_back( std::make_pair((int)SDLK_DOWN, std::make_pair(MOVE_DOWN, 1)));
  _input_mapping.push_back( std::make_pair((int)SDLK_LEFT, std::make_pair(MOVE_LEFT, 1)));
  _input_mapping.push_back( std::make_pair((int)SDLK_RIGHT, std::make_pair(MOVE_RIGHT, 1)));
  _input_mapping.push_back( std::make_pair((int)SDLK_RSHIFT, std::make_pair(PLACE_BOMB, 1)));

  _input_mapping.push_back( std::make_pair((int)SDLK_z, std::make_pair(MOVE_UP, 2)));
  _input_mapping.push_back( std::make_pair((int)SDLK_s, std::make_pair(MOVE_DOWN, 2)));
  _input_mapping.push_back( std::make_pair((int)SDLK_q, std::make_pair(MOVE_LEFT, 2)));
  _input_mapping.push_back( std::make_pair((int)SDLK_d, std::make_pair(MOVE_RIGHT, 2)));
  _input_mapping.push_back( std::make_pair((int)SDLK_a, std::make_pair(PLACE_BOMB, 2)));

  _input_mapping.push_back( std::make_pair((int)SDLK_KP_6, std::make_pair(CAM_XPLUS, 0)));
  _input_mapping.push_back( std::make_pair((int)SDLK_KP_4, std::make_pair(CAM_XMINUS, 0)));
  _input_mapping.push_back( std::make_pair((int)SDLK_KP_8, std::make_pair(CAM_ZPLUS, 0)));
  _input_mapping.push_back( std::make_pair((int)SDLK_KP_2, std::make_pair(CAM_ZMINUS, 0)));
  _input_mapping.push_back( std::make_pair((int)SDLK_KP_9, std::make_pair(CAM_YPLUS, 0)));
  _input_mapping.push_back( std::make_pair((int)SDLK_KP_3, std::make_pair(CAM_YMINUS, 0)));

  _input_mapping.push_back( std::make_pair((int)SDLK_l, std::make_pair(CAM_LOCK, 0)));


  _moveCamMapping[CAM_XPLUS] = glm::vec3(100, 0, 0);
  _moveCamMapping[CAM_XMINUS] = glm::vec3(-100, 0, 0);
  _moveCamMapping[CAM_YPLUS] = glm::vec3(0, 100, 0);
  _moveCamMapping[CAM_YMINUS] = glm::vec3(0, -100, 0);
  _moveCamMapping[CAM_ZPLUS] = glm::vec3(0, 0, -100);
  _moveCamMapping[CAM_ZMINUS] = glm::vec3(0, 0, 100); 

  _camPosition = glm::vec3(0, 500, 1300);
}

Screen::~Screen()
{
}

bool					Screen::init()
{
  try
    {
      if (!_context.start(800, 600, "Bomberbitch"))
	throw Error("Can't initialize context.");
      glEnable(GL_DEPTH_TEST);
      if (!_shader.load("./tp/Shaders/basic.fp", GL_FRAGMENT_SHADER) 
	  || !_shader.load("./tp/Shaders/basic.vp", GL_VERTEX_SHADER) 
	  || !_shader.build())
	throw Error("Can't compile shaders.");
      _camProjection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 5000.0f);
      _camTransformation =
	glm::lookAt(_camPosition, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
      _shader.bind();
      _shader.setUniform("view", _camTransformation);
      _shader.setUniform("projection", _camProjection);

      
      // if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
      // 	{
      // 	  printf("%s", Mix_GetError());
      // 	}
      // Mix_Music *musique; //Création du pointeur de type Mix_Music
      // musique = Mix_LoadMUS("./assets/bo.waw"); //Chargement de la musique
      // Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
      return (true);
    }
  catch (Error e)
    {
      std::cerr << e.what() << std::endl; 
    }
  return (false);
}

double				Screen::getTime() const
{
  return (_clock.getElapsed());
}

void					Screen::updateInputs(std::vector<t_event> *events)
{
  t_event				tmp;

  events->clear();
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  if (_input.getInput(SDL_QUIT, true) == true)
    {
      tmp.input = EXIT;
      tmp.pid = 0;
      events->push_back(tmp);
      return; 
    }
  for (size_t i = 0; _input_mapping.size() != i; i++)
    {
      if (_input.getKey(_input_mapping[i].first) == true)
	{
	  tmp.input = _input_mapping[i].second.first;
	  tmp.pid = _input_mapping[i].second.second;
	  events->push_back(tmp);
	}
    }
}

void					Screen::updateScreen(Map *map)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  map->draw(_shader, _clock);
  _context.flush();
  if (_lockCam == true)
    updateCam(map);
}

glm::vec3				Screen::getMediumPos(Player *p1, Player *p2)
{
  glm::vec3				medium(0 ,0 ,0);  
  glm::vec3				ponepos = p1->getVecPos() ;
  glm::vec3				ptwopos = p2->getVecPos();
    
  medium.x = (ponepos.x + ptwopos.x) / 2;
  medium.z = (ponepos.z + ptwopos.z) / 2;
  return (medium);
}

int					Screen::getHeightCam(Player *p1, Player *p2, 
							     Map *map)
{
  int					segment;
  glm::vec3				ponepos;
  glm::vec3				ptwopos;
  std::pair<int, int>			mapsize;

  if (p1 == NULL && p2 == NULL)
    {
      mapsize = map->getSize();
      if (mapsize.first > mapsize.second)  
	return (mapsize.first * 100);
      return (mapsize.second * 100);
    }
  if (p1 == NULL || p2 == NULL)
    return (500);
  ponepos = p1->getVecPos();
  ptwopos = p2->getVecPos();

  segment = sqrt(pow(ponepos.x - ptwopos.x, 2) + pow(ponepos.z - ptwopos.z, 2));
  if (segment < 500)
    return (500);
  return (segment);
}

glm::vec3				Screen::getCentralPoint(Map *map)
{
  glm::vec3			        centralPoint(0, 0, 0);
  std::pair<int, int>			size;
  
  size = map->getSize();
  centralPoint.x = (size.first / 2) * 100;
  centralPoint.z = (size.second / 2) * 100;
  return (centralPoint);
}

void					Screen::updateCam(Map *map)
{
  Player				*playerone = map->getHumanById(1);
  Player				*playertwo = map->getHumanById(2);	
  glm::vec3				lookAt; 
  
  if (playerone == NULL && playertwo == NULL)
    lookAt = getCentralPoint(map);
  else if (playertwo == NULL)
    lookAt = playerone->getVecPos();
  else if (playerone == NULL)
    lookAt = playertwo->getVecPos();
  else
    lookAt = getMediumPos(playerone, playertwo);

  _camTarget = lookAt;
  _camPosition = glm::vec3(lookAt.x , getHeightCam(playerone, playertwo, map),
			   lookAt.z + 500);
  _camProjection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 5000.0f);
  _camTransformation = 
    glm::lookAt(_camPosition, _camTarget, glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", _camTransformation);
  _shader.setUniform("projection", _camProjection);
}

void					Screen::moveCam(t_input input)
{
  if (_lockCam == false)
    {
      _camPosition += _moveCamMapping[input];
      _camTarget += _moveCamMapping[input];
      _camProjection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 5000.0f);
      _camTransformation = 
	glm::lookAt(_camPosition, _camTarget, glm::vec3(0, 1, 0));
      _shader.bind();
      _shader.setUniform("view", _camTransformation);
      _shader.setUniform("projection", _camProjection);
    }
}

void					Screen::lockCam()
{
  _lockCam = !_lockCam;
}
