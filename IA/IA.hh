//
// IA.hh for IA_bomber in /home/gazzol_j/rendu/cpp_bomberman/IA
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue May 12 09:55:35 2015 julien gazzola
// Last update Tue May 26 14:02:52 2015 julien gazzola
//

#ifndef IA_HH_
# define IA_HH_

enum e_action
  {
    GO_NORTH,
    GO_SOUTH,
    GO_EAST,
    GO_WEST,
    PUT_BOMB,
    STAY
  };

class IA
{
public:
  IA();
  ~IA();

public:
  e_action	DoAction(Map &map, Player *player);
  e_action	FindBonus(Map &map, Player *player);
  int     	CheckBomb(Map &map, Player *player);
  e_action     	CheckFreeCase(Map &map, Player *player);
  int     	CheckBonus(Map &map, Player *player);
  e_action     	CheckPlayer(Map &map, Player *player);
  e_action	Move(Map &map, Player *player);
};

#endif // !IA_HH_
