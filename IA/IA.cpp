
# include <vector>
# include "Map.hh"
# include "Definition.hh"
# include "Player.hh"
# include "Bomb.hh"
# include "Bonus.hh"
# include "Wall.hh"
# include "Void.hh"
# include "AObject.hh"
# include "IA.hh"

IA::IA(){
}

IA::~IA(){
}

t_input			IA::doAction(Map &map, Player *player){
  std::vector<int>	tab;

  tab = createTable(map, player);
  return (move(tab, map, player));
}



t_input				IA::move(std::vector<int> &tab, Map &map, Player *player){
  int				high = 0;
  std::vector<int>::iterator	it;

  createVectorPos(tab);
  for (it = tab.begin(); it != tab.end(); ++it)
    if (*it > high)
      high = *it;
  return (checkPos(high, map, player, tab));
}
std::vector<int>		IA::createTable(Map &map, Player *player){
  std::vector<int>		tab;
  std::pair<int, int>		posPlayer;
  std::pair<int, int>		tmp;
  AObject			*obj;
  int				i = 0;

  for(int i = 0; i != 25; ++i)
    tab.push_back(-5);
  posPlayer = player->getPos();
  tmp.first = posPlayer.first - 2;
  tmp.second = posPlayer.second - 2;
  for (unsigned int y = 0; y != 5; ++y){
    if (tmp.second >= 0 && tmp.second < map.getSize().second){
      for (unsigned int x = 0; x != 5; ++x){
	if (tmp.first >= 0 && tmp.first < map.getSize().first){
	  obj = map.getItemAtPos(tmp);
	  tab[i] = obj->getSmell();
	  ++i;
	}
	else
	  ++i;
	++tmp.first;
      }
    }
    else
      ++i;
    tmp.first = posPlayer.first - 2;
    ++tmp.second;
  }
  return (tab);
}
