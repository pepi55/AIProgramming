#ifndef BASE_GAME_ENTITY_HPP
#define BASE_GAME_ENTITY_HPP

class BaseGameEntity {
	public:
		BaseGameEntity (int id);
		virtual ~BaseGameEntity (void);

		virtual void update (void) = 0;

		int getID (void) const;

	private:
		int mID;
		static int mNextValidID;
		void setID (int value);
};

#endif
