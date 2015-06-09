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
  gdl::Texture			*_wallTexture;
  gdl::Texture			*_voidTexture;
  gdl::Texture			*_fireTexture;
  gdl::Texture			*_gameOverTexture;

public:
  static void				initAssetsController();
  static void				destroyAssetsController();

public:
  static gdl::Model*			getBombModel();
  static gdl::Model*			getPlayerModel();
  static gdl::Texture*			getWallTexture();
  static gdl::Texture*			getVoidTexture();
  static gdl::Texture*			getFireTexture();
  static gdl::Texture*			getGameOverTexture();
};

#endif
