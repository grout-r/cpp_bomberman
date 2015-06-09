
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
  t_input		Move(std::vector<int> &tab, Map &map, Player *player);
  int			CheckBomb(Map &map, Player *player);
  std::vector<int> 	CreateTable(Map &map, Player *player);

  // Check.cpp
private:
  int			checkUp(Map &map, Player *player);
  int			checkBottom(Map &map, Player *player);
  int			checkLeft(Map &map, Player *player);
  int			checkRight(Map &map, Player *player);

  // PosVectorTab.cpp
private:
  void			CreateVectorPos(std::vector<int> const &tab);
  t_input      		checkPos(int low, Map &map, Player *player, std::vector<int> const &tab);

  // Random.cpp
private:
  bool			dangerDown(std::vector<int> const &tab, int low);
  bool			dangerUp(std::vector<int> const &tab, int low);
  bool			dangerLeft(std::vector<int> const &tab, int low);
  bool			dangerRight(std::vector<int> const &tab, int low);
};

#endif // !IA_HH_
