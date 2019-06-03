#include <iostream>
#include <string>

std::string nameFromIdx(int idx) {
	return "Dragula";
}

class Person {
public:
	// perfect forwarding ctor
	template <typename T>
	explicit Person(T &&n) : name(std::forward<T>(n)) {}

	explicit Person(int idx) : name(nameFromIdx(idx)) {}

	// Person(const Person &rhs); // compiler-gen

	// Person(Person &&rhs); // compiler-gen

private:
	std::string name;
};

class SpecialPerson: public Person {
public:
	// ERROR, calling Person's perfect forwarding ctor
	//SpecialPerson(const SpecialPerson &rhs) : Person(rhs) {};

	// ERROR, calling Person's perfect forwarding ctor
	//SpecialPerson(SpecialPerson &&rhs) : Person(std::move(rhs)) {};
};

int main()
{
	return 0;
}
