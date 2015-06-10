#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <map>

# include "AObject.hh"
# include "Model.hh"
# include "Bomb.hh"
# include "Exception.hh"
# include "Definition.hh"
# include "Map.hh"
# include "PlayerIndicator.hh"

typedef enum				e_color
  {
    ORANGE,
    BLUE
  }					t_color;

class Player :	public AObject
{
private:
  int					bomb_nb;
  int					bomb_power;
  int					p_speed;
  t_color				bomb_color;
  int					player_id;
  int					humanId;
  bool					_alive;
private:
  gdl::Model				*_playerModel;
  int					_frameCounter;
  PlayerIndicator			*_indicator;

private:
  std::map<t_input, glm::vec3>		_movePlayerBind;
  std::map<t_input, glm::vec3>		_rotatePlayerBind;
public:
  Player(std::pair<int, int>, int humanId = 0);
  ~Player();
  int					getBombNb() const;
  void					setBombNb(int nb);
  int					getBombPower() const;
  void					setBombPower(int power);
  int					getPSpeed() const;
  void					setPSpeed(int speed);
  int					getPlayerId() const;
  t_color				getBombColor() const;
  void					setBombColor(t_color color);
  int					getHumanId();
  void					putBomb();

public:
  bool					initialize();
  void					update();
  void					draw(gdl::BasicShader& shader, gdl::Clock &);
  void					move(t_input input, double);
  std::vector<std::pair<int, int> >	getNewPos(t_input input);

public:
  void					die();
  bool					isAlive() const;
};

#endif /* !PLAYER_HH_ */
