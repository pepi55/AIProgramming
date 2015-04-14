#ifndef STATE_HPP
#define STATE_HPP

#include "../entities/troll/Troll.hpp"

class Troll;

class State {
	public:
		State (void) {};
		virtual ~State (void) {};

		virtual void execute (Troll *troll) = 0;
};

#endif
