#include <typeinfo>
#include "StateMachine.hpp"

template <class entityType> StateMachine<entityType>::StateMachine(entityType *owner) : mOwner(owner), mCurrentState(NULL), mPreviousState(NULL), mGlobalState(NULL) {
}

template <class entityType> StateMachine<entityType>::~StateMachine(void) {
	delete mOwner, mCurrentState, mPreviousState, mGlobalState;
}

template <class entityType> void StateMachine<entityType>::setCurrentState(State<entityType> *state) {
	mCurrentState = state;
}

template <class entityType> void StateMachine<entityType>::setPreviousState(State<entityType> *state) {
	mPreviousState = state;
}

template <class entityType> void StateMachine<entityType>::setGlobalState(State<entityType> *state) {
	mGlobalState = state;
}

template <class entityType> State<entityType> *StateMachine<entityType>::getCurrentState(void) const {
	return mCurrentState;
}

template <class entityType> State<entityType> *StateMachine<entityType>::getPreviousState(void) const {
	return mPreviousState;
}

template <class entityType> State<entityType> *StateMachine<entityType>::getGlobalState(void) const {
	return mGlobalState;
}

template <class entityType> void StateMachine<entityType>::update(void) const {
	if (mGlobalState) {
		mGlobalState->execute(mOwner);
	}

	if (mCurrentState) {
		mCurrentState->execute(mOwner);
	}
}

template <class entityType> void StateMachine<entityType>::changeState(State<entityType> *newState) {
	if (newState == NULL) {
		fprintf(stderr, "%s\n", "Changing to a NULL state!");
	} else {
		mPreviousState = mCurrentState;
		mCurrentState->exit(mOwner);
		mCurrentState = newState;
		mCurrentState->enter(mOwner);
	}
}

template <class entityType> void StateMachine<entityType>::revertState(void) {
	changeState(mPreviousState);
}

template <class entityType> bool StateMachine<entityType>::isInState(const State<entityType> &state) const {
	if (typeid(*mCurrentState) == typeid(state)) {
		return true;
	} else {
		return false;
	}
}
