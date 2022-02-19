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
	for(int i = 2; i<n; i++){
		if(!pr[i]) primes.push_back(i);
		for(int j = 0; j<primes.size() and i*prime[j]<N; j++){
			pr[i * primes[j]] = true;
			if(i%prime[j] == 0) break;
		}
	}
}

//let f be a multiplicative function to be precalculated - moubius for example
vector<int> mobius(N);

void linear_sieve(){
	bool pr[N];
	memset(pr, 0, sizeof pr);
	mobius[1] = 1;
	for(int i = 2; i<N; i++){
		if(!pr[i]){
			primes.push_back(i);
			mobius[i] = -1;
		}
		for(int j = 0; j<primes.size() and i*primes[j]<N; j++){
			pr[i * primes[j]] = true;
			if(i%(primes[j]*primes[j])==0) mobius[i] = 0;
			mobius[i * primes[j]] = mobius[i]*mobius[primes[j]];
		}
	}
}

//functions that are multiplicative:
//Euler's totient function
//mobius function
//some others