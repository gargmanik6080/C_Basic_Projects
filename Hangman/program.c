#include <stdio.h>
#include <assert.h>
int replacebits(int n){
	int evenmask = 0b1010101010101010;
	int oddmask  = 0b0101010101010101;
	int oddbits = n & evenmask;
	int evenbits = n & oddmask;

	oddbits = oddbits >> 1;
	evenbits = evenbits << 1;
	return oddbits | evenbits;
}

int main(){
	int a = 10;
	printf("%d\n", replacebits(a));
	assert( replacebits(a) == 5 );
	return 0;
}
