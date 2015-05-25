#ifndef MAP_HH_
# define MAP_HH_

# include <utility>
#include "glm/ext.hpp"

# include "AObject.hh"
# include "Bomb.hh"
# include "Wall.hh"
# include "Player.hh"
# include "Void.hh"

class Bomb;
class Player;

class Map
{
private:
  std::vector<std::vector<AObject*> >		_map;
  std::vector<Bomb*>				_bomb;
  std::vector<Player*>				_player;
  std::vector<Wall*>				_wall;
  std::vector<Void*>				_void;
  std::pair<int, int>				_size;

public:
  Map();
  ~Map();

public:
  void						init();
  void						newPlayer(int human);
  void						draw(gdl::BasicShader &shader, 
							  gdl::Clock clock);
  Player					*getHumanById(int id);
  std::pair<int, int>				getSize();
  AObject					*getItemAtPos(std::pair<int, int>);
  void						newBomb(Player *, std::pair<int, int> pos);
};

#endif /* !MAP_HH_ */
