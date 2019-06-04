#include <iostream>
#include <boost/type_index.hpp>

class Widget {
};

template <typename T>
void func(T &&param)
{
	using namespace std;
	using boost::typeindex::type_id_with_cvr;
	
	cout << "T: " << type_id_with_cvr<T>().pretty_name() << endl;
	cout << "param: " << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

int main()
{
	Widget w;

	auto &lref = w;
	auto &&rref = Widget();
	// auto & &ref_to_ref = Widget(); // ERROR

	func(w);
	std::cout << std::endl;
	func(Widget());
	return 0;
}
