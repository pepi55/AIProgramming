#ifndef ENTITY_H
#define ENTITY_H

class BaseGameEntity {
	private:
		int m_ID;
		static int m_nextValidID;

		void setID(int value);

	public:
		BaseGameEntity(int id) {
			setID(id);
		}

		virtual ~BaseGameEntity(void) {}
		virtual void update(void) = 0;

		int ID(void) const {
			return m_ID;
		}
};

#endif
