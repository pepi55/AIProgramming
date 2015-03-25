#ifndef ENTITY_NAMES_H
#define ENTITY_NAMES_H

#include <string>

enum {
	ent_construction_worker_Bob,
	ent_Elsa
};

inline std::string GetNameOfEntity(int n) {
	switch (n) {
		case ent_construction_worker_Bob:
			return "Construction worker Bob";
			break;

		case ent_Elsa:
			return "Elsa";
			break;

		default:
			return "Unknown";
			break;
	}
}

#endif
