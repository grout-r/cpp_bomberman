
#include "AObject.hh"

AObject::AObject() :
  _position(0, 0, 0),
  _rotation(0, 0, 0),
  _scale(1, 1, 1)
{
}

AObject::~AObject()
{

}

glm::mat4				AObject::calcTransformation()
{
  glm::mat4 transform(1);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  return (transform);
}

bool				AObject::initialize()
{
  std::cout << "AObject init" << std::endl;
  return (true);
}

void				AObject::draw(gdl::BasicShader& shader)
{
  (void)shader;
  _texture.bind();
  _geometry.draw(shader, calcTransformation(), GL_QUADS); 
}
