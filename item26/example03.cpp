#include <set>
#include <string>
#include "log.h"

std::multiset<std::string> names;

std::string nameFromIdx(int idx) {
	return "Dragula";
}

template <typename T>
void logAndAdd(T &&str)
{
	logNow("logAndAdd");
	names.emplace(std::forward<T>(str));
}

void logAndAdd(int idx)
{
	logNow("logAndAdd");
	names.emplace(nameFromIdx(idx));
}

int main()
{
	std::string petName("Dragula");

	logAndAdd(petName); // lvalue string, involve copying
	logAndAdd(std::string("Nala")); // rvalue string, exec ctor and dtor
	logAndAdd("Simba"); // string literal
	logAndAdd(22);

	short nameIdx; // same as size_t, short, long
	//logAndAdd(nameIdx); // ERROR
	return 0;
}
