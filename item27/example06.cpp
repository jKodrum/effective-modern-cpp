#include <string>

std::string nameFromIdx(int idx) {
	return "Dragula";
}

class Person {
public:
	explicit Person(std::string n) : name(std::move(n)) {}

	explicit Person(int idx) : name(nameFromIdx(idx)) {}

private:
	std::string name;
};

int main()
{
	std::string name = "FaDaTsai";
	char ch[] = "Timon";
	char *pch = ch;

	Person p1(name);
	Person p2(std::string("Mufasa"));
	Person p3("Herry");
	Person p4(ch);
	Person p5(pch);

	int i = 7;
	short s = 8;
	size_t u = 9;
	long l = 10;

	Person p6(6);
	Person p7(i);
	Person p8(s);
	Person p9(u);
	Person p10(l);

	return 0;
}
