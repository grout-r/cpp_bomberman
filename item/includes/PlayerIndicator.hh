#ifndef PINDIC
# define PINDIC

# include <cstdlib>
# include "AObject.hh"

class					PlayerIndicator : public AObject
{
private:
  int					_humanId;
public:
  PlayerIndicator(glm::vec3, int);
  
public:
  bool					initialize();
  void					updatePosition(glm::vec3);
};

# endif
