#include "Void.hh"

Void::Void(std::pair<int, int> pos)
{
  this->_smell = 0;
  _what = VOID;
  _position = glm::vec3(pos.first * 100 , 0 , pos.second * 100);
}

bool			Void::initialize()
{
  _scale = glm::vec3(100, 100 ,100);
  try
    {
      _texture = AssetsController::getVoidTexture();
      _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      _geometry.build();
    }
  catch (Error e)
    {
      std::cout << e.what() << std::endl;
    }
  return (false);
}
