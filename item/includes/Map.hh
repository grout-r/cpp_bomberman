#ifndef MAP_HH_
# define MAP_HH_

#include "AObject.hh"
#include "Bomb.hh"
#include "Wall.hh"
#include "Player.hh"
#include "Void.hh"

class Map
{
private:
  std::vector<std::vector<AObject*> >		_map;
  std::vector<Bomb*>				_bomb;
  std::vector<Player*>				_player;
  std::vector<Wall*>				_wall;
  std::vector<Void*>				_void;
  int						x_size;
  int						y_size;
public:
  Map();
  ~Map();
  void						initMap();
};

#endif /* !MAP_HH_ */
