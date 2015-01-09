#include <stdio.h>
#include <stdlib.h>

#define MAX 21

int board_width, board_height;
int begin_x, begin_y, end_x, end_y;
int state[MAX+1][MAX+1];

void go(){
	int i, j;
	memset(state, 0, sizeof(state));
	state[begin_x][begin_y] = 1;
	//they have default value of 0
	for(i=begin_x+1; i<=end_x; ++i){

		for(j=begin_y+1; j<=end_y; ++j){

			state[i][j] = state[i-1][j-2] + state[i-1][j+2] + state[i-2][j-1] + state[i-2][j+1];
		}
	}
}

int main(){
	scanf("%d%d", &board_width, &board_height);
	scanf("%d%d%d%d", &begin_x, &end_x, &begin_y, &end_y);
	go();
	printf("%ld \n ", state[end_x][end_y]);

	return 0;
}