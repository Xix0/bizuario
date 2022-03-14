#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

vector<int> primes;

//O(nlog(log(n))
void sieve(){
	bool pr[N];
	memset(pr, 0, sizeof pr);
	for(int i = 2; i<N; i++){
		if(pr[i]) continue;
		primes.push_back(i);
		for(int j = i*i; j<N; j+=i) pr[j] = true;
	}
}

//linear sieve is good for precalculating multiplicative functions, otherwise its just faster to code and understand the O(nlog(log(n)) one

//O(n)
void linear_sieve(){
	bool pr[N];
	memset(pr, 0, sizeof pr);
	for(int i = 2; i<N; i++){
		if(!pr[i]) primes.push_back(i);
		for(int j = 0; j<primes.size() and i*primes[j]<N; j++){
			pr[i * primes[j]] = true;
			if(i%primes[j] == 0) break;
		}
	}
}

//let f be a multiplicative function to be precalculated - moubius for example
vector<int> m(N);

void crivo(){
	long long pr[N];
	memset(pr, 0,sizeof pr);
	for(long long i = 2; i<N; i++){
		if(pr[i]) continue;
		primes.push_back(i);
		for(long long j = i; j<N; j+=i) pr[j]++;
	}
	for(long long i = 1; i<N; i++){
		if(pr[i]&1) m[i] = -1;
		else m[i] = 1;
	}
	for(long long i: primes) for(long long j = 1; j*i*i<N; j++) m[j*i*i] = 0;
}

//functions that are multiplicative(but not completely multiplicative - only valid for coprimes):
//Euler's totient function
//mobius function
//some others