#include <set>
#include <string>
#include <type_traits>
#include "log.h"

std::multiset<std::string> names;

std::string nameFromIdx(int idx) {
	return "Dragula";
}

// Defined in header <type_traits>
// std::integral_constant<bool, false>
template <typename T>
void logAndAddImpl(T&&, std::false_type);

// std::integral_constant<bool, true>
void logAndAddImpl(int, std::true_type);

template <typename T>
void logAndAdd(T &&str)
{
	logAndAddImpl(std::forward<T>(str),
			std::is_integral<
				typename std::remove_reference<T>::type
			>());
}

template <typename T>
void logAndAddImpl(T &&str, std::false_type)
{
	logNow("logAndAdd");
	names.emplace(std::forward<T>(str));
}

void logAndAddImpl(int idx, std::true_type)
{
	logAndAdd(nameFromIdx(idx));
}

int main()
{
	std::string petName("Dragula");

	logAndAdd(petName); // lvalue string, involve copying
	logAndAdd(std::string("Nala")); // rvalue string, involve copying
	logAndAdd("Simba"); // string literal
	logAndAdd(22);

	short nameIdx; // same as size_t, short, long
	logAndAdd(nameIdx); // ERROR

	return 0;
}
