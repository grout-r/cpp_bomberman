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

class				Screen
{
private:
  gdl::SdlContext		_context;
  gdl::Clock			_clock;
  gdl::Input			_input;
  gdl::BasicShader		_shader;
  glm::mat4			_camProjection;
  glm::mat4			_camTransformation;

public:
  Screen();
  ~Screen();
  bool				init();
};

#endif
