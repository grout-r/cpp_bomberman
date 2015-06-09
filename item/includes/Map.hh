#ifndef MAP_HH_
# define MAP_HH_

# include <utility>
# include "glm/ext.hpp"

# include "AObject.hh"
# include "Bomb.hh"
# include "Wall.hh"
# include "Player.hh"
# include "Void.hh"
# include "Fire.hh"
# include "AssetsController.hh"

class Bomb;
class Player;

class Map
{
private:
  std::vector<std::vector<AObject*> >		_map;
  std::vector<std::vector<int> >		_int_map;
  std::vector<Bomb*>				_bomb;
  std::vector<Player*>				_player;
  std::vector<Fire*>				_fire;
  std::pair<int, int>				_size;

  bool						up(std::pair<int, int> pos);
  bool						down(std::pair<int, int> pos);
  bool						right(std::pair<int, int> pos);
  bool						left(std::pair<int, int> pos);
  void						fillMap();
  bool						digMap(std::pair<int, int> pos);
  std::vector<bool>				check_hut(std::pair<int, int> hut);
  void						initDirection(bool (Map::*function_ptr[])(std::pair<int, int>));
  void						removeWalls();

public:
  Map (std::pair<int, int> = std::make_pair(20, 20));
  ~Map();
  void						genRandMap();

private:
  void						fireSomeHut(std::pair<int, int>);

public:
  void						init();
  void						newPlayer(int human);
  void						draw(gdl::BasicShader &shader, 
							  gdl::Clock &clock);
  Player					*getHumanById(int id);
  std::pair<int, int>				getSize();
  AObject					*getItemAtPos(std::pair<int, int>);
  void						newBomb(Player *, std::pair<int, int> pos);
  void						update(double);
  std::vector<Player*>*				getPlayerSet();
  bool						isTherePlayers();
  void						gameOver();
};

#endif /* !MAP_HH_ */
