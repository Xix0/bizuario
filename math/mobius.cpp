const int N = 1e2;

vector<int> m(N), p;


void crivo_mobius(){
	int pr[N];
	memset(pr, 0,sizeof pr);
	for(int i = 2; i<N; i++){
		if(pr[i]) continue;
		p.push_back(i);
		for(int j = i; j<N; j+=i) pr[j]++;
	}
	for(int i = 1; i<N; i++){
		if(pr[i]&1) m[i] = -1;
		else m[i] = 1;
	}
	for(int i: p) for(int j = 1; j*i*i<N; j++) m[j*i*i] = 0;
}