#ifndef BONUS_HH
# define BONUS_HH

#include "AObject.hh"

class Bonus :	public AObject
{
private:
  int		_smell;

public:
  Bonus();
  ~Bonus();
  int		getSmell() const;
};

#endif /* !BONUS_HH_ */
