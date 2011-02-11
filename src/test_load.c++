
#include "Tools/Configuration.h"
#include "Graphics/OgreManager.h"

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
{	// MAIN
	Game::GameManager game_manager;
	Graphics::OgreManager ogre_manager;

	ogre_manager.setGameManager(game_manager);

	ogre_manager.go();
	
	return 0;
}

#ifdef __cplusplus
}
#endif

