#include "Bomb.hh"

#include <unistd.h>

Bomb::Bomb(Player *player)
{
  std::cout << "bomb posée en :" << std::endl;
  this->player_id = player->getPlayerId();
  this->pos = player->getPos();
  this->bomb_power = player->getBombPower();
  this->color = player->getBombColor();
  time(&(this->timer));
  std::cout << this->pos.first << ";" << this->pos.second << std::endl;
  _what = BOMB;
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

  sleep(3);
  time(&now);
  if ((diff = difftime(now, (this->timer) + 3)) == 0)
    return (true);
  return (false);
}

bool		Bomb::initalize()
{
  return (true);
}

void		Bomb::update()
{
}
