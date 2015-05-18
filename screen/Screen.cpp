# include "Screen.hh"
# include "Exception.hh"

Screen::Screen()
{
  _input_mapping.push_back( std::make_pair((int)SDLK_ESCAPE, std::make_pair(MENU, 1)));
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
      _camProjection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
      _camTransformation =
	glm::lookAt(glm::vec3(0, 0, 200), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
      _shader.bind();
      _shader.setUniform("view", _camTransformation);
      _shader.setUniform("projection", _camProjection);
      return (true);
    }
  catch (Error e)
    {
      std::cerr << e.what() << std::endl; 
    }
  return (false);
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
      if (_input.getKey(_input_mapping[i].first, true) == true)
	{
	  tmp.input = _input_mapping[i].second.first;
	  tmp.pid = _input_mapping[i].second.second;
	  events->push_back(tmp);
	}
    }
}

void					Screen::updateScreen(std::vector<AObject*> &map)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; map.size() != i; i++)
    {
      map[i]->draw(_shader);
    }
  _context.flush();
}
