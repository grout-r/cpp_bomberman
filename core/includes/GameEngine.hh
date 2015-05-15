#ifndef GAMEENGINE

# define GAMEENGINE

# include <Game.hh>
# include <SdlContext.hh>
# include <BasicShader.hh>

# include <iostream>

# include "Screen.hh"

class						GameEngine : public gdl::Game 
{
private:
  
private:
  Screen					_screen;

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
