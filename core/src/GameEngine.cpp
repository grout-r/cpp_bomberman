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
}

GameEngine::~GameEngine()
{
}

bool					GameEngine::initialize()
{
  if (_screen.init() == false)
    return (false);
  newPlayer();
  Wall *a = new Wall;
  a->initialize();
  _map.push_back(a);
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
  _screen.updateScreen(_map);
  return (true);
}

void					GameEngine::draw()
{
  
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

void					GameEngine::movePlayer(int pid, t_input input)
{
  for (size_t i = 0; i != _playerPool.size(); i++)
    {
      if (_playerPool[i]->getHumanId()== pid)
	{
	  _playerPool[i]->move(input);
	  break;
	}
    }
}

void					GameEngine::newPlayer()
{
  Player *Michel = new Player(0, 0, 1);
  Michel->initialize();
  _map.push_back(Michel);
  _playerPool.push_back(Michel);
}
