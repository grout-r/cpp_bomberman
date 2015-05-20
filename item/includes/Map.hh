#ifndef MAP_HH_
# define MAP_HH_

#include "AObject.hh"

class Map
{
private:
  std::vector<std::vector<AObject*> >		_map;
  std::vector<Bomb*>				_bomb;
  std::vector<Player*>				_player;
  std::vector<Wall*>				_wall;
  std::vector<Void*>				_void;

public:
  Map();
  ~Map();
}

#endif /* !MAP_HH_ */
