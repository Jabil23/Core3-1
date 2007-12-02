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
 *	server/zone/objects/tangible/weapons/Weapon.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../../scene/SceneObject.h"

#include "../../player/Player.h"

#include "../TangibleObject.h"

#include "Weapon.h"

#include "WeaponImplementation.h"

/*
 *	WeaponStub
 */

Weapon::Weapon() : TangibleObject(NULL) {
}

Weapon::Weapon(ORBObjectServant* obj) : TangibleObject(obj) {
}

void Weapon::sendTo(Player* player, bool doClose) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);
		invocation.addObjectParameter(player);
		invocation.addBooleanParameter(doClose);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->sendTo(player, doClose);
}

void Weapon::generateAttributes(SceneObject* obj) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addObjectParameter(obj);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->generateAttributes(obj);
}

int Weapon::getType() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getType();
}

int Weapon::getCategory() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getCategory();
}

bool Weapon::isJedi() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->isJedi();
}

bool Weapon::isMelee() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->isMelee();
}

bool Weapon::isRanged() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->isRanged();
}

float Weapon::getMinDamage() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 13);

		return invocation.executeWithFloatReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMinDamage();
}

float Weapon::getMaxDamage() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 14);

		return invocation.executeWithFloatReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMaxDamage();
}

float Weapon::getAttackSpeed() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 15);

		return invocation.executeWithFloatReturn();
	} else
		return ((WeaponImplementation*) _impl)->getAttackSpeed();
}

int Weapon::getHealthAttackCost() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 16);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getHealthAttackCost();
}

int Weapon::getActionAttackCost() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 17);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getActionAttackCost();
}

int Weapon::getMindAttackCost() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 18);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMindAttackCost();
}

int Weapon::getPointBlankRange() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 19);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getPointBlankRange();
}

int Weapon::getPointBlankAccuracy() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 20);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getPointBlankAccuracy();
}

int Weapon::getMaxRange() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 21);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMaxRange();
}

int Weapon::getMaxRangeAccuracy() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 22);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMaxRangeAccuracy();
}

int Weapon::getIdealRange() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 23);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getIdealRange();
}

int Weapon::getIdealAccuracy() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 24);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getIdealAccuracy();
}

int Weapon::getWoundsRatio() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 25);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getWoundsRatio();
}

/*
 *	WeaponAdapter
 */

WeaponAdapter::WeaponAdapter(WeaponImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* WeaponAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendTo((Player*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 7:
		generateAttributes((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		resp->insertSignedInt(getType());
		break;
	case 9:
		resp->insertSignedInt(getCategory());
		break;
	case 10:
		resp->insertBoolean(isJedi());
		break;
	case 11:
		resp->insertBoolean(isMelee());
		break;
	case 12:
		resp->insertBoolean(isRanged());
		break;
	case 13:
		resp->insertFloat(getMinDamage());
		break;
	case 14:
		resp->insertFloat(getMaxDamage());
		break;
	case 15:
		resp->insertFloat(getAttackSpeed());
		break;
	case 16:
		resp->insertSignedInt(getHealthAttackCost());
		break;
	case 17:
		resp->insertSignedInt(getActionAttackCost());
		break;
	case 18:
		resp->insertSignedInt(getMindAttackCost());
		break;
	case 19:
		resp->insertSignedInt(getPointBlankRange());
		break;
	case 20:
		resp->insertSignedInt(getPointBlankAccuracy());
		break;
	case 21:
		resp->insertSignedInt(getMaxRange());
		break;
	case 22:
		resp->insertSignedInt(getMaxRangeAccuracy());
		break;
	case 23:
		resp->insertSignedInt(getIdealRange());
		break;
	case 24:
		resp->insertSignedInt(getIdealAccuracy());
		break;
	case 25:
		resp->insertSignedInt(getWoundsRatio());
		break;
	default:
		return NULL;
	}

	return resp;
}

void WeaponAdapter::sendTo(Player* player, bool doClose) {
	return ((WeaponImplementation*) impl)->sendTo(player, doClose);
}

void WeaponAdapter::generateAttributes(SceneObject* obj) {
	return ((WeaponImplementation*) impl)->generateAttributes(obj);
}

int WeaponAdapter::getType() {
	return ((WeaponImplementation*) impl)->getType();
}

int WeaponAdapter::getCategory() {
	return ((WeaponImplementation*) impl)->getCategory();
}

bool WeaponAdapter::isJedi() {
	return ((WeaponImplementation*) impl)->isJedi();
}

bool WeaponAdapter::isMelee() {
	return ((WeaponImplementation*) impl)->isMelee();
}

bool WeaponAdapter::isRanged() {
	return ((WeaponImplementation*) impl)->isRanged();
}

float WeaponAdapter::getMinDamage() {
	return ((WeaponImplementation*) impl)->getMinDamage();
}

float WeaponAdapter::getMaxDamage() {
	return ((WeaponImplementation*) impl)->getMaxDamage();
}

float WeaponAdapter::getAttackSpeed() {
	return ((WeaponImplementation*) impl)->getAttackSpeed();
}

int WeaponAdapter::getHealthAttackCost() {
	return ((WeaponImplementation*) impl)->getHealthAttackCost();
}

int WeaponAdapter::getActionAttackCost() {
	return ((WeaponImplementation*) impl)->getActionAttackCost();
}

int WeaponAdapter::getMindAttackCost() {
	return ((WeaponImplementation*) impl)->getMindAttackCost();
}

int WeaponAdapter::getPointBlankRange() {
	return ((WeaponImplementation*) impl)->getPointBlankRange();
}

int WeaponAdapter::getPointBlankAccuracy() {
	return ((WeaponImplementation*) impl)->getPointBlankAccuracy();
}

int WeaponAdapter::getMaxRange() {
	return ((WeaponImplementation*) impl)->getMaxRange();
}

int WeaponAdapter::getMaxRangeAccuracy() {
	return ((WeaponImplementation*) impl)->getMaxRangeAccuracy();
}

int WeaponAdapter::getIdealRange() {
	return ((WeaponImplementation*) impl)->getIdealRange();
}

int WeaponAdapter::getIdealAccuracy() {
	return ((WeaponImplementation*) impl)->getIdealAccuracy();
}

int WeaponAdapter::getWoundsRatio() {
	return ((WeaponImplementation*) impl)->getWoundsRatio();
}

/*
 *	WeaponHelper
 */

ORBClassHelper* WeaponHelper::instance = new WeaponHelper();

WeaponHelper::WeaponHelper() {
	className = "Weapon";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

ORBClassHelper* WeaponHelper::getInstance() {
	if (instance == NULL)
		return instance = new WeaponHelper();
	else
		return instance;
}

ORBObject* WeaponHelper::instantiateObject() {
	return new Weapon();
}

ORBObjectAdapter* WeaponHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new WeaponAdapter((WeaponImplementation*)obj);

	ORBObjectStub* stub = new Weapon(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	WeaponServant
 */

WeaponServant::WeaponServant(unsigned long long oid, int tp) : TangibleObjectImplementation(oid, tp) {
	_classHelper = WeaponHelper::getInstance();
}

WeaponServant::WeaponServant(unsigned long long oid, const unicode& name, const string& tempname, unsigned int tempcrc, int tp) : TangibleObjectImplementation(oid, name, tempname, tempcrc, tp) {
	_classHelper = WeaponHelper::getInstance();
}

WeaponServant::~WeaponServant() {
}
void WeaponServant::_setStub(ORBObjectStub* stub) {
	_this = (Weapon*) stub;
	TangibleObjectServant::_setStub(stub);
}

ORBObjectStub* WeaponServant::_getStub() {
	return _this;
}

