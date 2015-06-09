#ifndef PARAM_HH_
# define PARAM_HH_

#include <utility>

class			Param
{
private:
  int			_nbHuman;
  int			_nbIA;
  std::pair<int, int>	_XY;

public:
  Param(char **, int);
  ~Param();

public:
  int			getNbHuman() const;
  int			getNbIA() const;
  std::pair<int, int>	getXY() const;
};

#endif //!PARAM_HH_
