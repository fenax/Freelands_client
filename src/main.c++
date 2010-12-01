#include "MinimalOgre.h"
#include "Game/GameManager.h"
#include "Protocol/ELProtocolV0.h"
#include "Tools/Configuration.h"
#include "Network/TcpNetwork.h"

#include "Network/Buffer.h"

using namespace std;

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        MinimalOgre app;

        try {
        	Tools::Configuration configuration;
        	Game::GameManager game_manager;
        	Protocol::ELProtocolV0 protocol(game_manager);
        	Network::TcpNetwork network(configuration.server, protocol);

        	network.connect();
        	network.start();
        	//protocol.sendCreateCharacter("login","password", 0,0,0,0,0,0,0);

        	protocol.sendLogin("login","password");



 //       	protocol.sendOpeninigScreen();

//        	Network::Buffer buff;
//        	cout << "size = " << buff.size() << endl;
//        	cout << "in_avial = " << buff.in_avail() << endl;
//        	string kikoo = "putain de merde";
//        	cout << "string is : " << kikoo.length() << " caracters long"<< endl;
//        	buff.write_c_string(kikoo);
//        	cout << "size = " << buff.size() << endl;
//        	cout << "in_avial = " << buff.in_avail() << endl;
//
//        	buff.makeReadable();
//        	cout << "size = " << buff.size() << endl;
//        	cout << "in_avial = " << buff.in_avail() << endl;




            //app.go();


        	while(true);


        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
