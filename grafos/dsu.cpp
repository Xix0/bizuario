//DSU (DISJOINT SET UNION / UNION-FIND) 

#include <bits/stdc++.h>
using namespace std;

const int N = 2;

//copy from below this line
int par[N], size[N];

int find(int u){
	return (par[u] == u)?  u : par[u] = find(par[u]);
}

void unite(int u, int v){
	u = find(u);
	v = find(v);
	if(size[u]<size[v]) swap(u, v);
	size[u] += size[v];
	par[v] = u;
}

