/*
Copyright (C) 2007 <SWGEmu>
 
This File is part of Core3.
 
This program is free software; you can redistribute 
it and/or modify it under the terms of the GNU Lesser 
General Public License as published by the Free Software
Foundation; either version 2 of the License, 
or (at your option) any later version.
 
This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU Lesser General Public License for
more details.
 
You should have received a copy of the GNU Lesser General 
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 
Linking Engine3 statically or dynamically with other modules 
is making a combined work based on Engine3. 
Thus, the terms and conditions of the GNU Lesser General Public License 
cover the whole combination.
 
In addition, as a special exception, the copyright holders of Engine3 
give you permission to combine Engine3 program with free software 
programs or libraries that are released under the GNU LGPL and with 
code included in the standard release of Core3 under the GNU LGPL 
license (or modified versions of such code, with unchanged license). 
You may copy and distribute such a system following the terms of the 
GNU LGPL for Engine3 and the licenses of the other code concerned, 
provided that you include the source code of that other code when 
and as the GNU LGPL requires distribution of source code.
 
Note that people who make modified versions of Engine3 are not obligated 
to grant this special exception for their modified versions; 
it is their choice whether to do so. The GNU Lesser General Public License 
gives permission to release a modified version without this exception; 
this exception also makes it possible to release a modified version 
which carries forward this exception.
*/

#ifndef ZONESERVERIMPLEMENTATION_H_
#define ZONESERVERIMPLEMENTATION_H_

#include "engine/engine.h"

#include "ZoneProcessServerImplementation.h"

#include "ZonePacketHandler.h"

#include "Zone.h"

#include "managers/object/ObjectManager.h"

class SceneObject;

class UserManager;

class PlayerManager;
class ItemManager;
class GuildManager;

class ChatManager;

#include "ZoneServer.h"

class ZoneServerImplementation : public DatagramServiceThread, public ZoneServerServant {
	BasePacketHandler* phandler;

	ZoneProcessServerImplementation* processor;
	int procThreadCount;

	Vector<Zone*> zones;
	
	ObjectManager* objectManager;

	UserManager* userManager;
	PlayerManager* playerManager;
	ItemManager* itemManager;
	ChatManager* chatManager;
	GuildManager* guildManager;
	
	int totalSentPackets;
	int totalResentPackets;
	
	int currentPlayers;
	int maximumPlayers;
	int totalPlayers;
	
	uint64 nextCreatureID;
	
	string name;

public:
	ZoneServerImplementation(int processingThreads);
	
	~ZoneServerImplementation();
	
	void init();

	void run();
	
	void shutdown();

	ServiceClient* createConnection(Socket* sock, SocketAddress& addr);

	void handleMessage(ServiceClient* client, Packet* message);

	bool handleError(ServiceClient* client, Exception& e);

	// object methods
	void addObject(SceneObject* obj, bool doLock = true);

	SceneObject* getObject(uint64 oid, bool doLock = true);

	SceneObject* removeObject(uint64 oid, bool doLock = true);

	SceneObject* removeCachedObject(uint64 oid, bool doLock = true);

	// server methods
	void addTotalSentPacket(int count);
	void addTotalResentPacket(int count);		

	void printInfo(bool forcedLog = true);
	void printEvents();

	void fixScheduler() {
		scheduler->fixQueue();
	}
	
	void startManagers();

	// user control methods
	bool banUser(string& name, string& admin);

	void changeUserCap(int amount = 50);

	int getConnectionCount();
	
	// setters and getters	
	
	inline string& getServerName() {
		return name;
	}
	
	inline PlayerManager* getPlayerManager() {
		return playerManager;
	}
	
	inline UserManager* getUserManager() {
		return userManager;
	}
	
	inline ItemManager* getItemManager() {
		return itemManager;
	}

	inline ChatManager* getChatManager() {
		return chatManager;
	}

	inline GuildManager* getGuildManager() {
		return guildManager;
	}
	
	inline Zone* getZone(int index) {
		return zones.get(index); 
	}
	
	inline uint64 getNextCreatureID() {
		return nextCreatureID += 0x10;
	}
	
};

#endif /*ZONESERVERIMPLEMENTATION_H_*/
