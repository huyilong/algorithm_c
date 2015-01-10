class Foo{
public:
	bool isScramble(string s1, string s2){
		const int n = s1.size();
		if(n!=s2.size())
			return false;

		bool state[n+1][n][n];
		//state[len][s1_index][s2_index]
		fill_n(&state[0][0][0], (n+1)*n*n, false);

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				state[1][i][j] = (s1[i] == s2[j])
			}
		}

		for(int n_ =1; n_<=n; ++n){
			for(int i=0; i+n<=n; ++i){
				for(int j=0; j+n<=n;++j){
					for(int k=1; k<n; ++k){
						if((state[k][i][j] && state[n-k][i+k][j+k]) || (state[k][i][j+n-k] && state[n-k][i+k][j]))
						state[n][i][j] = true;
						break;
					}
				}
			}
		}

		return state[n][0][0];
	}
}