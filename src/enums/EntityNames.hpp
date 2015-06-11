#ifndef ENTITY_NAMES_HPP
#define ENTITY_NAMES_HPP

#include <string>

enum Entities {
	EDGAR,
	HELLEN
};

inline std::string getEntityName (int name) {
	switch (name) {
		case EDGAR:
			return "Edgar";

		case HELLEN:
			return "Hellen";

		default:
			return "Unknown";
	}
}

#endif
