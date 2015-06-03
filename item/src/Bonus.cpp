//
// Bonus.cpp for bomberman in /home/verove_j/rendu/cpp_bomberman/core/src
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Tue May 12 13:18:59 2015 Jordan Verove
// Last update Mon Jun  1 13:56:06 2015 Jordan Verove
//

#include "AObject.hh"
#include "Bonus.hh"
#include <ctime>

Bonus::Bonus()
{
  int		nbr_rand;

  nbr_rand = std::rand() % 7;
  std::srand(std::time(0));
  this->_smell = 10;
  _what = BONUS;
  _bonus = (t_bonus)nbr_rand;
  _is_exploded = false;
}

Bonus::~Bonus()
{
  
}

bool		Bonus::getExploded() const
{
  return (this->_is_exploded);
}

void		Bonus::setExploded(bool exploded)
{
  this->_is_exploded = exploded;
}
