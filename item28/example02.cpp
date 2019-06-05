#include <iostream>

class Widget {
};

template <typename T>
T &&myForward(typename std::remove_reference<T>::type&);

template <typename T>
void func(T &&param)
{
	someFunc(myForward<T>(param));
}

void someFunc(const Widget &w)
{
	std::cout << "lvalue" << std::endl;
}

void someFunc(Widget &&w)
{
	std::cout << "rvalue" << std::endl;
}

template <typename T>
T &&myForward(typename std::remove_reference<T>::type& param)
{
	return static_cast<T&&>(param);
}

int main()
{
	Widget w;

	/** Widget& &&  -->  Widget&
	 * Widget& &&myForward(typename std::remove_reference<Widget&>::type& param)
	 * { return static_cast<Widget& &&>(param); }
	 *
	 * Widget& myForward(Widget &param)
	 * { return static_cast<Widget&>(param); }
	 */
	func(w);

	/** No reference collapsing occurring
	 * Widget &&myForward(typename std::remove_reference<Widget>::type& param)
	 * { return static_cast<Widget &&>(param); }
	 *
	 * Widget &&myForward(Widget &param)
	 * { return static_cast<Widget&&>(param); }
	 */
	func(Widget());
	return 0;
}
