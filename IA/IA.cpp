//
// IA.cpp for IA_bomber in /home/gazzol_j/rendu/cpp_bomberman/IA
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue May 12 13:32:12 2015 julien gazzola
// Last update Thu May 28 16:45:15 2015 julien gazzola
//

# include <vector>
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


e_input		IA::FindBonus(Map &map, Player *player){
  if (CheckBonus(map, player) != 0)
    return (Move(map, player));
  else
    return (CheckPlayer(map, player));
}

e_input		IA::doAction(Map &map, Player *player){
  std::vector<std::pair<AObject*, int> >	tab;

  tab = CreateTable(map, player);
  if (CheckBomb(map, player) != 0)
    return (CheckFreeCase(map, player));
  else
    return (FindBonus(map, player));
  std::cout << "caca" << std::endl;
  return (MOVE_RIGHT);
}

e_input       	IA::CheckFreeCase(Map &map, Player *player){
  (void) map;
  (void) player;
  return (MOVE_RIGHT);
}

int       	IA::CheckBonus(Map &map, Player *player){
  (void) map;
  (void) player;
  return (1);
}

e_input       	IA::CheckPlayer(Map &map, Player *player){
  (void) map;
  (void) player;
  /*
    if (playerProche)
       ;
    else
       return ();
   */
  return (MOVE_RIGHT);
}

e_input		IA::Move(Map &map, Player *player){
  (void) map;
  (void) player;
  return (MOVE_RIGHT);
}

std::vector<std::pair<AObject*, int> >		IA::CreateTable(Map &map, Player *player){
    std::vector<std::pair<AObject*, int> >	tab;
    std::pair<AObject*, int>			pairToAdd;
    std::pair<int, int>				posPlayer;
    std::pair<int, int>				tmp;
    AObject					*obj;

    posPlayer = player->getPos();
    tmp.first = posPlayer.first - 2;
    tmp.second = posPlayer.second - 2;
    if (posPlayer.first - 2 >= 0){
      if (posPlayer.second - 2 >= 0){
	for (unsigned int y = 0; y != 5; ++y){
	  for (unsigned int x = 0; x != 5; ++x){
	    obj = map.getItemAtPos(tmp);
	    pairToAdd.second = obj->getSmell();
	    tab.push_back(pairToAdd);
	    ++tmp.first;
	  }
	  tmp.first = posPlayer.first - 2;
	  ++tmp.second;
	}
      }
    }
    return (tab);
}

int			IA::CheckBomb(Map &map, Player *player){
  std::pair<int, int>  	posPlayer;
  AObject		*tmp;
  std::pair<int, int>	tmp2;
  int			xPlayer;
  int			yPlayer;
  int			count = 0;
  Bomb			*bomb;

  bomb = NULL;
  posPlayer = player->getPos();
  xPlayer = posPlayer.first;
  yPlayer = posPlayer.second;
  tmp2 = map.getSize();
  for (; posPlayer.second != tmp2.second; ++posPlayer.second){
    ++count;
    tmp = map.getItemAtPos(posPlayer);
    if (tmp->what() == BOMB){
       if (bomb->getBombPower() >= count)
	  return (1);
      }
  }
  posPlayer.first = xPlayer;
  posPlayer.second = yPlayer;

  for (; posPlayer.second != 0; --posPlayer.second){
    tmp = map.getItemAtPos(posPlayer);
    if (tmp->what() == BOMB){
	if (bomb->getBombPower() >= count)
	  return (1);
      }
  }
  posPlayer.first = xPlayer;
  posPlayer.second = yPlayer;

  for (; posPlayer.first != tmp2.first; ++posPlayer.first){
    tmp = map.getItemAtPos(posPlayer);
    if (tmp->what() == BOMB){
	if (bomb->getBombPower() >= count)
	  return (1);
      }
  }
  posPlayer.first = xPlayer;
  posPlayer.second = yPlayer;

  for (; posPlayer.first != 0; ++posPlayer.first){
    tmp = map.getItemAtPos(posPlayer);
    if (tmp->what() == BOMB){
	if (bomb->getBombPower() >= count)
	  return (1);
      }
  }
  return (0);
}
