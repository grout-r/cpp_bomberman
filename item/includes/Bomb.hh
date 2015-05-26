#ifndef BOMB_HH_
# define BOMB_HH_

#include <time.h>
#include <unistd.h>

#include "AObject.hh"
#include "Player.hh"

class Player;

// typedef enum e_color 
//   {
//     ORANGE,
//     BLUE
//   }	     t_color ;

class Bomb :	public AObject
{
private:
  int			player_id;
  std::pair<int, int>	pos;
  int			bomb_power;
  //j'ai mis un int sinon ca compile pas ca m'a soulé
  int			color;
  time_t		timer;

private:
  gdl::Model		_bombModel;
  

public:
  Bomb(Player  *player, std::pair<int, int> pos);
  ~Bomb();

  bool			explose();
public:
  int			getBombPower() const;
  bool			initialize();
  void			update();
  void			draw(gdl::BasicShader&, gdl::Clock &);
};

#endif /* !BOMB_HH */
