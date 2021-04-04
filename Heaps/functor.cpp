#include <bits/stdc++.h>
using namespace std;

class Fun {

public:
	void operator()(string s) {
		cout << "Having fun with " << s;
	}
};

int main() {

	Fun f; //constructor
	f("C++"); //Overloaded () operator = Function call where f is an object

	/*
	Here f is an object but behaving as a function call.
	Therefore it is called functor - Functional object in c++
	*/

	return 0;
}