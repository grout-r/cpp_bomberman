#ifndef FIRE_HH
# define FIRE_HH

#include "AObject.hh"
#include "Exception.hh"

class Fire :	public AObject
{
private:
  gdl::Model	_fireModel;

public:
  Fire(std::pair<int, int>);
  bool		initialize();
  void		draw(gdl::BasicShader& shader, gdl::Clock &clock);
};

#endif /* !FIRE_HH_ */
