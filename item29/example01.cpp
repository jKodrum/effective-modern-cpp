#include <cstdio>
#include <vector>
#include <array>

class Widget {
};

int main()
{
	std::vector<Widget> v1(10);
	printf("&v1: %p, &v1[0]: %p\n", &v1, &v1[0]);
	puts("");

	auto v2 = std::move(v1);
	printf("&v1: %p, &v1[0]: %p\n", &v1, &v1[0]);
	printf("&v2: %p, &v2[0]: %p\n", &v2, &v2[0]);
	puts("");

	std::array<Widget, 10> aw1;
	printf("&aw1: %p, &aw1[0]: %p\n", &aw1, &aw1[0]);
	puts("");

	auto aw2 = std::move(aw1);
	printf("&aw1: %p, &aw1[0]: %p\n", &aw1, &aw1[0]);
	printf("&aw2: %p, &aw2[0]: %p\n", &aw2, &aw2[0]);
	puts("");

	std::string ls1 = "this is a long long long string";
	printf("&ls1: %p, &ls1[0]: %p\n", &ls1, &ls1[0]);
	puts("");

	auto ls2 = std::move(ls1);
	printf("&ls1: %p, &ls1[0]: %p\n", &ls1, &ls1[0]);
	printf("&ls2: %p, &ls2[0]: %p\n", &ls2, &ls2[0]);
	puts("");

	std::string ss1 = "short str";
	printf("&ss1: %p, &ss1[0]: %p\n", &ss1, &ss1[0]);
	puts("");

	auto ss2 = std::move(ss1);
	printf("&ss1: %p, &ss1[0]: %p\n", &ss1, &ss1[0]);
	printf("&ss2: %p, &ss2[0]: %p\n", &ss2, &ss2[0]);
	return 0;
}
