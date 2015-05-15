
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

bool				AObject::initialize()
{
  return (true);
}
   
void				AObject::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)(clock);
  (void)(input);
}
