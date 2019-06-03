#include <iostream>
#include <set>
#include <string>
#include <typeinfo>
#include "log.h"

std::multiset<std::string> names;

template <typename T>
void logAndAdd(T &&str)
{
	logNow("logAndAdd");
	std::cout << typeid(str).name() << std::endl;
	std::cout << typeid(std::forward<T>(str)).name() << std::endl;
	names.emplace(std::forward<T>(str));
}

int main()
{
	std::string petName("Dragula");

	logAndAdd(petName); // lvalue string, involve copying
	logAndAdd(std::string("Nala")); // rvalue string, involve copying
	logAndAdd("Simba"); // string literal
	return 0;
}
