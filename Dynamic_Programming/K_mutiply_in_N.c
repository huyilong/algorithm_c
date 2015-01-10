//here are two numbers in first line
//first is N for length and the second is K for the number of mutiply
//then the second line is the string which has a length of N

#include <stdio.h>
#include <stdlib.h>

#define MAXN 30;// have 30 chars
#define MAXK 5;//  could use 5 *

int N,K;

char str[MAXN];
int state[MAXN][MAXN][MAXK];
//state[i][j][k] means that from i to j has k * will result in the maximum of result

int strToNum(int begin, int end){
	int result = 0;
	int i;
	for(i=begin; i<=end; ++i){
		result = result * 10 + (str[i] - '0');
	}
	return result;
} 

void go(){
	int i, j, k, s, t;
	// i < k <j ; 0 < t < k;
	memset(state, 0, sizeof(state));
	for(i=0; i< N; i++){
		/*
		for(j=0; j<M; ++j){
			*/
		for(j=i; j<N; ++j){

			state[i][j][0] = num(i,j);
		
		}
	}

	for(i=0; i<N; ++i){
		for(j=i; j<M; ++j){
			for(k=1; k<=K; ++k){
				for(s=i; s<j; ++s){
					for(t=0; t<k; ++t){
						state[i][j][k] = max(state[i][j][k], state[i][s][t]* state[s+1][j][k-t-1]);
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d%d", &N, &M);
	scanf("%s", str);

	go();
	printf("%d \n", state[0][N-1][K]);
	return 0;
}