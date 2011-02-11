
AM_CPPFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(BOOST_CPPFLAGS) -Wall

bin_PROGRAMS=EternalLands test_ogre


Network_SOURCES = Network/TcpNetwork.c++
Network_SOURCES += Network/Buffer.c++
Network_SOURCES += Network/FatalNetworkException.c++ 

Protocol_SOURCES = Protocol/Protocol.c++
Protocol_SOURCES += Protocol/ELProtocolV0.c++

Game_SOURCES = Game/GameManager.c++ 
Game_SOURCES += Game/Actor.c++ 
Game_SOURCES += Game/EnhancedActor.c++ 
Game_SOURCES += Game/Player.c++ 
Game_SOURCES += Game/InventoryItem.c++ 
Game_SOURCES += Game/Inventory.c++ 



Files_SOURCES = Files/FileLoader.c++
Files_SOURCES += Files/MapLoader.c++

Graphics_SOURCES = Graphics/HeightMap.c++
Graphics_SOURCES += Graphics/OgreManager.c++



EternalLands_SOURCES = $(Network_SOURCES) $(Protocol_SOURCES) $(Game_SOURCES) $(Files_SOURCES) $(Graphics_SOURCES) main.c++ 

EternalLands_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(BOOST_LDFLAGS) -lboost_thread



test_ogre_SOURCES = $(Network_SOURCES) $(Protocol_SOURCES) $(Game_SOURCES) $(Files_SOURCES) $(Graphics_SOURCES) test_load.c++

test_ogre_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(BOOST_LDFLAGS) -lboost_thread
