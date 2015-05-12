#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <OpenGL.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

# ifndef AOBJ_HPP
# define AOBJ_HPP

// La classe abstraite representant un objet avec sa position, sa rotation et son echelle
class AObject
{
public:
  AObject()
  virtual ~AObject()
  // La fonction initialize charge l'objet ou le construit
  virtual bool initialize()
  // La fonction update sert a gerer le comportement de l'objet
  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  // La fonction draw sert a dessiner l'objet
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  void translate(glm::vec3 const &v)
  void rotate(glm::vec3 const& axis, float angle)
  void scale(glm::vec3 const& scale)
  glm::mat4 getTransformation()
protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
};

#endif //!AOBJ_HPP
