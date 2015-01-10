//divede n to k pieces
//order does not matter
//1 1 5 and 1 5 1 and 5 1 1 are the same
#include <stdio.h>
#include <memory.h>

#define MAXN 30
#define MAXK 10

int n,k;
int state[MAXK+1][MAXN+1];

void go(){
	int i,j;
	memset(state, 0, sizeof(state));

	for(i=1; i<=n; ++i){
		state[1][i] = 1;
		if(i<=k)
			state[i][i] = 1;
	}

	for(j=2; j<=k; ++j){
		for(i=j+1;i<=n;++i){
			state[j][i] = state[j-1][i-1] + state[j][i-j];
		}
	}
}