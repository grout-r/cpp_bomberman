#include	"GameEngine.hh"
#include	"Wall.hh"
#include	"Map.hh"
	 
int			main()
{
  GameEngine		engine;

  if (engine.initialize() == false)
    return (-1);
  while (engine.update() != false)
    {
      engine.draw();
    }
  engine.gameOver();
  return  (0);
}
