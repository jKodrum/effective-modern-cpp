#include <iostream>
#include <set>
#include <string>
#include "log.h"

std::multiset<std::string> names;

void logAndAdd(const std::string &str)
{
	logNow("logAndAdd");
	names.emplace(str);
}

int main()
{
	std::string petName("Dragula");

	logAndAdd(petName); // lvalue string, involve copying
	logAndAdd(std::string("Nala")); // rvalue string, involve copying
	logAndAdd("Simba"); // string literal, involve copying
	return 0;
}
