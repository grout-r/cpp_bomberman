//
// Void.cpp for bomberman in /home/verove_j/rendu/cpp_bomberman/core/src
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Tue May 12 13:25:09 2015 Jordan Verove
// Last update Thu May 21 18:23:54 2015 grout_r
//

#include "Void.hh"

Void::Void(std::pair<int, int> pos)
{
  _what = VOID;
  _position = glm::vec3(pos.first * 100 , 0 , pos.second * 100);
}

bool			Void::initialize()
{
  //  std::cout << " init du void " << std::endl;
  _scale = glm::vec3(100, 100 ,100);
  try
    {
      if (_texture.load("./assets/lava.tga") == false)
        throw (Error("Cannot load the wall texture"));
      //      _geometry.setColor(glm::vec4(1, 0, 0, 1));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      // _geometry.setColor(glm::vec4(1, 1, 0, 1));
      // _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      // _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      // _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      // _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      // _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      // _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      // // _geometry.setColor(glm::vec4(0, 1, 1, 1));
      // _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      // _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      // _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      // _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      // _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      // _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      // // _geometry.setColor(glm::vec4(1, 0, 1, 1));
      // _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      // _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      // _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      // _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      // _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      // _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      // // _geometry.setColor(glm::vec4(0, 1, 0, 1));
      // _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      // _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      // _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      // _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      // _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      // _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      // //_geometry.setColor(glm::vec4(0, 0, 1, 1));
      // _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      // _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      // _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      // _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      // _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      // _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      // _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      _geometry.build();
    }
  catch (Error e)
    {
      std::cout << e.what() << std::endl;
    }
  return (false);
}

