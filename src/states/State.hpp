#ifndef STATE_HPP
#define STATE_HPP

#include "../entities/troll/Troll.hpp"

template <class entityType> class State {
	public:
		State (void) {};
		virtual ~State (void) {};

		virtual void enter (entityType *) = 0;
		virtual void execute (entityType *) = 0;
		virtual void exit (entityType *) = 0;
};

#endif
