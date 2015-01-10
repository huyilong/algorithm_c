//we could not declare the i and j
//just use the state[k][j] to denote 
//from 0 to j
//              and use k * and get the maximum



#include <stdio.h>
#include <stdlib.h>

#define MAXN 30
#define MAXM 5

int N,K;
char str[MAXN];

int state[MAXK+1][MAXN];

void go(){
	int i,j,k;

	memset(state, 0, sizeof(state));

	//initialize would be easier 
	//all from 0 to j
	for(j=0; j<N; ++j){
		state[0][j] = strToNum(0,j);
	}

	for(k=1; k<= K; ++k){
		for(j=0; j<N; ++j){
			for(i=0; i<j; ++i){
				state[k][j] = max(state[k][j], state[k-1][j] * strToNum(i+1,j) );
			}
		}
	}
}

int main(){
	scanf("%d%d", &N, &M);
	scanf("%s", str);

	go();
	printf("%d\n", state[K][N-1]);
	return 0;
}