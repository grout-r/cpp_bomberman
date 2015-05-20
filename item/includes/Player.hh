#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <map>

# include "AObject.hh"
# include "Model.hh"
# include "Bomb.hh"
# include "Exception.hh"
# include "Screen.hh"

typedef enum			e_color
  {
    ORANGE,
    BLUE
  }				t_color;

class Player :	public AObject
{
private:
  std::pair<int, int>	pos;
  int			bomb_nb;
  int			bomb_power;
  int			p_speed;
  t_color		bomb_color;
  int			player_id;
  int			humanId;
private:
  gdl::Model		_playerModel;
  int			_frameCounter;

private:
  std::map<t_input, glm::vec3>		_movePlayerBind;
  std::map<t_input, glm::vec3>		_rotatePlayerBind;
public:
  Player(int x, int y, int humanId = 0);
  ~Player();
  std::pair<int, int>		getPos() const;
  void				setPos(std::pair<int, int>);
  int				getBombNb() const;
  void				setBombNb(int nb);
  int				getBombPower() const;
  void				setBombPower(int power);
  int				getPSpeed() const;
  void				setPSpeed(int speed);
  t_where			getOrientation() const;
  void				setOrientation(t_where direction);
  int				getPlayerId() const;
  t_color			getBombColor() const;
  void				setBombColor(t_color color);
  int				getHumanId();
  void				putBomb();

public:
  bool				initialize();
  void				update();
  void				draw(gdl::BasicShader& shader, gdl::Clock &);
  void				move(t_input input);
};

#endif /* !PLAYER_HH_ */
