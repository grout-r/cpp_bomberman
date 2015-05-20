# ifndef AOBJ_HPP
# define AOBJ_HPP

# include <iostream>
# include <utility>
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

class				AObject
{
protected:
  glm::vec3			_position;
  glm::vec3			_rotation;
  glm::vec3			_scale;
  gdl::Texture			_texture;
  gdl::Geometry			_geometry;
public:
  AObject();
  virtual ~AObject();

protected:
  glm::mat4				calcTransformation();

public:
  virtual bool			initialize();
  virtual void			draw(gdl::BasicShader&, gdl::Clock&);
};

#endif //!AOBJ_HPP
