#ifndef BOMB_HH_
# define BOMB_HH_

#include <time.h>

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

public:
  Bomb(Player  *player);
  ~Bomb();

  std::pair<int, int>	getPos() const;
  bool			explose();
public:
  bool			initalize();
  void			update();
};

#endif /* !BOMB_HH */
