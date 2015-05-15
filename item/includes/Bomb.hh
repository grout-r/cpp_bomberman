#ifndef BOMB_HH_
# define BOMB_HH_

#include <time.h>

#include "AObject.hh"
#include "Player.hh"

class Bomb :	public AObject
{
private:
  int			player_id;
  std::pair<int, int>	pos;
  int			bomb_power;
  t_color		color;
  time_t		timer;

public:
  Bomb(Player * const player);
  ~Bomb();

  std::pair<int, int>	getPos() const;
  bool			explose();
};

#endif /* !BOMB_HH */
