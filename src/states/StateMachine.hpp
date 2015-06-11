#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <string.h>
#include <typeinfo>

#include "State.hpp"
#include "../messages/Telegram.hpp"

template <class entityType> class StateMachine {
	public:
		StateMachine (entityType *owner) : mOwner(owner), mCurrentState(NULL), mPreviousState(NULL), mGlobalState(NULL) {
		}

		~StateMachine (void) {
			delete mOwner,
						 mCurrentState,
						 mPreviousState,
						 mGlobalState;
		}

		//Use this to initialize the StateMachine
		void setCurrentState (State<entityType> *state) {
			mCurrentState = state;
		}

		void setPreviousState (State<entityType> *state) {
			mPreviousState = state;
		}

		void setGlobalState (State<entityType> *state) {
			mGlobalState = state;
		}

		State<entityType> *getCurrentState (void) const {
			return mCurrentState;
		}

		State<entityType> *getPreviousState (void) const {
			return mPreviousState;
		}

		State<entityType> *getGlobalState (void) const {
			return mGlobalState;
		}

		void update (void) const {
			//Remember to assign Global state on object creation!
			if (mGlobalState) {
				mGlobalState->execute(mOwner);
			}

			//Remember to assign Current state on object creation!
			if (mCurrentState) {
				mCurrentState->execute(mOwner);
			}
		}

		void changeState (State<entityType> *newState) {
			if (newState == NULL) {
				fprintf(stderr, "%s\n", "Changing to a NULL state!");
			} else {
				mPreviousState = mCurrentState;
				mCurrentState->exit(mOwner);

				mCurrentState = newState;
				mCurrentState->enter(mOwner);
			}
		}

		void revertState (void) {
			changeState(mPreviousState);
		}

		//Returns true if parameter is equal to the current state
		bool isInState (const State<entityType> &state) const {
			return typeid(*mCurrentState) == typeid(state);
		}

	private:
		entityType *mOwner;

		State<entityType> *mCurrentState;
		State<entityType> *mPreviousState;
		State<entityType> *mGlobalState;
};

#endif
