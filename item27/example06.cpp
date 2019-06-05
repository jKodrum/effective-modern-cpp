#include <string>

std::string nameFromIdx(int idx) {
	return "Dragula";
}

class Person {
public:
	template <
		typename T,
		typename = typename std::enable_if<
			!std::is_base_of<Person,
				typename std::decay<T>::type
			>::value
			&&
			!std::is_integral<
				typename std::remove_reference<T>::type
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

	int i = 1;
	Person p1(i);

	short s = 2;
	Person p2(s);

	size_t u = 3;
	Person p3(u);

	long l = l;
	Person p4(l);
	return 0;
}
