# include "Screen.hh"
# include "Exception.hh"

Screen::Screen()
{
}

Screen::~Screen()
{
}

bool					Screen::init()
{
  try
    {
      if (!_context.start(800, 600, "Bomberbitch"))
	throw Error("Can't initialize context.");
      glEnable(GL_DEPTH_TEST);
      if (!_shader.load("./tp/Shaders/basic.fp", GL_FRAGMENT_SHADER) 
	  || !_shader.load("./tp/Shaders/basic.vp", GL_VERTEX_SHADER) 
	  || !_shader.build())
	throw Error("Can't compile shaders.");
      _camProjection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
      _camTransformation =
	glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
      _shader.bind();
      _shader.setUniform("view", _camTransformation);
      _shader.setUniform("projection", _camProjection);
      return (true);
    }
  catch (Error e)
    {
      std::cerr << e.what() << std::endl; 
    }
  return (false);
}
