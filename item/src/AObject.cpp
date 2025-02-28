
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
  transform = glm::translate(transform, _position);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, _scale);
  return (transform);
}

bool				AObject::initialize()
{
  return (true);
}

void				AObject::draw(gdl::BasicShader& shader, gdl::Clock &clock)
{
  (void)clock;
  _texture->bind();
  _geometry.draw(shader, calcTransformation(), GL_QUADS); 
}

t_what				AObject::what()
{
  return (_what);
}

std::pair<int, int>		AObject::getPos() const
{
  return (std::make_pair(_position.x / 100 , _position.z / 100));
}

glm::vec3			AObject::getVecPos() const
{
  return (_position);
}

int				AObject::getSmell() const{
  return (this->_smell);
}

void				AObject::die()
{
  return ;
}
