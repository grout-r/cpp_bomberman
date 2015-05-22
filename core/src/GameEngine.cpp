#include "GameEngine.hh"

GameEngine::GameEngine()
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
  _map = new Map;
}

GameEngine::~GameEngine()
{
}

bool					GameEngine::initialize()
{
  if (_screen.init() == false)
    return (false);
  _map->init();
  _map->newPlayer(1);
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
   return (true);
}

void					GameEngine::draw()
{
  _screen.updateScreen(_map);
}

bool					GameEngine::gameOver()
{
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
  std::pair<int, int>			newPos;

  tmp = _map->getHumanById(pid);
  if (tmp != NULL)
    {
      newPos = tmp->getNewPos(input);
      if (_map->getItemAtPos(newPos)->what() == VOID ||
	  _map->getItemAtPos(newPos)->what() == PLAYER )
	tmp->move(input);
    }
}
