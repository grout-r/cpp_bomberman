//
// IA.hh for IA_bomber in /home/gazzol_j/rendu/cpp_bomberman/IA
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue May 12 09:55:35 2015 julien gazzola
// Last update Thu May 28 14:10:48 2015 julien gazzola
//

#ifndef IA_HH_
# define IA_HH_

# include "Definition.hh"

class IA
{
public:
  IA();
  ~IA();

public:
  e_input	doAction(Map &map, Player *player);

private:
  e_input	FindBonus(Map &map, Player *player);
  int     	CheckBomb(Map &map, Player *player);
  e_input     	CheckFreeCase(Map &map, Player *player);
  int     	CheckBonus(Map &map, Player *player);
  e_input     	CheckPlayer(Map &map, Player *player);
  e_input	Move(Map &map, Player *player);
  //  std::vector<std::pair<AObject*, e_smell> > CreateTable(Map &map, Player *player);
};

#endif // !IA_HH_
