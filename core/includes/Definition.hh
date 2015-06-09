#ifndef DEF
# define DEF

typedef enum			e_input
  {
    MOVE_UP = 0,
    MOVE_RIGHT,
    MOVE_DOWN,
    MOVE_LEFT,
    PLACE_BOMB,
    MENU,
    EXIT,
    CAM_XPLUS,
    CAM_XMINUS,
    CAM_YPLUS,
    CAM_YMINUS,
    CAM_ZPLUS,
    CAM_ZMINUS,
    CAM_LOCK
  }				t_input;

typedef	struct			s_event
{
  e_input			input;
  int				pid;
}				t_event;

typedef enum			e_what
  {
    VOID,
    WALL,
    PLAYER,
    BOMB,
    BONUS,
    FIRE,
    GAMEOVER
  }				t_what;

typedef enum			e_bonus
  {
    SPEED,
    MORE_BOMB,
    POWER,
    NOTHING,
    SPEED_LESS,
    BOMB_LESS,
    POWER_LESS,
  }				t_bonus;

enum e_action
  {
    GO_NORTH,
    GO_SOUTH,
    GO_EAST,
    GO_WEST,
    PUT_BOMB,
    STAY
  };

#endif
