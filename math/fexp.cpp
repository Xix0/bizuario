#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;


//copy from below this line
long long fexp(long long b, long long e, long long m = MOD){
	long long ans = 1;
    while(e){
        if(e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e /= 2;
    }
    return ans;
}