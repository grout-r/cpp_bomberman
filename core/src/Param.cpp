#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Exception.hh"
#include "Param.hh"

Param::Param(char **arg, int ac)
{
  std::stringstream     ss;

  if (ac == 1)
    {
      _nbHuman = 2;
      _nbIA = 0;
      _XY = std::make_pair(20, 20);
      return;
    }
  if (ac != 4)
    {
      std::cerr << "Usage: " << arg[0] << " [nbHuman] [nbIA] [size map]" << std::endl;
      exit(-1);
    }
  ss << arg[1];
  ss >> _nbHuman;
  if (_nbHuman < 0 || _nbHuman > 2)
    {
      std::cerr << "nbHuman must be between 0 and 2" << std::endl;
      exit(-1);
    }
  ss.clear();
  ss << arg[2];
  ss >> _nbIA;
  if (_nbIA < 0 || _nbIA > 45)
    {
      std::cerr << "nbIA must be between 0 and 45" << std::endl;
      exit(-1);
    }
  ss.clear();
  ss << arg[3];
  ss >> _XY.first;
  _XY.second = _XY.first;
  if (_XY.first < 10 || _XY.first > 50)
    {
      std::cerr << "coords must be between 10 and 50" << std::endl;
      exit(-1);
    }
}

Param::~Param()
{
}

int			Param::getNbHuman() const
{
  return (_nbHuman);
}

int			Param::getNbIA() const
{
  return (_nbIA);
}

std::pair<int, int>	Param::getXY() const
{
  return (_XY);
}
