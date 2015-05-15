//
// Player.cpp for bomberman in /home/verove_j/rendu/cpp_bomberman/core/src
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Tue May 12 13:14:59 2015 Jordan Verove
// Last update Fri May 15 12:43:29 2015 Jordan Verove
//

#include "Player.hh"
#include "Bomb.hh"

Player::Player() :
  bomb_nb(1), bomb_power(1), p_speed(1), bomb_color(ORANGE)
{
  static int	id = 0;

  this->player_id = id;
  this->pos = std::make_pair(10, 2);
  //putOnMap(map);
  id += 1;
}

Player::~Player()
{
  std::cout << "Player " << this->player_id << " is dead" << std::endl;
}

/*void		Player::putOnMap(Map &map)
  {
  std::cout << this->player_id << std::endl;
}*/

void		Player::putBomb()
{
  Bomb		*bomb;

  bomb = new Bomb(this);
  (void) bomb;
  delete bomb;
}

std::pair<int, int>		Player::getPos() const
{
  return (this->pos);
}

void		Player::setPos(std::pair<int, int> pos)
{
  //  this->pos = std::make_pair(pos.first, pos.second);
  this->pos = pos;
}

int		Player::getBombNb() const
{
  return (this->bomb_nb);
}

void		Player::setBombNb(int nb)
{
  this->bomb_nb = nb;
}

int		Player::getBombPower() const
{
  return (this->bomb_power);
}

void		Player::setBombPower(int power)
{
  this->bomb_power = power;
}

int		Player::getPSpeed() const
{
  return (this->p_speed);
}

void		Player::setPSpeed(int speed)
{
  this->p_speed = speed;
}

t_where		Player::getOrientation() const
{
  return (this->orientation);
}

void		Player::setOrientation(t_where direction)
{
  this->orientation = direction;
}

int		Player::getPlayerId() const
{
  return (this->player_id);
}

t_color		Player::getBombColor() const
{
  return (this->bomb_color);
}

void		Player::setBombColor(t_color color)
{
  this->bomb_color = color;
}

int		main()
{
  Player	j1;
  Player	j2;
  Player	j3;
  
  //  std::cout << j1.getBombNb() << std::endl;
  j1.putBomb();
  return (0);
}
