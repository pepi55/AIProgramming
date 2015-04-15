#ifndef STATE_HPP
#define STATE_HPP

#include "../entities/troll/Troll.hpp"

class Troll;

class State {
	public:
		State (void) {};
		virtual ~State (void) {};

		virtual void enter (Troll *) = 0;
		virtual void execute (Troll *) = 0;
		virtual void exit (Troll *) = 0;
};

#endif
