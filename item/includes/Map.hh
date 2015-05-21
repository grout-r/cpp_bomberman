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
  int						x_size;
  int						y_size;

public:
  Map();
  ~Map();

public:
  void						init();
  void						newPlayer(int human);
  void						draw(gdl::BasicShader &shader, 
							  gdl::Clock clock);
  Player					*getHumanById(int id);
};

#endif /* !MAP_HH_ */
