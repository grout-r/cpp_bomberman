#ifndef GAMEENGINE

# define GAMEENGINE

# include <Game.hh>
# include <SdlContext.hh>
# include <BasicShader.hh>

# include <iostream>

# include "Screen.hh"
# include "AObject.hh"

class GameEngine;

typedef void (GameEngine::*inputFuncptr)(int player);

class						GameEngine : public gdl::Game 
{
private:
  
private:
  Screen					_screen;
  std::vector<t_event>				_events;
  std::vector<AObject*>				_map;
  std::map<t_input, inputFuncptr>		_funcptrBind;

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
