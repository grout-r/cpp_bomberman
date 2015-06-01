
# include <vector>
# include "Definition.hh"
# include "Player.hh"
# include "Bomb.hh"
# include "Bonus.hh"
# include "Wall.hh"
# include "Void.hh"
# include "AObject.hh"
# include "IA.hh"

int	IA::checkBottom(Map &map, Player *player){
  std::pair<int, int>   posPlayer;
  AObject               *tmp;
  std::pair<int, int>   tmp2;
  int                   count = 0;
  Bomb                  *bomb;

  bomb = NULL;
  posPlayer = player->getPos();
  tmp2 = map.getSize();  
  for (; posPlayer.second != tmp2.second; ++posPlayer.second){
    ++count;
    tmp = map.getItemAtPos(posPlayer);
    if (tmp->what() == BOMB){
      if (bomb->getBombPower() >= count)
	return (1);
    }
  }
  return (0);
}

int	IA::checkUp(Map &map, Player *player){
  std::pair<int, int>   posPlayer;
  AObject               *tmp;
  std::pair<int, int>   tmp2;
  int                   count = 0;
  Bomb                  *bomb;

  bomb = NULL;
  posPlayer = player->getPos();
  tmp2 = map.getSize();
  for (; posPlayer.second != 0; --posPlayer.second){
    ++count;
    tmp = map.getItemAtPos(posPlayer);
    if (tmp->what() == BOMB){
      if (bomb->getBombPower() >= count)
	return (1);
    }
  }
  return (0);
}

int	IA::checkRight(Map &map, Player *player){
  std::pair<int, int>   posPlayer;
  AObject               *tmp;
  std::pair<int, int>   tmp2;
  int                   count = 0;
  Bomb                  *bomb;

  bomb = NULL;
  posPlayer = player->getPos();
  tmp2 = map.getSize();
  for (; posPlayer.first != tmp2.first; ++posPlayer.first){
    ++count;
    tmp = map.getItemAtPos(posPlayer);
    if (tmp->what() == BOMB){
      if (bomb->getBombPower() >= count)
	return (1);
    }
  }
  return (0);
}

int	IA::checkLeft(Map &map, Player *player){
  std::pair<int, int>   posPlayer;
  AObject               *tmp;
  std::pair<int, int>   tmp2;
  int                   count = 0;
  Bomb                  *bomb;

  bomb = NULL;
  posPlayer = player->getPos();
  tmp2 = map.getSize();

  for (; posPlayer.first != 0; --posPlayer.first){
    ++count;
    tmp = map.getItemAtPos(posPlayer);
    if (tmp->what() == BOMB){
      if (bomb->getBombPower() >= count)
	return (1);
    }
  }
  return (0);
}
