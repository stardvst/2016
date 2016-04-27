#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

void customNewHandler() {
	cerr << "customNewHandler was called";
	abort();
}

int main() {
	
	double *ptr[50];

	set_new_handler(customNewHandler);

		for (int i = 0; i < 50; ++i) {
			ptr[i] = new double[50000000];
			cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
		}
	


	cin.get();
	return 0;
}