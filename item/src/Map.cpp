#include "Map.hh"
#include <cstdlib>
#include <ctime>

Map::Map(std::pair<int, int> size)
{
  std::srand(std::time(0));

  if ((size.first % 2) == 0)
    _size.first = size.first + 3;
  else
    _size.first= size.first + 2;
  if ((size.second % 2) == 0)
    _size.second = size.second + 3;
  else
    _size.second = size.second + 2;
  genRandMap();
}

Map::~Map()
{
  
}
 
void				Map::fillMap()
{
  _map.resize(_size.second);
  for (int y = 0; y != _size.second; y++)
    {
      _map[y].resize(_size.first);
      for (int x = 0; x != _size.first; x++)
	{
	  _map[y][x] = new Wall(std::make_pair(x, y));
	}
    }
}

std::vector<bool>		Map::check_hut(std::pair<int, int> hut)
{
  bool				tmp[] = {false, false, false, false};
  std::vector<bool>		tab(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));
  
  if (hut.first > 2 && (_map[hut.first - 2][hut.second]->what() == WALL))
    tab[0] = 1;
  if (hut.first < (_size.first - 2) && (_map[hut.first + 2][hut.second]->what() == WALL))
    tab[1] = 1;
  if (hut.second > 2 && (_map[hut.first][hut.second - 2]->what() == WALL))
    tab[2] = 1;
  if (hut.second < (_size.second - 2) && (_map[hut.first][hut.second + 2]->what() == WALL))
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
  delete _map[pos.first][pos.second];
  _map[pos.first][pos.second] = new Void(pos);
  delete _map[pos.first - 1][pos.second];
  _map[pos.first - 1][pos.second] = new Void(std::make_pair(pos.first - 1, pos.second));
  delete _map[pos.first - 2][pos.second];
  _map[pos.first - 2][pos.second] = new Void(std::make_pair(pos.first - 2,pos.second));
  return (digMap(std::make_pair(pos.first - 2, pos.second)));
}

bool				Map::down(std::pair<int, int> pos)
{
  delete _map[pos.first][pos.second];
  _map[pos.first][pos.second] = new Void(pos);
  delete _map[pos.first + 1][pos.second];
  _map[pos.first + 1][pos.second] = new Void(std::make_pair(pos.first + 1, pos.second));
  delete _map[pos.first + 2][pos.second];
  _map[pos.first + 2][pos.second] = new Void(std::make_pair(pos.first + 2,pos.second));
  return (digMap(std::make_pair(pos.first + 2, pos.second)));
}

bool				Map::left(std::pair<int, int> pos)
{
  delete _map[pos.first][pos.second];
  _map[pos.first][pos.second] = new Void(pos);
  delete _map[pos.first][pos.second - 1];
  _map[pos.first][pos.second - 1] = new Void(std::make_pair(pos.first, pos.second - 1));
  delete _map[pos.first][pos.second - 2];
  _map[pos.first][pos.second - 2] = new Void(std::make_pair(pos.first, pos.second - 2));
  return (digMap(std::make_pair(pos.first, pos.second - 2)));
}

bool				Map::right(std::pair<int, int> pos)
{
  delete _map[pos.first][pos.second];
  _map[pos.first][pos.second] = new Void(pos);
  delete _map[pos.first][pos.second + 1];
  _map[pos.first][pos.second + 1] = new Void(std::make_pair(pos.first, pos.second + 1));
  delete _map[pos.first][pos.second + 2];
  _map[pos.first][pos.second + 2] = new Void(std::make_pair(pos.first, pos.second + 2));
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

void				Map::genRandMap()
{
  fillMap();
  digMap(std::make_pair(1, 1));
  std::cout << "tg grout" << std::endl;
  for (int x = 0; x != _size.first; x++)
    for (int y = 0; y != _size.second; y++)
      {
	std::cout << x << ", " << y << ", " << _map[x][y]->what() << std::endl;
	_map[x][y]->initialize();
      }
  std::cout << "tg grout" << std::endl;
}

/*
bool						Map::initMap(char *filename)
{
  int						i;
  std::stream					file;

  i = 0;
  if (filename == NULL)
    genRandMap();
  else
    {
      file.open(filename);
      try
	{
	  if (!file.is_open())
	    throw Error("The file has not been found");
    }
}*/

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
