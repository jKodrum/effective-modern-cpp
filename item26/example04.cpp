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

int main()
{
	Person p("Alphonse");
	//auto cloneOfP(p); // ERROR (non-const var taken by template ctor)

	const Person cp("Alphonse");
	auto cloneOfCp(cp);
	return 0;
}
