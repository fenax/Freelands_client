
AM_CPPFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(BOOST_CPPFLAGS) -Wall -pedantic

bin_PROGRAMS=EternalLands

EternalLands_SOURCES = main.c++ 

EternalLands_SOURCES += Network/TcpNetwork.c++
EternalLands_SOURCES += Network/Buffer.c++
EternalLands_SOURCES += Network/FatalNetworkException.c++ 

EternalLands_SOURCES += MinimalOgre.c++

EternalLands_SOURCES += Protocol/Protocol.c++
EternalLands_SOURCES += Protocol/ELProtocolV0.c++

EternalLands_SOURCES += Game/GameManager.c++ 
EternalLands_SOURCES += Game/Actor.c++ 
EternalLands_SOURCES += Game/Player.c++ 
EternalLands_SOURCES += Game/InventoryItem.c++ 
EternalLands_SOURCES += Game/Inventory.c++ 


EternalLands_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(BOOST_LDFLAGS) -lboost_thread