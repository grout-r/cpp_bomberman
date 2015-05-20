#ifndef GAMEENGINE

# define GAMEENGINE

# include <Game.hh>
# include <SdlContext.hh>
# include <BasicShader.hh>

# include <iostream>

# include "Screen.hh"
# include "AObject.hh"
# include "Wall.hh"
# include "Player.hh"

class GameEngine;

typedef void (GameEngine::*inputFuncptr)(int player, t_input input);

class						GameEngine : public gdl::Game 
{
private:
  
private:
  Screen					_screen;
  std::vector<t_event>				_events;
  std::vector<AObject*>				_map;
  std::map<t_input, inputFuncptr>		_funcptrBind;
  std::vector<Player*>				_playerPool;
public:
  GameEngine();
  ~GameEngine();
  
public:
  bool						initialize();
  bool						update();
  void						draw();
  bool						gameOver();
  
public:
  void						newPlayer();

public:
  void						moveCam(int, t_input);
  void						movePlayer(int, t_input);
};

# endif
