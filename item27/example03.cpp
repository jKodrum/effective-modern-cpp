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
	//auto cloneOfP(p); // ERROR (non-const var taken by template ctor)

	const Person cp("Alphonse");
	auto cloneOfCp(cp);

	int i = 1;
	Person p1(i);

	/* // ERRROR
	short s = 2;
	Person p2(s);

	size_t u = 3;
	Person p3(u);

	long l = l;
	Person p4(l);
	*/
	return 0;
}
