#ifndef MENU_HH_
# define MENU_HH_

#include <Game.hh>
#include <SdlContext.hh>
#include <BasicShader.hh>

class Menu : public gdl::Game
{
private:

public:
  Menu();
  ~Menu();
public:
  virtual bool	initialize();
  virtual bool	update();
  virtual void	draw();
};

#endif //MENU_HH_
