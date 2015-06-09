//
// Bonus.cpp for bomberman in /home/verove_j/rendu/cpp_bomberman/core/src
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Tue May 12 13:18:59 2015 Jordan Verove
// Last update Tue Jun  9 14:19:25 2015 grout_r
//

#include "AObject.hh"
#include "Bonus.hh"
#include <ctime>

Bonus::Bonus(std::pair<int, int> pos)
{
  int		nbr_rand;

  nbr_rand = std::rand() % 7;
  std::srand(std::time(0));
  this->_smell = 10;
  _what = BONUS;
  _bonus = (t_bonus)nbr_rand;
  _is_exploded = false;
  _what = BONUS;
  _position = glm::vec3(pos.first * 100 , 0 , pos.second * 100);
}

Bonus::~Bonus()
{
  
}

bool			Bonus::initialize()
{
  _scale = glm::vec3(100, 100 ,100);
  try
    {
      _texture = AssetsController::getBonusTexture();
      _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      _geometry.build();
    }
  catch (Error e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (false);
}

bool		Bonus::getExploded() const
{
  return (this->_is_exploded);
}

void		Bonus::setExploded(bool exploded)
{
  this->_is_exploded = exploded;
}
