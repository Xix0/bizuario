#include <stdio.h>
#include <string.h>
#include <math.h>

int BpD(int n){
	int n1=0;
	for(int i = 0; n!=0; i++){
		n1+=(n%10)*pow(2, i);
		n=(n-(n%10))/10;
	}
	return n1;
}
