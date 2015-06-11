#include "Fire.hh"

Fire::Fire(std::pair<int, int> pos)
{
  this->_smell = 0;
  _timer = 0.2;
  _what = FIRE;
  _position = glm::vec3(pos.first * 100 , 0 , pos.second * 100);
}

bool			Fire::initialize()
{
  _scale = glm::vec3(100, 100 ,100);
  try
    {
      _texture = AssetsController::getFireTexture();
      _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(0, 0.5, 0));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0, 0.5, 0));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0, 0.5, 0));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(0, 0.5, 0));
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

void				Fire::draw(gdl::BasicShader& shader, gdl::Clock &clock)
{
  (void)clock;
  _texture->bind();
  _geometry.draw(shader, calcTransformation(), GL_TRIANGLES); 
}

bool			Fire::stillBurn(double elapsedTime)
{
  _timer -= elapsedTime;
  if (_timer <= 0)
    return (false);
  return (true);
    
}
