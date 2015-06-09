#ifndef FIRE_HH
# define FIRE_HH

# include <unistd.h>
# include "AObject.hh"
# include "Exception.hh"

class Fire :	public AObject
{
private:
  double	_timer;
public:
  Fire(std::pair<int, int>);
  bool		initialize();
  void		draw(gdl::BasicShader& shader, gdl::Clock &clock);
  bool		stillBurn(double);
};

#endif /* !FIRE_HH_ */
