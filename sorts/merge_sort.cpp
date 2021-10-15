#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, v[N], a[N], b[N], ans, t;

void merge(int bot, int top){
	if(bot==top) return;
	int m = (bot+top)/2, n1 = m-bot+1, n2 = top-m;
	merge(bot, m), merge(m+1, top);
	for(int i = 0; i<n1; i++) a[i] = v[bot+i];
	for(int i = 0; i<n2; i++) b[i] = v[m+1+i];
	int i = 0, j = 0, k = bot;
	while((i<n1) && (j<n2)){
		if(a[i]<=b[j]) v[k] = a[i], i++;
		else v[k] = b[j], j++; //ans+=n1-i; add isso aqui pra contar inversões
		k++;
	}
	while(i<n1) v[k] = a[i], i++, k++;
	while(j<n2) v[k] = b[j], j++, k++;	
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i<n; i++) scanf("%d", &v[i]);
		merge(0, n-1);
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}

