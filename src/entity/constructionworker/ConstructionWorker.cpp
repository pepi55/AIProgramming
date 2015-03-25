#include "ConstructionWorker.hpp"
#include "../../state/constructionworker/ConstructionWorkerStates.hpp"

ConstructionWorker::ConstructionWorker(int id) : BaseGameEntity(id),
	m_current_state(GoHomeAndSleep::instance()),
	m_location(HOME),
	m_bricks_carried(0),
	m_bricks_contributed(0),
	m_hunger(0),
	m_fatigue(0) {
}

void ConstructionWorker::changeState(State *new_state) {
	assert(m_current_state && new_state);

	m_current_state->exit(this);
	m_current_state = new_state;
	m_current_state->enter(this);
}

void ConstructionWorker::addToBricksCarried(const int val) {
	m_bricks_carried += val;

	if (m_bricks_carried < 0) m_bricks_carried = 0;
}

void ConstructionWorker::addToBricksContributed(const int val) {
	m_bricks_contributed += val;

	if (m_bricks_contributed < 0) m_bricks_contributed = 0;
}

bool ConstructionWorker::hungry(void) const {
	if (m_hunger >= ConstWorkerHungerLvl) return true;

	return false;
}

void ConstructionWorker::update(void) {
	m_hunger += 1;

	if (m_current_state) {
		m_current_state->execute(this);
	}
}

bool ConstructionWorker::tired(void) const {
	if (m_fatigue > ConstWorkerExhaustionThreshold) return true;

	return false;
}

location_type ConstructionWorker::getLocation(void) const {
	return m_location;
}

void ConstructionWorker::changeLocation(const location_type loc) {
	m_location = loc;
}

int ConstructionWorker::getBricksCarried(void) const {
	return m_bricks_carried;
}

void ConstructionWorker::setBricksCarried(const int val) {
	m_bricks_carried = val;
}

bool ConstructionWorker::handsFull(void) const {
	return m_bricks_carried >= ConstWorkerMaxBricks;
}

void ConstructionWorker::increaseFatigue(int value) {
	m_fatigue += value;
}

void ConstructionWorker::decreaseFatigue(int value) {
	m_fatigue -= value;
}

int ConstructionWorker::bricksContributed(void) const {
	return m_bricks_contributed;
}

void ConstructionWorker::setBricksContributed(const int val) {
	m_bricks_contributed = val;
}

void ConstructionWorker::buyAndEatFood(void) {
	m_hunger = 0;
	//m_bricks_contributed -= 2;
}
