//
// Player.hh for bomberman in /home/verove_j/rendu/cpp_bomberman/core/includes
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Tue May 12 13:11:14 2015 Jordan Verove
// Last update Wed May 13 11:49:23 2015 Jordan Verove
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

#include "AObject.hh"
//#include "Bomb.hh"

typedef enum			e_where
  {
    NORTH,
    SOUTH,
    EAST,
    WEST,
  }				t_where;

typedef enum			e_color
  {
    ORANGE,
    BLUE,
  }				t_color;

class Player :	public AObject
{
private:
  int			pos_x;
  int			pos_y;
  int			bomb_nb;
  int			bomb_power;
  int			p_speed;
  t_color		bomb_color;
  t_where		orientation;
  int			player_id;

public:
  Player();
  ~Player();
  int			getPosX() const;
  void			setPosX(int x);
  int			getPosY() const;
  void			setPosY(int y);
  int			getBombNb() const;
  void			setBombNb(int nb);
  int			getBombPower() const;
  void			setBombPower(int power);
  int			getPSpeed() const;
  void			setPSpeed(int speed);
  t_where		getOrientation() const;
  void			setOrientation(t_where direction);
  int			getPlayerId() const;
  t_color		getBombColor() const;
  void			setBombColor(t_color color);
  void			putBomb();
};

#endif /* !PLAYER_HH_ */
