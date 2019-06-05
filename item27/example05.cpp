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
		>::type
	>
	explicit Person(T &&n) : name(std::forward<T>(n)) {}

	explicit Person(int idx) : name(nameFromIdx(idx)) {}

private:
	std::string name;
};

class SpecialPerson : public Person {
	SpecialPerson(const SpecialPerson &rhs)
		: Person(rhs) { }

	SpecialPerson(SpecialPerson &&rhs)
		: Person(std::move(rhs)) { }
};

int main()
{
	Person p("Alphonse");
	const Person cp("Alphonse");

	auto cloneOfP(p);
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
