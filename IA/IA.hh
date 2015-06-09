
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

public:
  IA();
  ~IA();

public:
  t_input		doAction(Map &map, Player *player);

private:
  t_input		Move(std::vector<int> tab, Map &map, Player *player);
  int			CheckBomb(Map &map, Player *player);
  int			checkUp(Map &map, Player *player);
  int			checkBottom(Map &map, Player *player);
  int			checkLeft(Map &map, Player *player);
  int			checkRight(Map &map, Player *player);
  std::vector<int> 	CreateTable(Map &map, Player *player);
  void			CreateVectorPos();
  t_input      		checkPos(std::vector<int>::iterator ite, Map &map, Player *player, std::vector<int> tab);
};

#endif // !IA_HH_
