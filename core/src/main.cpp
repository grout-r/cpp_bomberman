#include	"Param.hh"
#include	"GameEngine.hh"
#include	"Wall.hh"
#include	"Map.hh"
	 
int			main(int ac, char **av)
{
  Param			params(av, ac);
  GameEngine		engine(params);

  if (engine.initialize() == false)
    return (-1);
  while (engine.update() != false)
    {
      engine.draw();
    }
  engine.gameOver();
  return  (0);
}
