#ifndef ACTRL
# define ACTRL

# include <BasicShader.hh>
# include <Clock.hh>
# include <Input.hh>
# include <SdlContext.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <OpenGL.hh>
# include <iostream>

# include "Exception.hh"

class				AssetsController
{
private:
  AssetsController();
  ~AssetsController();
  
private:
  static AssetsController		*AssetsControllerInstance;
  
private:
  gdl::Model			*_bombModel;
  gdl::Model			*_playerModel;
  
public:
  static void				initAssetsController();
  static void				destroyAssetsController();

public:
  static gdl::Model*			getBombModel();
  static gdl::Model*			getPlayerModel();
};

#endif
