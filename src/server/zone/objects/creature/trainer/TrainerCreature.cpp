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

/*
 *	server/zone/objects/creature/trainer/TrainerCreature.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../Creature.h"

#include "../../player/Player.h"

#include "../../scene/SceneObject.h"

#include "TrainerCreature.h"

#include "TrainerCreatureImplementation.h"

/*
 *	TrainerCreatureStub
 */

TrainerCreature::TrainerCreature() : Creature(NULL) {
}

TrainerCreature::TrainerCreature(ORBObjectServant* obj) : Creature(obj) {
}

void TrainerCreature::sendConversationStartTo(SceneObject* obj) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);
		invocation.addObjectParameter(obj);

		invocation.executeWithVoidReturn();
	} else
		((TrainerCreatureImplementation*) _impl)->sendConversationStartTo(obj);
}

void TrainerCreature::sendSkillBoxes(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((TrainerCreatureImplementation*) _impl)->sendSkillBoxes(player);
}

void TrainerCreature::selectConversationOption(int option, SceneObject* obj) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);
		invocation.addSignedIntParameter(option);
		invocation.addObjectParameter(obj);

		invocation.executeWithVoidReturn();
	} else
		((TrainerCreatureImplementation*) _impl)->selectConversationOption(option, obj);
}

/*
 *	TrainerCreatureAdapter
 */

TrainerCreatureAdapter::TrainerCreatureAdapter(TrainerCreatureImplementation* obj) : CreatureAdapter(obj) {
}

Packet* TrainerCreatureAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendConversationStartTo((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		sendSkillBoxes((Player*) inv->getObjectParameter());
		break;
	case 8:
		selectConversationOption(inv->getSignedIntParameter(), (SceneObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void TrainerCreatureAdapter::sendConversationStartTo(SceneObject* obj) {
	return ((TrainerCreatureImplementation*) impl)->sendConversationStartTo(obj);
}

void TrainerCreatureAdapter::sendSkillBoxes(Player* player) {
	return ((TrainerCreatureImplementation*) impl)->sendSkillBoxes(player);
}

void TrainerCreatureAdapter::selectConversationOption(int option, SceneObject* obj) {
	return ((TrainerCreatureImplementation*) impl)->selectConversationOption(option, obj);
}

/*
 *	TrainerCreatureHelper
 */

ORBClassHelper* TrainerCreatureHelper::instance = new TrainerCreatureHelper();

TrainerCreatureHelper::TrainerCreatureHelper() {
	className = "TrainerCreature";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

ORBClassHelper* TrainerCreatureHelper::getInstance() {
	if (instance == NULL)
		return instance = new TrainerCreatureHelper();
	else
		return instance;
}

ORBObject* TrainerCreatureHelper::instantiateObject() {
	return new TrainerCreature();
}

ORBObjectAdapter* TrainerCreatureHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new TrainerCreatureAdapter((TrainerCreatureImplementation*)obj);

	ORBObjectStub* stub = new TrainerCreature(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	TrainerCreatureServant
 */

TrainerCreatureServant::TrainerCreatureServant(unsigned long long oid) : CreatureImplementation(oid) {
	_classHelper = TrainerCreatureHelper::getInstance();
}

TrainerCreatureServant::~TrainerCreatureServant() {
}
void TrainerCreatureServant::_setStub(ORBObjectStub* stub) {
	_this = (TrainerCreature*) stub;
	CreatureServant::_setStub(stub);
}

ORBObjectStub* TrainerCreatureServant::_getStub() {
	return _this;
}

