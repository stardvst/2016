#include <stdio.h>
#include <limits.h>
#include <math.h> 

int maxint(int i) {
	if (i >= INT_MAX) {
		throw "i > MAXINT";
	}
	return i;
}

float div1(float x, float y) {
	if (y == 0) {
		throw "Error: float y = 0";
	}
	return x / y;
}

float div2(float x, float y) {
	if (y == INFINITY) {
		throw "Error: y = INF";
	}
	return x / y;
}

float div3(int x, int y) {
	if (y == 0) {
		throw "Error: int y = 0";
	}
	return (float)x / y;
}

int main() {

	try {
		int a = maxint(INT_MAX);
	}
	catch (const char *msg) {
		printf("%s\n\n", msg);
	}



	try {
		int b = div1(5.0, 0);
	}
	catch (const char *msg) {
		printf("%s\n\n", msg);
	}



	try {
		int c = div2(5.0, INFINITY);
	}
	catch (const char *msg) {
		printf("%s\n\n", msg);
	}


	try {
		int d = div3(5, 0);
	}
	catch (const char *msg) {
		printf("%s\n\n", msg);
	}


	return 0;
}