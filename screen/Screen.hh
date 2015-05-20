#ifndef SCREEN
# define SCREEN

# include <BasicShader.hh>
# include <Clock.hh>
# include <Input.hh>
# include <SdlContext.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <OpenGL.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
# include <vector>
# include <map>

# include "AObject.hh"

typedef enum			e_input
  {
    MOVE_RIGHT,
    MOVE_LEFT,
    MOVE_UP,
    MOVE_DOWN,
    PLACE_BOMB,
    MENU,
    EXIT,
    CAM_XPLUS,
    CAM_XMINUS,
    CAM_YPLUS,
    CAM_YMINUS,
    CAM_ZPLUS,
    CAM_ZMINUS,
    
  }				t_input;

typedef	struct			s_event
{
  e_input			input;
  int				pid;
}				t_event;

class				Screen
{
private:
  gdl::SdlContext		_context;
  gdl::Clock			_clock;
  gdl::Input			_input;
  gdl::BasicShader		_shader;
  glm::mat4			_camProjection;
  glm::mat4			_camTransformation;

private:
  std::vector <std::pair<int, std::pair<t_input, int> > >	_input_mapping;	
public:
  Screen();
  ~Screen();
  bool				init();
  void				updateInputs(std::vector<t_event>*);
  void			        updateScreen(std::vector<AObject*>&);
};

#endif
