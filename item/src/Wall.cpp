
#include "Wall.hh"

Wall::Wall(std::pair<int, int> pos)
{
  _what = WALL;
  _position = glm::vec3(pos.first * 100 , 0 , pos.second * 100);
}

Wall::~Wall()
{
  
}

bool			Wall::initialize()
{
  _scale = glm::vec3(100, 100 ,100);
  try
    {
      if (_texture.load("./assets/wall.tga") == false)
        throw (Error("Cannot load the wall texture"));
      //      _geometry.setColor(glm::vec4(1, 0, 0, 1));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      // _geometry.setColor(glm::vec4(1, 1, 0, 1));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      // _geometry.setColor(glm::vec4(0, 1, 1, 1));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      // _geometry.setColor(glm::vec4(1, 0, 1, 1));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      // _geometry.setColor(glm::vec4(0, 1, 0, 1));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      //_geometry.setColor(glm::vec4(0, 0, 1, 1));
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

void				update()
{
}
