#include "Player.hh"

Player::Player(std::pair<int, int> pos, int humanId) :
  bomb_nb(1), bomb_power(1), p_speed(1), bomb_color(ORANGE)
{
  static int	id = 0;
  
  this->_smell = 4;
  _position = glm::vec3(pos.first * 100, 0 , pos.second * 100);
  this->humanId = humanId;
  this->player_id = id;
  id += 1;
  _movePlayerBind[MOVE_RIGHT] = glm::vec3(10, 0, 0);
  _movePlayerBind[MOVE_LEFT] = glm::vec3(-10, 0, 0);
  _movePlayerBind[MOVE_UP] = glm::vec3(0, 0, -10);
  _movePlayerBind[MOVE_DOWN] = glm::vec3(0, 0, 10);
  _rotatePlayerBind[MOVE_RIGHT] = glm::vec3(0, 90, 0);
  _rotatePlayerBind[MOVE_LEFT] = glm::vec3(0, -90, 0);
  _rotatePlayerBind[MOVE_UP] = glm::vec3(0, 180, 0);
  _rotatePlayerBind[MOVE_DOWN] = glm::vec3(0, 0, 0);
  _frameCounter = 0;
  _what = PLAYER;
  _scale = glm::vec3(0.2, 0.2, 0.2);
}

Player::~Player()
{
  std::cout << "Player " << this->player_id << " is dead" << std::endl;
}

void		Player::putBomb()
{

}

int	        Player::getHumanId()
{
  return (this->humanId);
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

bool		Player::initialize()
{
  _playerModel = AssetsController::getPlayerModel();
  return (true);
}

void		Player::draw(gdl::BasicShader& shader, gdl::Clock &clock)
{
  if (_frameCounter != 0)
    {
      if (_frameCounter == _playerModel->getAnimationFrameNumber(0))
	_frameCounter = 0;
      else
	_frameCounter++;
    }
  _playerModel->draw(shader, calcTransformation(), clock.getElapsed());
}

void		Player::update()
{
}

std::pair<int, int>	Player::getNewPos(t_input input)
{
  glm::vec3		newPos = _position + _movePlayerBind[input];
  
  return (std::make_pair(newPos.x / 100, newPos.z / 100));
}

void		Player::move(t_input input)
{
  if (_frameCounter == 0)
    {
      _playerModel->setCurrentAnim(0, false);
      _frameCounter++;
    }
  _position += _movePlayerBind[input];
  _rotation = _rotatePlayerBind[input];
}
