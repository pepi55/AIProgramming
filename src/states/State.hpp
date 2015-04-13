#ifndef STATE_HPP
#define STATE_HPP

#include "../entities/Troll.hpp"

class Troll;

class State {
	public:
		State(void) {};
		//virtual ~State(void) = 0;

		virtual void execute(Troll *troll) = 0;
};

#endif
