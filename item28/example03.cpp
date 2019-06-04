#include <iostream>
#include <boost/type_index.hpp>

class Widget {
};

int main()
{
	using boost::typeindex::type_id_with_cvr;
	using namespace std;
	Widget w;

	// T& && => T&
	auto&& w1 = w;
	cout << "w1: " << type_id_with_cvr<decltype(w1)>().pretty_name() << endl;

	// No reference collapsing occurring
	auto&& w2 = Widget();
	cout << "w2: " << type_id_with_cvr<decltype(w2)>().pretty_name() << endl;
	return 0;
}
