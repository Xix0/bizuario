#include <stdio.h>
#include <string.h>

int DpB(int n){
	int n1=0;
	for(int i = 0; n!=0; i++){
		n1+=(n%2)*pow(10,i);
		n=(n-(n%2))/2;
	}
	return n1;
}
