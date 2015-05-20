#include "GameEngine.hh"
#include "Wall.hh"
#include "Player.hh"

GameEngine::GameEngine()
{
  
}

GameEngine::~GameEngine()
{
}

bool					GameEngine::initialize()
{
  if (_screen.init() == false)
    return (false);  
  Player *a = new Player(2, 2);
  a->initialize();
  _map.push_back(a);
  return (true);
}

bool					GameEngine::update()
{
  _screen.updateInputs(&_events);
  if (_events.size() != 0 && _events[0].input == EXIT)
    return (false);
  // std::cout << _events.size() << std::endl;
  for (size_t i = 0; _events.size() != i; i++)
    {
      
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
