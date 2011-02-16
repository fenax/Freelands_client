#include "OgreManager.h"
#include "Files/MapLoader.h"
namespace Graphics{

OgreManager::OgreManager():
	root_(0),
	camera_(0),
	sceneManager_(0),
	window_(0),
	resourcesConfiguration_(Ogre::StringUtil::BLANK),
	pluginsConfiguration_(Ogre::StringUtil::BLANK),
	inputManager_(0),
	mouse_(0),
	keyboard_(0),
	shutDown_(false)
{}

OgreManager::~OgreManager(){
    if (cameraMan_) delete cameraMan_;

    Ogre::WindowEventUtilities::removeWindowEventListener(window_, this);
    windowClosed(window_);
    delete root_;
}


bool OgreManager::go(void){
	#ifdef _DEBUG
	    resourcesConfiguration_ = "resources_d.cfg";
	    pluginsConfiguration_ = "plugins_d.cfg";
	#else
		resourcesConfiguration_ = "resources.cfg";
		pluginsConfiguration_ = "plugins.cfg";
	#endif

    // construct Ogre::Root
    root_ = new Ogre::Root(pluginsConfiguration_);

	//-------------------------------------------------------------------------------------
    // setup resources
    // Load resource paths from config file

    Ogre::ConfigFile cf;
    cf.load(resourcesConfiguration_);
    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            Ogre::ResourceGroupManager::getSingleton().
            	addResourceLocation( archName, typeName, secName);
        }
    }
	
	//-------------------------------------------------------------------------------------
    // configure
    // Show the configuration dialog and initialise the system
    // You can skip this and use root.restoreConfig() to load configuration
    // settings if you were sure there are valid ones saved in ogre.cfg
    if(root_->restoreConfig() || root_->showConfigDialog())
    {
        // If returned true, user clicked OK so initialise
        // Here we choose to let the system create a default rendering window by passing 'true'
        window_ = root_->initialise(true, "Render Window");
    }
    else
    {
        return false;
    }
    
	//-------------------------------------------------------------------------------------
    // choose scenemanager
    // Get the SceneManager, in this case a generic one
    sceneManager_ = root_->createSceneManager(Ogre::ST_GENERIC);

	//-------------------------------------------------------------------------------------
    // create camera
    // Create the camera
    camera_ = sceneManager_->createCamera("PlayerCam");

    // Position it at 500 in Z direction
    camera_->setPosition(Ogre::Vector3(75,5,-75));
    // Look back along -Z
    camera_->lookAt(Ogre::Vector3(0,0,0));
    camera_->setNearClipDistance(5);
    cameraMan_ = new OgreBites::SdkCameraMan(camera_);   // create a default camera controller

	//-------------------------------------------------------------------------------------
    // create viewports
    // Create one viewport, entire window
    Ogre::Viewport* vp = window_->addViewport(camera_);
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

    // Alter the camera aspect ratio to match the viewport
    camera_->setAspectRatio(  Ogre::Real(vp->getActualWidth()) 
    						/ Ogre::Real(vp->getActualHeight()));
    
	//-------------------------------------------------------------------------------------
    // Set default mipmap level (NB some APIs ignore this)
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

	//-------------------------------------------------------------------------------------
    // Create any resource listeners (for loading screens)
    //createResourceListener();
	//-------------------------------------------------------------------------------------
    // load resources
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	//-------------------------------------------------------------------------------------

    loadMap("maps/xlurp_ile.elm");

//-------------------------------------------------------------------------------------
    //create FrameListener
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;

    window_->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

    inputManager_ = OIS::InputManager::createInputSystem( pl );

    keyboard_ = static_cast<OIS::Keyboard*>(inputManager_->createInputObject( OIS::OISKeyboard, true ));
    mouse_ = static_cast<OIS::Mouse*>(inputManager_->createInputObject( OIS::OISMouse, true ));

    mouse_->setEventCallback(this);
    keyboard_->setEventCallback(this);

    //Set initial mouse clipping size
    windowResized(window_);

    //Register as a Window listener
    Ogre::WindowEventUtilities::addWindowEventListener(window_, this);

	root_->addFrameListener(this);
//-------------------------------------------------------------------------------------
    root_->startRendering();

    return true;
}

void
OgreManager::loadMap(std::string source){
    // Create the scene
	//    Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");

    //Ogre::SceneNode* headNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    //headNode->attachObject(ogreHead);

    // Set ambient light
	sceneManager_->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Ogre::Light* l = sceneManager_->createLight("MainLight");
    l->setPosition(20,80,50);

	Ogre::SceneNode* scene = sceneManager_->getRootSceneNode();

//	scene->removeAndDestroyChild ("map");

	Ogre::SceneNode* new_map = scene->createChildSceneNode("map");
	MapLoader map_loader;
	map_loader.loadMap(source, new_map, sceneManager_);

}


bool OgreManager::frameRenderingQueued(const Ogre::FrameEvent& evt){
	if (window_->isClosed()) return false;
	if (shutDown_) return false;

	cameraMan_->frameRenderingQueued(evt);
	keyboard_->capture();
	mouse_->capture();

	return true;
}

bool OgreManager::keyPressed( const OIS::KeyEvent &arg ){
    if (arg.key == OIS::KC_ESCAPE)
    {
    	shutDown_ = true;
    }else if(arg.key == OIS::KC_L){

    }else
	Ogre::LogManager::getSingletonPtr()->logMessage("some asshole pressed a key");
    cameraMan_->injectKeyDown(arg);

    return true;
}

bool OgreManager::keyReleased( const OIS::KeyEvent &arg ){
	cameraMan_->injectKeyUp(arg);
    return true;
}

bool OgreManager::mouseMoved( const OIS::MouseEvent &arg ){
	cameraMan_->injectMouseMove(arg);
    return true;
}
	
bool OgreManager::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){
	cameraMan_->injectMouseDown(arg,id);
    return true;
}

bool OgreManager::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){
	cameraMan_->injectMouseUp(arg,id);
    return true;
}

//Adjust mouse clipping area
void OgreManager::windowResized(Ogre::RenderWindow* rw){
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);

    const OIS::MouseState &ms = mouse_->getMouseState();
    ms.width = width;
    ms.height = height;
}

//Unattach OIS before window shutdown (very important under Linux)
void OgreManager::windowClosed(Ogre::RenderWindow* rw)
{
    //Only close for window that created OIS (the main window in these demos)
    if( rw == window_ )
    {
        if( inputManager_ )
        {
            inputManager_->destroyInputObject( mouse_ );
            inputManager_->destroyInputObject( keyboard_ );

            OIS::InputManager::destroyInputSystem(inputManager_);
            inputManager_ = 0;
        }
    }
}

}
	
