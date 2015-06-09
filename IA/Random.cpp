
#include "IA.hh"

bool				IA::dangerDown(std::vector<int> const &tab, int low){
  std::vector<int>::iterator    it;

  for (it = this->down.begin(); it != down.end(); ++it)
    if (low == *it)
      if (tab[7] >= 0)
        return (true);
  return (false);
}

bool				IA::dangerUp(std::vector<int> const &tab, int low){
  std::vector<int>::iterator    it;

  for (it = this->up.begin(); it != up.end(); ++it)
    if (low == *it)
      if (tab[17] >= 0)
        return (true);
  return (false);
}

bool				IA::dangerLeft(std::vector<int> const &tab, int low){
  std::vector<int>::iterator    it;

  for (it = this->left.begin(); it != left.end(); ++it)
    if (low == *it)
      if (tab[13] >= 0)
        return (true);
  return (false);
}

bool				IA::dangerRight(std::vector<int> const &tab, int low){
  std::vector<int>::iterator    it;

  for (it = this->right.begin(); it != right.end(); ++it)
    if (low == *it)
      if (tab[11] >= 0)
        return (true);
  return (false);
}
