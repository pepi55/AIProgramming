#ifndef MESSAGE_MANAGER_HPP
#define MESSAGE_MANAGER_HPP

#include <set>

#include "Telegram.hpp"

class BaseGameEntity;

class MessageManager {
	public:
	private:
		std::set<Telegram> priorityQ;
};

#endif
