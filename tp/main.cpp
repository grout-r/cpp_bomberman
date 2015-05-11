// main.cpp for bomber in /home/roman/Documents/dev/cpp_bomberman/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Wed May  6 11:29:04 2015 grout_r
// Last update Thu May  7 14:58:28 2015 grout_r
//

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

#include "AObject.hpp"
#include "engine.hpp"
#include <cstdlib>

int main()
{
  //  On cree son engine
  GameEngine engine;
  if (engine.initialize() == false)
    {
      std::cout << " failure " << std::endl;
      return (EXIT_FAILURE);
    }
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
