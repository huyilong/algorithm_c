//longest common subsequence problem
//we firstly need to find out the state and state transition equation
//to solve this dynamically, i.e. from the bottom-up

#include <stdio.h>
//similar to #include <iostream>
#include <string.h>

#define MAX 20;

int state[MAX][MAX];
//state[i][j] means that the xi and yi has the length of maximum subsequence
char x[MAX], y[MAX];

void lcs(const char *x, const int m, const char *y, const int n){
	int i,j;

	for(i = 0; i<=m; ++i)  
		state[i][0] = 0;
	for(j = 0; i<=n; ++j)
		state[0][j] = 0;

	for(i=1; i<=m; ++i){
		for(j=1; j<=n; ++j){

			if(x[i-1] == y[i-1]){
				//we get a perfect intermediate but still could find further
				state[i][j] = state[i-1][j-1] + 1;
			}
			else{
				//we finally meet with the difference and thus need to pick up the bigger one
				//from the former two sub problems's optimal result
				//this is a 2d DP
				state[i][j] = state[i-1][j] > state[i][j-1] ? state[i-1][j] : state[i][j-1];
			}
		}
	}
}

int main(){
	//input would be seperated by whitespace
	//char x[MAX], y[MAX];
	//so x,y are already address
	//otherwise in scanf we need to &x
	while( scanf("%s%s", x, y) != EOF){
		//this will skip all the while space between the char
		const int x_len = strlen(x);
		const int y_len = strlen(y);
		lcs(x, x_len, y, y_len);

		printf("%d \n", state[x_len][y_len]);
	}
}