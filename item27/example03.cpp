#include <string>
#define CONDITION true

std::string nameFromIdx(int idx) {
	return "Dragula";
}

class Person {
public:
	template <
		typename T,
		typename = typename std::enable_if<CONDITION>::type
	>
	explicit Person(T &&n) : name(std::forward<T>(n)) {}

	explicit Person(int idx) : name(nameFromIdx(idx)) {}

private:
	std::string name;
};

int main()
{
	Person p("Alphonse");
	const Person cp("Alphonse");

	//auto cloneOfP(p); // ERROR
	auto cloneOfCp(cp);
	return 0;
}
