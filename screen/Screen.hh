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
# include "glm/ext.hpp"
# include <SDL/SDL.h>
# include <SDL/SDL_mixer.h>
# include "AObject.hh"
# include "Map.hh"
# include "Definition.hh"

class Map;

class				Screen
{
private:
  gdl::SdlContext		_context;
  gdl::Clock			_clock;
  gdl::Input			_input;
  gdl::BasicShader		_shader;
  glm::mat4			_camProjection;
  glm::mat4			_camTransformation;
  glm::vec3			_camPosition;
  glm::vec3			_camTarget;
private:
  std::vector <std::pair<int, std::pair<t_input, int> > >	_input_mapping;	
  std::map<e_input, glm::vec3>					_moveCamMapping;

private:
  bool				_lockCam;
  
private:
  void				updateCam(Map *);

public:
  Screen();
  ~Screen();
  bool				init();
  void				updateInputs(std::vector<t_event>*);
  void			        updateScreen(Map*);
  void				moveCam(t_input);
  void				lockCam();
};

#endif
