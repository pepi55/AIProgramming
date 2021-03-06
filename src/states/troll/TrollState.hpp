#ifndef TROLL_STATE_HPP
#define TROLL_STATE_HPP

#include "../State.hpp"

class Troll;

class GlobalTrollState : public State<Troll> {
	public:
		GlobalTrollState (void);
		GlobalTrollState (const GlobalTrollState &ctor);
		~GlobalTrollState (void);

		void enter (Troll *troll);
		void execute (Troll *troll);
		void exit (Troll *troll);
};

class TrollStateHunt : public State<Troll> {
	public:
		TrollStateHunt (void);
		TrollStateHunt (const TrollStateHunt &ctor);
		~TrollStateHunt (void);

		void enter (Troll *troll);
		void execute (Troll *troll);
		void exit (Troll *troll);
};

class TrollStatePeaceful : public State<Troll> {
	public:
		TrollStatePeaceful (void);
		TrollStatePeaceful (const TrollStatePeaceful &ctor);
		~TrollStatePeaceful (void);

		void enter (Troll *troll);
		void execute (Troll *troll);
		void exit (Troll *troll);
};

#endif
