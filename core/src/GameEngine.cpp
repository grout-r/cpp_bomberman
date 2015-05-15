#include "GameEngine.hh"

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
  return (true);
}

bool					GameEngine::update()
{
  return (true);
}

void					GameEngine::draw()
{
  
}

bool					GameEngine::gameOver()
{
  return (true);
}
