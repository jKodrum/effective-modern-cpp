#include <chrono>
#include <cstdio>

#define logNow(x) {\
	auto now = time(0); \
	auto t = localtime(&now); \
	printf("[%04d%02d%02d-%02d:%02d:%02d]: %s\n", \
			1900 + t->tm_year, \
			1 + t->tm_mon, \
			t->tm_mday, \
			t->tm_hour, \
			t->tm_min, \
			t->tm_sec, \
			x \
	); \
}
