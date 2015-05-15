//
// Bomb.cpp for bomberman in /home/verove_j/rendu/cpp_bomberman/core/src
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Tue May 12 13:17:09 2015 Jordan Verove
// Last update Fri May 15 12:16:25 2015 Jordan Verove
//

#include "Bomb.hh"

#include <unistd.h>

Bomb::Bomb(Player * const player)
{
  std::cout << "bomb posée en :" << std::endl;
  this->player_id = player->getPlayerId();
  this->pos_x = player->getPosX();
  this->pos_y = player->getPosY();
  this->bomb_power = player->getBombPower();
  this->color = player->getBombColor();
  std::cout << this->pos_x << ";" << this->pos_y << std::endl;
}

Bomb::~Bomb()
{
  if (this->explose() == true)
    std::cout << "BOOOM!!!!!!!!!!!!!" << std::endl;
}

bool		Bomb::explose()
{
  double	diff;
  time_t	now;

  time(&now);
  sleep(2);
  if ((diff = difftime(now, (this->timer) + 2)) == 0)
    return (true);
  return (false);
}
