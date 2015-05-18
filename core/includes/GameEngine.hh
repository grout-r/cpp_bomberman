#ifndef GAMEENGINE

# define GAMEENGINE

# include <Game.hh>
# include <SdlContext.hh>
# include <BasicShader.hh>

# include <iostream>

# include "Screen.hh"
# include "AObject.hh"

class						GameEngine : public gdl::Game 
{
private:
  
private:
  Screen					_screen;
  std::vector<t_event>				_events;
  std::vector<AObject*>				_map;	
public:
  GameEngine();
  ~GameEngine();
  
public:
  bool						initialize();
  bool						update();
  void						draw();
  bool						gameOver();
};

# endif
