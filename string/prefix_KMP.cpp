//função prefixo:
vi pre(string s){
	 int n = (int) s.length();
	 vi pi(n);
	 for(int i = 0; i < n; i++)
			 for(int k = 0; k <= i; k++)
					 if(s.substr(0, k) == s.substr(i-k+1, k))
							 pi[i] = k;
	 return pi;
}


//prefixo otimizado (tem uma parada de ficar pulando)
vi pre(string s){
	 vi pi(s.size());
	 for(int i = 1; i < s.size(); i++){
			 int j = pi[i-1];
			 while(j > 0 and s[i] != s[j])
					 j = pi[j-1];
			 if(s[i] == s[j])
					 j++;
			 pi[i] = j;
	 }
	 return pi;
}


//kmp (tendo o prefixo calculado)
void kmp() {
	 n = s.size();
	 for (int i = 0, j = 0; i < n;) {
			while (j >= 0 and s[i] != p[j])
			j = pi[j];
			i++, j++;
			if (j == m) {
					// matching position: i - m
					j = pi[j];
			 }
	 }
}
