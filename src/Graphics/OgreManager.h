#ifndef OGREMANAGER_VA02DJ6R

#define OGREMANAGER_VA02DJ6R

#include <string>

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <SdkTrays.h>
#include <SdkCameraMan.h>

#include "Game/GameManager.h"

namespace Graphics{
class OgreManager : 
	public Ogre::FrameListener, 
	public Ogre::WindowEventListener, 
	public OIS::KeyListener, 
	public OIS::MouseListener, OgreBites::SdkTrayListener
{
public :
	OgreManager();
	virtual ~OgreManager();
	
    Ogre::Root * 		root_;
    Ogre::Camera* 		camera_;
    Ogre::SceneManager* sceneManager_;
    Ogre::RenderWindow* window_;
    std::string 		resourcesConfiguration_;
    std::string 		pluginsConfiguration_;
    Game::GameManager*  game_manager_;

    bool shutDown_;

    // OIS Input devices
    OIS::InputManager* 	inputManager_;
    OIS::Mouse*    		mouse_;
    OIS::Keyboard* 		keyboard_;

    virtual void setGameManager(Game::GameManager& game_manager){
		game_manager_ = &game_manager;
	}


    virtual void loadMap(std::string source);

    // Ogre::FrameListener
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

    // OIS::KeyListener
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
    // OIS::MouseListener
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

    // Ogre::WindowEventListener
    virtual void windowResized(Ogre::RenderWindow* rw);
    virtual void windowClosed(Ogre::RenderWindow* rw);
		
	virtual bool go();
};
}

#endif /* end of include guard: OGREMANAGER_VA02DJ6R */
