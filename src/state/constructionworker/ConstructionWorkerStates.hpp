#ifndef CONSTRUCTION_WORKER_STATES_H
#define CONSTRUCTION_WORKER_STATES_H

#include "../State.hpp"

class ConstructionWorker;

/* In this state the worker will go to the depot and
 * pick up bricks to deposit at the construction site.
 * If the worker has enough bricks he changes his state
 * to VisitConstructionSiteAndDropBricks. If hungry, he
 * changes state to GoEat.
 */
class GoToDepotAndCollectBricks : public State {
	private:
		GoToDepotAndCollectBricks(void) {};

		GoToDepotAndCollectBricks(const GoToDepotAndCollectBricks&);
		GoToDepotAndCollectBricks& operator=(const GoToDepotAndCollectBricks&);

	public:
		static GoToDepotAndCollectBricks *instance(void);

		virtual void enter(ConstructionWorker *worker);
		virtual void execute(ConstructionWorker *worker);
		virtual void exit(ConstructionWorker *worker);
};

/* Worker will go to the construction site and drop any
 * bricks he is carrying. If enough bricks are contributed
 * the worker will go home, otherwise he'll keep bringing
 * in new bricks.
 */

class VisitConstructionSiteAndDropBricks : public State {
	private:
		VisitConstructionSiteAndDropBricks(void) {};

		VisitConstructionSiteAndDropBricks(const VisitConstructionSiteAndDropBricks&);
		VisitConstructionSiteAndDropBricks& operator=(const VisitConstructionSiteAndDropBricks&);

	public:
		static VisitConstructionSiteAndDropBricks *instance(void);

		virtual void enter(ConstructionWorker *worker);
		virtual void execute(ConstructionWorker *worker);
		virtual void exit(ConstructionWorker *worker);
};

/* Worker will go home and sleep until he is rested enough.
 */
class GoHomeAndSleep : public State {
	private:
		GoHomeAndSleep(void) {};

		GoHomeAndSleep(const GoHomeAndSleep&);
		GoHomeAndSleep& operator=(const GoHomeAndSleep&);

	public:
		static GoHomeAndSleep *instance(void);

		virtual void enter(ConstructionWorker *worker);
		virtual void execute(ConstructionWorker *worker);
		virtual void exit(ConstructionWorker *worker);
};

/* Worker will go and eat something so he wont die.
 */
class GoEat : public State {
	private:
		GoEat(void) {};

		GoEat(const GoEat&);
		GoEat& operator=(const GoEat&);

	public:
		static GoEat *instance(void);

		virtual void enter(ConstructionWorker *worker);
		virtual void execute(ConstructionWorker *worker);
		virtual void exit(ConstructionWorker *worker);
};

#endif
