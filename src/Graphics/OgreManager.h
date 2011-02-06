#ifndef OGREMANAGER_VA02DJ6R

#define OGREMANAGER_VA02DJ6R

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

namespace Game{
class OgreManager : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener, OgreBites::SdkTrayListener
{
public :
	OgreManager();
	virtual ~OgreManager();
	
    Ogre::Root * 		root_;
    Ogre::Camera* 		camera_;
    Ogre::SceneManager* sceneManager_;
    Ogre::RenderWindow* window_;
    Ogre::String 		resourcesConfiguration_;
    Ogre::String 		pluginsConfiguration_;

    bool shutDown_;

    // OIS Input devices
    OIS::InputManager* 	inputManager_;
    OIS::Mouse*    		mouse_;
    OIS::Keyboard* 		keyboard_;

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
