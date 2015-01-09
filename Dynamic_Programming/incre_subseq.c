//input @1 : length: 7
//input @2 : array: 1,7,3,5,9,4,8
//output : max len = 4 
//where the array is 1,3,4,8

#include <stdio.h>
#define MAX 11

int length;
int input[MAX];
int state[MAX];

void go(){
	int i, j;
	state[1] = 1;
	//here we do not use the position at 0
	//and we must initialize the first place in state matrix

	for(j=2; j<=length; ++j){
		//fill in the state from the second place
		int local_max = 0; //this is trying to find the max value of the previous state
		for(i=1; i<j; i++){
			if(input[i] < input[j] && max < state[i])
			{
				//the prerequisite is the sequence should be increasing 
				max = state[i];
			}
		}

		//after the inner loop we find the local_max of the previous state
		//then we fill in the next position of state
		state[j] = max + 1;
	}
}

int main(){
	int i, max;
	scanf("%d", &length);
	for(i=1; i<=length; ++i){
		scanf("%d", &input[i]);
	}

	go();

	max = 0;
	//find the max value in the one dimension state array
	for(i=1; i<=length; ++i){
		if(staet[i] > max)
			max = state[i];
	}

	printf("%d \n", max);
	return 0;
}