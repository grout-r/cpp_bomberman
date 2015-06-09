#ifndef GO_HH
# define GO_HH

#include "AObject.hh"
#include "Exception.hh"

class GameOver :	public AObject
{
public:
  GameOver();
  bool		initialize();
};

#endif /* GO_HH_ */
