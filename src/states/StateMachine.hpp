#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <string.h>

#include "State.hpp"
#include "../messages/Telegram.hpp"

template <class entityType> class StateMachine {
	public:
		StateMachine (entityType *owner);
		~StateMachine (void);

		//Use this to initialize the StateMachine
		void setCurrentState (State<entityType> *state);
		void setPreviousState (State<entityType> *state);
		void setGlobalState (State<entityType> *state);

		State<entityType> *getCurrentState (void) const;
		State<entityType> *getPreviousState (void) const;
		State<entityType> *getGlobalState (void) const;

		void update (void) const;
		void changeState (State<entityType> *newState);
		void revertState (void);

		bool isInState (const State<entityType> &state) const;

	private:
		entityType *mOwner;

		State<entityType> *mCurrentState;
		State<entityType> *mPreviousState;
		State<entityType> *mGlobalState;
};

#endif
