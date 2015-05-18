
#ifndef WALL_HH_
# define WALL_HH_

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

# include "AObject.hh"
# include "Exception.hh"

class Wall :	public AObject
{

public:
  Wall();
  ~Wall();

public:
  bool		initialize();
  void		update();
};

#endif /* !WALL_HH_ */
