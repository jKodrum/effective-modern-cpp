#include <iostream>
#include <set>
#include <string>
#include <boost/type_index.hpp>
#include "log.h"

std::multiset<std::string> names;

template <typename T>
void logAndAdd(T &&str)
{
	using boost::typeindex::type_id_with_cvr;

	logNow("logAndAdd");
	std::cout << "T: " << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "str: " << type_id_with_cvr<decltype(str)>().pretty_name() << std::endl;
	std::cout << std::endl;
	names.emplace(std::forward<T>(str));
}

int main()
{
	std::string petName("Dragula");

	logAndAdd(petName); // lvalue string, involve copying
	logAndAdd(std::string("Nala")); // rvalue string, exec ctor and dtor
	logAndAdd("Simba"); // string literal
	return 0;
}
