#include "GameEngine.hh"

GameEngine::GameEngine(Param const &params):
  _nbHuman(params.getNbHuman()), _nbIA(params.getNbIA())
{
  _funcptrBind[CAM_XPLUS] = &GameEngine::moveCam;  
  _funcptrBind[CAM_XMINUS] = &GameEngine::moveCam;  
  _funcptrBind[CAM_YPLUS] = &GameEngine::moveCam;  
  _funcptrBind[CAM_YMINUS] = &GameEngine::moveCam;  
  _funcptrBind[CAM_ZPLUS] = &GameEngine::moveCam;  
  _funcptrBind[CAM_ZMINUS] = &GameEngine::moveCam;  
  _funcptrBind[MOVE_RIGHT] = &GameEngine::movePlayer;
  _funcptrBind[MOVE_LEFT] = &GameEngine::movePlayer;
  _funcptrBind[MOVE_UP] = &GameEngine::movePlayer;
  _funcptrBind[MOVE_DOWN] = &GameEngine::movePlayer;
  _funcptrBind[CAM_LOCK] = &GameEngine::lockCam;
  _funcptrBind[PLACE_BOMB] = &GameEngine::placeBomb;
  _map = new Map(params.getXY());
  _iaManager = new IA;
}

GameEngine::~GameEngine()
{
}

bool					GameEngine::initialize()
{
  if (_screen.init() == false)
    return (false);
  AssetsController::initAssetsController();
  _map->genRandMap();
  for (int i = 0; i != _nbHuman; ++i)
    _map->newPlayer(i + 1);
  for (int i = 0; i != _nbIA; ++i)
    _map->newPlayer(0);
  return (true);
}
 
bool					GameEngine::update()
{
  _screen.updateInputs(&_events);
  if (_events.size() != 0 && _events[0].input == EXIT)
    return (false);
  for (size_t i = 0; _events.size() != i; i++)
    {
      if (_funcptrBind.count(_events[i].input))
      	(this->*_funcptrBind[_events[i].input])(_events[i].pid, _events[i].input);
    }
  this->updateIA();
  _map->update(_screen.getTime());
  if (!_map->isTherePlayers())
    return (false);
  return (true);
}

void					GameEngine::updateIA()
{
  std::vector<Player*>			*playerSet;
  t_input				input;

  playerSet = _map->getPlayerSet();
  for (size_t i = 0; i != playerSet->size(); i++)
    {
      if ( (*playerSet)[i]->getHumanId() == 0 ) 
  	{
  	  input = _iaManager->doAction(*_map, (*playerSet)[i]);
	  if (_funcptrBind.count(input))
	    (this->*_funcptrBind[input])((*playerSet)[i]->getPlayerId(), input);
  	}
    } 
}

void					GameEngine::draw()
{
  _screen.updateScreen(_map);
}

bool					GameEngine::gameOver()
{
  _map->gameOver();
  _screen.updateScreen(_map);
  _screen.gameOver();
  sleep(2);
  return (true);
}

void					GameEngine::moveCam(int pid, t_input input)
{
  (void)pid;
  (void)input;
  _screen.moveCam(input);
}

void					GameEngine::lockCam(int pid, t_input input)
{
  (void)pid;
  (void)input;
  _screen.lockCam();
}

void					GameEngine::movePlayer(int pid, t_input input)
{
  Player				*tmp;
  std::vector<std::pair<int, int> >	newPos;
  bool					canMove = true;

  tmp = _map->getPlayerById(pid);
  if (tmp != NULL)
    {
      newPos = tmp->getNewPos(input);
      for (unsigned int i = 0; i != newPos.size(); ++i)
	{
	  if (_map->getItemAtPos(newPos[i])->what() == WALL
	      || (_map->getItemAtPos(newPos[i])->what() == BONUS
		  && !reinterpret_cast<Bonus*>(_map->getItemAtPos(newPos[i]))->getExploded()))
	    canMove = false;
	}
      if (canMove == true)
	{
	  tmp->move(input, _screen.getTime());
	  for (unsigned int i = 0; i != newPos.size(); ++i)
	    if (_map->getItemAtPos(newPos[i])->what() == BONUS
		&& reinterpret_cast<Bonus*>(_map->getItemAtPos(newPos[i]))->getExploded())
	      {
		tmp->takeBonus(reinterpret_cast<Bonus*>(_map->getItemAtPos(newPos[i]))->getBonus());
		_map->delItemAtPos(newPos[i]);
		break;
	      }
	}
    }
}

void					GameEngine::placeBomb(int pid, t_input input)
{
  (void)input;
  Player *tmp = _map->getPlayerById(pid);
  if (tmp != NULL)
    {
      std::pair<int, int> pos = tmp->getPos();
      if (_map->getItemAtPos(pos)->what() != BOMB)
	_map->newBomb(tmp, pos);
    }
}
