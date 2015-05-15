//
// Bomb.cpp for bomberman in /home/verove_j/rendu/cpp_bomberman/core/src
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Tue May 12 13:17:09 2015 Jordan Verove
// Last update Fri May 15 11:17:21 2015 Jordan Verove
//

#include "Bomb.hh"

#include <unistd.h>

Bomb::Bomb(Player * const player)
{
  time_t	sec_time;
  double	diff;

  std::cout << "bomb posée en :" << std::endl;
  this->player_id = player->getPlayerId();
  this->pos_x = player->getPosX();
  this->pos_y = player->getPosY();
  this->bomb_power = player->getBombPower();
  this->color = player->getBombColor();
  time(&sec_time);
  time(&(this->timer));
  std::cout << this->pos_x << ";" << this->pos_y << std::endl;
  diff = difftime(this->timer, sec_time);
  std::cout << diff << std::endl;
}

Bomb::~Bomb()
{
  std::cout << "BOOOM!!!!!!!!!!!!!" << std::endl;
}

bool		Bomb::explose()
{
  
}
