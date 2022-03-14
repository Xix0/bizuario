#include <bits/stdc++.h>
using namespace std;


//ocoreencias de um padrão
vector<int> rabin_karp(string s, string t) {
	const long long p = 31;
	const long long m = 1e9 + 9;
	int S = s.size(), T = t.size();
	vector<long long> p_pot(max(S, T));

	p_pot[0] = 1;
	for (int i = 1; i < (int)p_pot.size(); i++) p_pot[i] = (p_pot[i - 1] * p) % m;

	vector<long long> h(T + 1);
	for (int i = 0; i < T; i++) h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pot[i]) % m;

	long long h_s = 0;
	for (int i = 0; i < (int)s.size(); i++) h_s = (h_s + (s[i] - 'a' + 1) * p_pot[i]) % m;

	vector<int> occ;

	for (int i = 0; i + S - 1 < T; i++) {
		long long cur_h = (h[i + S] - h[i] + m) % m;
		if (cur_h == h_s * p_pot[i] % m) occ.push_back(i);
	}

	return occ;
}

