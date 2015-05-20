#include "Map.hh"

Map::Map() :
  x_size(5), y_size(5)
{
  initMap();
}

Map::~Map()
{

}

void				Map::initMap()
{
  bool		      		wall;

  wall = false;
  _map.resize(y_size);
  for (int y = 0; y != y_size; y++)
    {
      if (wall == false)
	{
	  _map[y].resize(x_size);
	  for (int x = 0; x != x_size; x++)
	    {
	      _map[y][x] = new Void;
	      std::cout << "0" << std::endl;
	    }
	  wall = true;
	}
      else
	{
	  _map[y].resize(x_size);
	  for (int x = 0; x != x_size; x++)
	    {
	      if (x % 2 == 0)
		{
		  _map[y][x] = new Void;
		  std::cout << "0" << std::endl;	      
		}
	      else
		{
		  _map[y][x] = new Wall;
		  std::cout << "1" << std::endl;
		}
	    }
	  wall = false;
	}
    }
}

