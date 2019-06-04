#include <string>

std::string nameFromIdx(int idx) {
	return "Dragula";
}

class Person {
public:
	template <
		typename T,
		typename = typename std::enable_if<
			!std::is_same<Person,
				typename std::decay<T>::type
			>::value
		>::type
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

	auto cloneOfP(p);
	auto cloneOfCp(cp);
	return 0;
}
