#ifndef FIRE_HH
# define FIRE_HH

# include <time.h>
# include <unistd.h>
# include "AObject.hh"
# include "Exception.hh"

class Fire :	public AObject
{
private:
  time_t	_timer;
public:
  Fire(std::pair<int, int>);
  bool		initialize();
  void		draw(gdl::BasicShader& shader, gdl::Clock &clock);
  bool		stillBurn();
};

#endif /* !FIRE_HH_ */
