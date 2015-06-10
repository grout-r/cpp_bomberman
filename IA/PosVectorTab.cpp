# include "IA.hh"

t_input	      	IA::checkPos(int high, Map &map, Player *player, std::vector<int> const &tab){
  (void) player;
  (void) map;
  int  		i = 0;
  bool		(IA::*funcptr[4])(std::vector<int> const &, int);

  funcptr[0] = &IA::moveRight;
  funcptr[1] = &IA::moveLeft;
  funcptr[2] = &IA::moveUp;
  funcptr[3] = &IA::moveDown;
  for (i = 0; i != 4; ++i){
    if ((this->*funcptr[i])(tab, high) == true){
      //      std::cout << "CA RETURN TRUE     " << i << std::endl;
      return ((t_input) i);
    }
  }
  return (PLACE_BOMB);
}

void		IA::createVectorPos(std::vector<int> const &tab){
  this->up.clear();
  this->down.clear();
  this->left.clear();
  this->right.clear();
  for (int i = 0; i != 10; ++i)
    this->up.push_back(tab[i]);
  for (int i = 15; i != 25; ++i)
    this->down.push_back(tab[i]);
  for (int i = 0; i <= 22; ++i){
    for (int inc = 0 ; inc < 2 ; ++inc){
      this->left.push_back(tab[i]);
      ++i;
    }
    i += 2;
  }
  for (int i = 3; i <= 25; ++i){
    for (int inc = 0 ; inc < 2; ++inc){
      this->right.push_back(tab[i]);
      ++i;
    }
    i += 2;
  }
}
