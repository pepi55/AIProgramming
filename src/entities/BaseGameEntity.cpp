#include "BaseGameEntity.hpp"

int BaseGameEntity::mNextValidID = 0;

BaseGameEntity::BaseGameEntity(int id) {
	setID(id);
}

BaseGameEntity::~BaseGameEntity(void) {
}

void BaseGameEntity::setID(int value) {
	if (value >= mNextValidID) {
		mID = value;

		mNextValidID = mID + 1;
	}
}
