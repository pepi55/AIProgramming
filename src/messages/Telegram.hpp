#ifndef TELEGRAM_HPP
#define TELEGRAM_HPP

#include <stdio.h>

const double minDelay = 0.25;

struct Telegram {
	int sender,
			reciever,
			message;

	double delay;

	void *extraInfo;

	Telegram (void) : sender(0), reciever(0), message(0), delay(0) {
	}

	Telegram (int sender, int reciever, int msg, double time, void* info = NULL) : sender(sender), reciever(reciever), message(msg), delay(time), extraInfo(info) {
	}
};

template<class T>
inline T dereferenceToType (void *p) {
	return *(T*)(p);
}

#endif
