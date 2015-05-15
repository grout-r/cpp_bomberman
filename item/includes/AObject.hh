# ifndef AOBJ_HPP
# define AOBJ_HPP

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

// La classe abstraite representant un objet avec sa position, sa rotation et son echelle
class				AObject
{
protected:
  glm::vec3			_position;
  glm::vec3			_rotation;
  glm::vec3			_scale;

public:
  AObject();
  virtual ~AObject();

public:
  virtual bool			initialize();
  virtual void			update(gdl::Clock const &clock, gdl::Input &input);
};

#endif //!AOBJ_HPP
