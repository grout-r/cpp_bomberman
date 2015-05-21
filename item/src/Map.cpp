#include "Map.hh"

Map::Map() :
  x_size(20), y_size(20)
{

}

Map::~Map()
{

}

void				Map::init()
{
  bool		      		wall;

  wall = false;
  _map.resize(y_size);
  for (int x = 0; x != x_size; x++)
    {
      if (wall == false)
	{
	  _map[x].resize(y_size);
	  for (int y = 0; y != y_size; y++)
	    {
	      _map[x][y] = new Void(std::make_pair(x, y));
	      _map[x][y]->initialize();
	    }
	  wall = true;
	}
      else
	{
	  _map[x].resize(y_size);
	  for (int y = 0; y != y_size; y++)
	    {
	      if (y % 2 == 0)
		{
		  _map[x][y] = new Void(std::make_pair(x, y));
		  _map[x][y]->initialize();
		}
	      else
		{
		  _map[x][y] = new Wall(std::make_pair(x, y));
		  _map[x][y]->initialize();
		}
	    }
	  wall = false;
	}
    }
}

void						Map::draw(gdl::BasicShader &shader, 
							  gdl::Clock clock)
{
  for (size_t i = 0; i != _map.size(); i++)
    {
      for (size_t j = 0; j != _map[i].size(); j++)
	{
	  _map[i][j]->draw(shader, clock);
	}
    }
}

void						Map::newPlayer(int human)
{
  Player *Michel;

  for (size_t i = 0; i != _map.size(); i++)
    {
      for (size_t j = 0; j != _map[i].size(); j++)
	{
	  if (_map[i][j]->what() == VOID)
	    {
	      Michel = new Player(std::make_pair(i, j), human);
	      Michel->initialize();
	      delete _map[i][j];
	      _map[i][j] = Michel;
	      _player.push_back(Michel);
	      return ;
	    }
	}
    }
}

Player*						Map::getHumanById(int id)
{
  for (size_t i = 0; i != _player.size(); i++)
    {
      if (_player[i]->getHumanId() == id)
	return _player[i];
    }
  return (NULL);
}
