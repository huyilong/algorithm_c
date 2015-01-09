//first input the rows of the triangle
//then like 5
//1
//23
//123
//1234
//12345
//actually go left is state[i+1][j] and go right is state[i+1][j+1]

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int n, input[MAX][MAX], state[MAX][MAX];

int go(){
	int i, j;
	for(i=0; i<n; ++i){
		state[n-1][i] = input[n-1][i];
	}

	for(i=n-2; i>=0; --i){
		for(j=0; j<=i; ++j){
			//this is using bottom-up
			//so we start from n-2
			//because the initilization state is n-1
			state[i][j] = input[i][j] + max(state[i+1][j], state[i+1][j+1]);
		}
	}
}

int main(){
	int i, j;
	memset(state, -1, sizeof(state));
	//malloc the memory blocks for a 2d matrix
	//the first arg is the address of the matrix i.e. &state[0][0]
	//the second arg is the initialization of all places filling with -1
	//the third arg is the size of state which is declared at first : state[MAX][MAX]

	scanf("%d", &n);
	for(i=0; i<n; ++i){
		for (j=0; j<=i; ++j)
			scanf("%d", &input[i][j]);
	}

	go();

	printf("%d \n", state[0][0]);
	//because we are using bottom-up
	//and thus we need to return the first value rather than state[n][n]
	return 0;
}