//
// IA.hh for IA_bomber in /home/gazzol_j/rendu/cpp_bomberman/IA
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue May 12 09:55:35 2015 julien gazzola
// Last update Thu May 28 14:17:41 2015 grout_r
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
  t_input	doAction(Map &map, Player *player);

private:
  t_input	FindBonus(Map &map, Player *player);
  int     	CheckBomb(Map &map, Player *player);
  t_input     	CheckFreeCase(Map &map, Player *player);
  int     	CheckBonus(Map &map, Player *player);
  t_input     	CheckPlayer(Map &map, Player *player);
  t_input	Move(Map &map, Player *player);
  //  std::vector<std::pair<AObject*, e_smell> > CreateTable(Map &map, Player *player);
};

#endif // !IA_HH_
