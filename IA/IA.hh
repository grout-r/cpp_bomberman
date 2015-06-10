
#ifndef IA_HH_
# define IA_HH_

# include <vector>
# include "Definition.hh"
# include "Map.hh"

class IA
{
private:
  std::vector<int>	up;
  std::vector<int>	down;
  std::vector<int>	right;
  std::vector<int>	left;

  // IA.cpp
public:
  IA();
  ~IA();

public:
  t_input		doAction(Map &map, Player *player);

private:
  t_input		move(std::vector<int> &tab, Map &map, Player *player);
  int			checkBomb(Map &map, Player *player);
  std::vector<int> 	createTable(Map &map, Player *player);

  // Check.cpp
private:
  int			checkUp(Map &map, Player *player);
  int			checkBottom(Map &map, Player *player);
  int			checkLeft(Map &map, Player *player);
  int			checkRight(Map &map, Player *player);

  // PosVectorTab.cpp
private:
  void			createVectorPos(std::vector<int> const &tab);
  t_input      		checkPos(int high, Map &map, Player *player, std::vector<int> const &tab);

  // Move.cpp
private:
  bool			moveDown(std::vector<int> const &tab, int high);
  bool			moveUp(std::vector<int> const &tab, int high);
  bool			moveLeft(std::vector<int> const &tab, int high);
  bool			moveRight(std::vector<int> const &tab, int high);
  t_input		saveMyLife();
};

#endif // !IA_HH_
