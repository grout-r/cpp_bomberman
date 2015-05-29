
#include "Bomb.hh"

Bomb::Bomb(Player *player, std::pair<int, int> pos)
{
  _floor = new Void(pos);
  _floor->initialize();
  _scale = glm::vec3(0.3, 0.3, 0.3);
  std::cout << "bomb posée en :" << std::endl;
  _position = glm::vec3(pos.first * 100, 0, pos.second * 100);
  this->player_id = player->getPlayerId();
  this->pos = player->getPos();
  this->bomb_power = player->getBombPower();
  this->color = player->getBombColor();
  this->_smell = -10;
  time(&(this->timer));
  std::cout << this->pos.first << ";" << this->pos.second << std::endl;
  _what = BOMB;
}

Bomb::~Bomb()
{
  std::cout << "BOOOM!!!!!!!!!!!!!" << std::endl;
}

bool		Bomb::explose()
{
  double	diff;
  time_t	now;

  time(&now);
  if ((diff = difftime(now, (this->timer) + 3)) == 0)
    {
      std::cout << "bomb explose" << std::endl;
      return (true);
    }
  return (false);
}

bool		Bomb::initialize()
{
  try
    {
      if (!_bombModel.load("./assets/bomb.fbx"))
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
  _floor->draw(shader, clock);
}

void		Bomb::update()
{
}

int		Bomb::getBombPower() const{
  return (this->bomb_power);
}
