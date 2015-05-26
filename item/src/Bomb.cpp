
#include "Bomb.hh"

Bomb::Bomb(Player *player, std::pair<int, int> pos)
{
  std::cout << "bomb posée en :" << std::endl;
  _position = glm::vec3(pos.first * 100, 0, pos.second * 100);
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

bool		Bomb::initialize()
{
  try
    {
      if (!_bombModel.load("./assets/bomb.obj"))
	throw (Error("cannot load assets for bomb model"));
      return (true);
    }
  catch (Error e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (false);
}

void		Bomb::draw(gdl::BasicShader& shader, gdl::Clock & clock)
{
  _bombModel.draw(shader, calcTransformation(), clock.getElapsed());
}

void		Bomb::update()
{
}
