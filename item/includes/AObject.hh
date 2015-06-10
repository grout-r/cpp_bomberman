#ifndef AOBJ_HPP
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
# include "glm/ext.hpp"

# include "Definition.hh"
# include "AssetsController.hh"

class				AObject
{
protected:
  glm::vec3			_position;
  glm::vec3			_rotation;
  glm::vec3			_scale;
  gdl::Texture			*_texture;
  gdl::Geometry			_geometry;
  int				_smell;
  
protected:
  t_what			_what;

public:
  AObject();
  virtual ~AObject();

protected:
  glm::mat4			calcTransformation();

public:
  virtual bool			initialize();
  virtual void			draw(gdl::BasicShader&, gdl::Clock&);
  
public:
  t_what			what();
  int				getSmell() const;
  std::pair<int, int>		getPos() const;
  glm::vec3			getVecPos();
 
public:
  virtual void			die();
};

#endif //!AOBJ_HPP
