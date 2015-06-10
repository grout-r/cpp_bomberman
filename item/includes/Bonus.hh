#ifndef BONUS_HH
# define BONUS_HH

#include "AObject.hh"

class Bonus :	public AObject
{
private:
  t_bonus	_bonus;
  bool		_is_exploded;

public:
  Bonus(std::pair<int, int>);
  ~Bonus();
  bool		getExploded() const;
  void		setExploded(bool exploded);
  bool		initialize();
  virtual void	die();
};

#endif /* !BONUS_HH_ */
