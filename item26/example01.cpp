#include <iostream>
#include <chrono>
#include <set>
#include <string>

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

std::multiset<std::string> names;

void logAndAdd(const std::string &name)
{
	logNow("logAndAdd");
	names.emplace(name);
}

int main()
{
	std::string petName("Dragula");

	logAndAdd(petName);
	logAndAdd(std::string("Nala"));
	logAndAdd("Simba");
	return 0;
}
