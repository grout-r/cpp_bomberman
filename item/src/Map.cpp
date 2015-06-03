#include "Map.hh"
#include <cstdlib>
#include <ctime>

Map::Map(std::pair<int, int> size)
{
  std::srand(std::time(0));

  _size.first = size.first + 2;
  _size.second = size.second + 2;
  if ((_size.first % 2) == 0)
    _size.first= size.first + 1;
  if ((_size.second % 2) == 0)
    _size.second = size.second + 1;
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
	      if (x == 0 || x == (_size.first - 1) || y == 0 || y == (_size.second -1))
		{
		  _map[x][y] = new Wall(std::make_pair(x, y));
		  _map[x][y]->initialize();
		}
	      else
		{
		  _map[x][y] = new Void(std::make_pair(x, y));
		  _map[x][y]->initialize();
		}
	    }
	  wall = true;
	}
      else
	{
	  _map[x].resize(_size.second);
	  for (int y = 0; y != _size.second; y++)
	    {
	      if (x == 0 || x == (_size.first - 1) || y == 0 || y == (_size.second - 1))
		{
                  _map[x][y] = new Wall(std::make_pair(x, y));
                  _map[x][y]->initialize();
		}
	      else
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
	    }
	  wall = false;
	}
    }
}
 
void				Map::fillMap()
{
  static bool			last_fill = false;

  if (last_fill == true)
    {
      _map.resize(_size.second);
      for (int y = 0; y != _size.second; y++)
	{
	  _map[y].resize(_size.first);
	  for (int x = 0; x != _size.first; x++)
	    {
	      if (_int_map[y][x] == 0)
		{
		  _map[y][x] = new Wall(std::make_pair(x, y));
		  _map[y][x]->initialize();
		}	      
	      else
		{
		  _map[y][x] = new Void(std::make_pair(x, y));
		  _map[y][x]->initialize();
		}
	    }
	}
    }
  else
    {
      _int_map.resize(_size.second);
      for (int y = 0; y != _size.second; y++)
	{
	  _int_map[y].resize(_size.first);
	  for (int x = 0; x != _size.first; x++)
	    _int_map[y][x] = 0;
	}
    }
  last_fill = true;
}

std::vector<bool>		Map::check_hut(std::pair<int, int> hut)
{
  bool				tmp[] = {false, false, false, false};
  std::vector<bool>		tab(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));
  
  if (hut.first > 2 && (_int_map[hut.first - 2][hut.second] == 0))
    tab[0] = 1;
  if (hut.first < (_size.first - 2) && (_int_map[hut.first + 2][hut.second] == 0))
    tab[1] = 1;
  if (hut.second > 2 && (_int_map[hut.first][hut.second - 2] == 0))
    tab[2] = 1;
  if (hut.second < (_size.second - 2) && (_int_map[hut.first][hut.second + 2] == 0))
    tab[3] = 1;
  return (tab);
}

void				Map::initDirection(bool (Map::*function_ptr[])(std::pair<int, int>))
{
  function_ptr[0] = &Map::up;
  function_ptr[1] = &Map::down;
  function_ptr[2] = &Map::left;
  function_ptr[3] = &Map::right;  
}

bool				Map::up(std::pair<int, int> pos)
{
  _int_map[pos.first][pos.second] = 1;
  _int_map[pos.first - 1][pos.second] = 1;
  _int_map[pos.first - 2][pos.second] = 1;
  return (digMap(std::make_pair(pos.first - 2, pos.second)));
}

bool				Map::down(std::pair<int, int> pos)
{
  _int_map[pos.first][pos.second] = 1;
  _int_map[pos.first + 1][pos.second] = 1;
  _int_map[pos.first + 2][pos.second] = 1;
  return (digMap(std::make_pair(pos.first + 2, pos.second)));
}

bool				Map::left(std::pair<int, int> pos)
{
  _int_map[pos.first][pos.second] = 1;
  _int_map[pos.first][pos.second - 1] = 1;
  _int_map[pos.first][pos.second - 2] = 1;
  return (digMap(std::make_pair(pos.first, pos.second - 2)));
}

bool				Map::right(std::pair<int, int> pos)
{
  _int_map[pos.first][pos.second] = 1;
  _int_map[pos.first][pos.second + 1] = 1;
  _int_map[pos.first][pos.second + 2] = 1;
  return (digMap(std::make_pair(pos.first, pos.second + 2)));
}

bool				Map::digMap(std::pair<int, int> pos)
{
  std::vector<bool>		tab;
  int				nbr_rand;
  bool				(Map::*function_ptr[4])(std::pair<int, int>);

  nbr_rand = std::rand() % 4;
  tab = check_hut(pos);
  initDirection(function_ptr);
  if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0)
    return true;
  while (tab[0] != 0 || tab[1] != 0 || tab[2] != 0 || tab[3] != 0)
    {
      while (tab[nbr_rand] == 0)
	nbr_rand = std::rand() % 4;
      (this->*function_ptr[nbr_rand])(pos);
      tab = check_hut(pos);
    }
  return (true);
}

void				Map::removeWalls()
{
  int				x_rand;
  int				y_rand;
  int				removed_wall;
  int				nb_remove_wall;

  removed_wall = 0;
  nb_remove_wall = (_size.first * _size.second) / 4;
  x_rand = std::rand() % _size.first;
  y_rand = std::rand() % _size.first;
  while (removed_wall != nb_remove_wall)
    {
      while (_int_map[x_rand + 1][y_rand + 1] != 0)
	{
	  x_rand = std::rand() % (_size.first - 2);
	  y_rand = std::rand() % (_size.second - 2);
	}
      removed_wall += 1;
      _int_map[x_rand + 1][y_rand + 1] = 1;
    }
}

void				Map::genRandMap()
{
  fillMap();
  digMap(std::make_pair(1, 1));
  removeWalls();
  fillMap();
}

void						Map::draw(gdl::BasicShader &shader, 
							  gdl::Clock clock)
{
  for (size_t i = 0; i != _map.size(); i++)
    {
      for (size_t j = 0; j != _map[i].size(); j++)
	_map[i][j]->draw(shader, clock);
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
	      //Michel = new Player(std::make_pair(i, j), human);
	       Michel = new Player(std::make_pair(5, 5), human);
  	      Michel->initialize();
	      _map[i][j] = Michel;
	      _player.push_back(Michel);
	      return ;
	    }
	}
    }
}

void						Map::newBomb(Player *player,
							     std::pair<int, int> pos)
{
  Bomb	*Michel;

  if (_map[pos.first][pos.second]->what() == VOID)
    {
      Michel = new Bomb (player, pos);
      Michel->initialize();
      delete _map[pos.first][pos.second];
      _map[pos.first][pos.second] = Michel;
      _bomb.push_back(Michel);
      return ;
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

void						Map::fireSomeHut(std::pair<int, int> pos)
{
  (void)pos;  
}

void						Map::update()
{
  std::pair<int, int>				pos;
  
  for (size_t i = 0; i != _bomb.size(); i++)
    {
      if (_bomb[i]->explose() == true)
	{
	  pos = _bomb[i]->getPos();
	  delete _map[pos.first][pos.second];
	  _map[pos.first][pos.second] = new Void(pos);
	  _map[pos.first][pos.second]->initialize();
	  //_bomb.erase(_bomb.begin() + i - 1);
	  fireSomeHut(pos);
	}
    }
}

std::vector<Player*>*			       Map::getPlayerSet()
{
  return (&_player);
}
