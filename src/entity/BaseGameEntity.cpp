#include "BaseGameEntity.hpp"

BaseGameEntity::BaseGameEntity (int id) {
	setID(id);
}

BaseGameEntity::~BaseGameEntity (void) {
}

int BaseGameEntity::ID (void) const {
	return m_ID;
}
