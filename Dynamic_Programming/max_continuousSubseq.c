//maximum continuos subsequence sum problem
#include <stdio.h>
#include <stdlib.h>

#include <limits.h>
//MAX_MIN -32768
//MAX_MAX 32768


int go(int input[], int n){
	int i, result;

	int *d = (int*) malloc( n * sizeof(int));
	//this is same as the arr[] dynamic_memory = arr[input_size]
	state[0] = input[0];
	//initialize
	result = state[0];

	for(i=1; i<n; ++i){
		state[i] = max(input[i], state[i-1] + input[i]);
		if(result < state[i])
			result = state[i];
	}

	free(d);
	//this is similar to delete ptr or arr[] in c++
	//in java we have garbage collection GC
 	return result;
}

int main(){
	int n, *input;
	//n is the size of the following array
	//and the input will be the array passed in the function
	while(scanf("%d", &n) >0){
		int i;
		input = (int*) malloc(n* sizeof(int));
		for(i=0; i<n; ++i){
			scanf("%d", &input[i]);
		}

		printf("%d \n", go(input, n));
		free(input);
	}
}
