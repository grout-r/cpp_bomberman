#ifndef VOID_HH
# define VOID_HH

#include "AObject.hh"
#include "Exception.hh"

class Void :	public AObject
{
private:
  int		_smell;

public:
  Void(std::pair<int, int>);
  bool		initialize();
  int		getSmell() const;
};

#endif /* !VOID_HH_ */
