#ifndef VOID_HH
# define VOID_HH

#include "AObject.hh"
#include "Exception.hh"

class Void :	public AObject
{
public:
  Void(std::pair<int, int>);
  bool		initialize();
};

#endif /* !VOID_HH_ */
