#include <stdio.h>

/*

void main()
{

	int x = 3;
	foo(x);



}


 foo(int a) {
	int b = 1;
	printf(" % d\n", bar(a) + b);
}


int bar(int z) {
	if (z > 0)
		return bar(z - 1) + 1;
	else
		return dummy();
}

int dummy() {
	int c = 1;
		return c;
}




*/



void main() {
	int x = 5, y = 0;
	foo(x, y);
}

foo(int a, int b){
	int c;
	c = bar(a, b);

}

int bar( f, g) {
	if (f > g)
		return bar(f - 1, g + 1) + 1;
	else 
		return last(f, g);
}

int last(int m, int n) {
	int d = m + n;
	return d;
}
