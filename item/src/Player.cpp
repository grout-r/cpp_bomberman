#include "Player.hh"

Player::Player(std::pair<int, int> pos, int humanId) :
  bomb_nbMax(1), bomb_nbCur(1), bomb_power(1), p_speed(25), bomb_color(ORANGE), _alive(true)
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
  _fptrBonus[SPEED_MORE] = &Player::speedMore;
  _fptrBonus[BOMB_MORE] = &Player::bombMore;
  _fptrBonus[POWER_MORE] = &Player::powerMore;
  _fptrBonus[SPEED_LESS] = &Player::speedLess;
  _fptrBonus[BOMB_LESS] = &Player::bombLess;
  _fptrBonus[POWER_LESS] = &Player::powerLess;
  _frameCounter = 0;
  _what = PLAYER;
  _scale = glm::vec3(0.2, 0.2, 0.2);
  _indicator = new PlayerIndicator(_position, humanId);
  _indicator->initialize();
}

Player::~Player()
{
  delete _indicator;
}

int	        Player::getHumanId() const
{
  return (this->humanId);
}

int		Player::getBombPower() const
{
  return (this->bomb_power);
}

void		Player::setBombPower(int power)
{
  this->bomb_power = power;
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
  _indicator->draw(shader, clock);
}

void		Player::update()
{
  
}

std::vector<std::pair<int, int>	>	Player::getNewPos(t_input input)
{
  std::vector<std::pair<int, int> >	pos;
  glm::vec3				newPos = _position + _movePlayerBind[input];

  pos.push_back(std::make_pair((newPos.x + 20) / 100, (newPos.z) / 100));
  pos.push_back(std::make_pair((newPos.x + 70) / 100, (newPos.z) / 100));
  pos.push_back(std::make_pair((newPos.x + 20) / 100, (newPos.z + 40) / 100));
  pos.push_back(std::make_pair((newPos.x + 70) / 100, (newPos.z + 40) / 100));

  return (pos);
}

void		Player::move(t_input input, double elapsedTime)
{  
  if (_frameCounter == 0)
    {
      _playerModel->setCurrentAnim(0, false);
      _frameCounter++;
    }
  _position += _movePlayerBind[input] * (p_speed * static_cast<float>(elapsedTime));
  _rotation = _rotatePlayerBind[input];
  _indicator->updatePosition(_position);
}

void	       Player::die()
{
  _alive = !_alive;
}

bool	      Player::isAlive() const
{
  return (_alive);
}

bool		Player::decBomb()
{
  if (bomb_nbCur <= 0)
    {
      bomb_nbCur = 0;
      return false;
    }
  --bomb_nbCur;
  return true;
}

void		Player::addBomb()
{
  ++bomb_nbCur;
  if (bomb_nbCur >= bomb_nbMax)
    bomb_nbCur = bomb_nbMax;
}

void					Player::speedMore()
{
  p_speed += 5;
  if (p_speed >= 50)
    p_speed = 50;
}

void					Player::bombMore()
{
  bomb_nbMax += 1;
  bomb_nbCur += 1;
  if (bomb_nbMax >= 6)
    bomb_nbMax = 6;
}

void					Player::powerMore()
{
  bomb_power += 1;
  if (bomb_power >= 10)
    bomb_power = 10;
}

void					Player::speedLess()
{
  p_speed -= 5;
  if (p_speed <= 10)
    p_speed = 10;
}

void					Player::bombLess()
{
  bomb_nbMax -= 1;
  bomb_nbCur += 1;
  if (bomb_nbMax <= 1)
    bomb_nbMax = 1;
}

void					Player::powerLess()
{
  bomb_power -= 1;
  if (bomb_power <= 1)
    bomb_power = 1;
}

void					Player::takeBonus(t_bonus bonus)
{
  (this->*_fptrBonus[bonus])();
}
