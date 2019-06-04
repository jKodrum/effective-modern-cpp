#include <iostream>
#include <boost/type_index.hpp>
using boost::typeindex::type_id_with_cvr;
using namespace std;

int main()
{
	typedef int&  lref;
	typedef int&& rref;
	int n;

	lref&  r1 = n; // type of r1 is int&
	lref&& r2 = n; // type of r2 is int&
	rref&  r3 = n; // type of r3 is int&
	rref&& r4 = 1; // type of r4 is int&&

	cout << "r1: " << type_id_with_cvr<decltype(r1)>().pretty_name() << endl;
	cout << "r2: " << type_id_with_cvr<decltype(r2)>().pretty_name() << endl;
	cout << "r3: " << type_id_with_cvr<decltype(r3)>().pretty_name() << endl;
	cout << "r4: " << type_id_with_cvr<decltype(r4)>().pretty_name() << endl;

	return 0;
}
