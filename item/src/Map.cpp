#include "Map.hh"

Map::Map()
{
  _size = std::make_pair(20, 20);
}

Map::~Map()
{

}

void				Map::init()
{
  bool		      		wall;

  wall = false;
  _map.resize(_size.first);
  for (int x = 0; x != _size.first; x++)
    {
      if (wall == false)
	{
	  _map[x].resize(_size.second);
	  for (int y = 0; y != _size.second; y++)
	    {
	      _map[x][y] = new Void(std::make_pair(x, y));
	      _map[x][y]->initialize();
	    }
	  wall = true;
	}
      else
	{
	  _map[x].resize(_size.second);
	  for (int y = 0; y != _size.second; y++)
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

std::pair<int, int>				Map::getSize()
{
  return (_size);
}

AObject*					Map::getItemAtPos(std::pair<int, int> pos)
{
  return (_map[pos.first][pos.second]);
}
