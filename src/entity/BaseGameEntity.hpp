#ifndef ENTITY_H
#define ENTITY_H

class BaseGameEntity {
	private:
		int m_ID;
		static int m_next_valid_ID;

		//Check if the ID is valid; if so, set it to the next valid
		//ID and increment the next valid ID.
		void setID(int value);

	public:
		BaseGameEntity(int id);
		virtual ~BaseGameEntity(void);

		//All entities require an update();
		virtual void update(void) = 0;

		int ID(void) const;
};

#endif
