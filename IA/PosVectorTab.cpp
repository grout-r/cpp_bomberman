#include "IA.hh"

t_input				IA::checkPos(std::vector<int>::iterator ite, Map &map, Player *player, std::vector<int> tab){
  std::vector<int>::iterator	it;
  (void) player;
  (void) map;

  for (it = this->down.begin(); it != down.end(); ++it)
    if (ite == it)
      if (tab[17] >= 0)
	return (MOVE_DOWN);
  for (it = this->up.begin(); it != up.end(); ++it)
    if (ite == it)
      if (tab[7] >=0)
	return (MOVE_UP);
  for (it = this->left.begin(); it != left.end(); ++it)
    if (ite == it)
      if (tab[11] >= 0)
	return (MOVE_LEFT);
  for (it = this->right.begin(); it != right.end(); ++it)
    if (ite == it)
      if (tab[13] >= 0)
	return (MOVE_RIGHT);
  return (MOVE_RIGHT);
}

void		IA::CreateVectorPos(){
  this->up.clear();
  this->down.clear();
  this->left.clear();
  this->right.clear();
  for (int i = 0; i != 10; ++i)
    this->up.push_back(i);
    for (int i = 15; i != 25; ++i)
      this->down.push_back(i);
  for (int i = 0; i <= 22; ++i){
    for (int inc = 0 ; inc < 2 ; ++inc){
      this->left.push_back(i);
      ++i;
    }
    i += 2;
  }
  for (int i = 3; i <= 25; ++i){
    for (int inc = 0 ; inc < 2; ++inc){
      this->right.push_back(i);
      ++i;
    }
    i += 2;
  }
}
