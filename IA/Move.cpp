
#include "IA.hh"

bool				IA::moveDown(std::vector<int> const &tab, int high){
  std::vector<int>::iterator    it;

  for (it = this->down.begin(); it != down.end(); ++it)
    if (high == *it)
      if (tab[17] == 0){
	//	std::cout << "CA DESCEND   ----> " << tab[17]  << std::endl;
        return (true);
      }
  return (false);
}

bool				IA::moveUp(std::vector<int> const &tab, int high){
  std::vector<int>::iterator    it;

  for (it = this->up.begin(); it != up.end(); ++it)
    if (high == *it)
      if (tab[7] == 0){
	//	std::cout << "CA MONTE   ----> " << tab[7] << std::endl;
        return (true);
      }
  return (false);
}

bool				IA::moveLeft(std::vector<int> const &tab, int high){
  std::vector<int>::iterator    it;

  for (it = this->left.begin(); it != left.end(); ++it)
    if (high == *it)
      if (tab[11] == 0){
	//	std::cout << "CA MOVE A GAUCHE   ----> " << tab[11] << std::endl;
        return (true);
      }
  return (false);
}

bool				IA::moveRight(std::vector<int> const &tab, int high){
  std::vector<int>::iterator    it;

  for (it = this->right.begin(); it != right.end(); ++it)
    if (high == *it)
      if (tab[13] == 0){
	//	std::cout << "CA MOVE A DROITE   ----> " << tab[13]  << std::endl;
        return (true);
      }
  return (false);
}

t_input		IA::saveMyLife(){
  return (MOVE_RIGHT);
}
