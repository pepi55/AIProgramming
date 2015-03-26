#ifndef STATE_H
#define STATE_H

class ConstructionWorker;

class State {
	public:
		State(void) {}
		virtual ~State(void) {}

		//Execute when entering a new state
		virtual void enter(ConstructionWorker*) = 0;
		//Update function for the state
		virtual void execute(ConstructionWorker*) = 0;
		//Execute when leaving current state
		virtual void exit(ConstructionWorker*) = 0;
};

#endif
