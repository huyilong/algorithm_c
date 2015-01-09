//the obstacle is given a place and it will like a horse
//i.e. it could go to 8 places and will occupy itself 
//in total there are 9 obstacles on the board
#include <stdio.h>
#include <memory.h>
//memory will be used with smart ptr in c++

#define MAX 31

int board_width, board_height;//arg 1 and 2
int obstacle_x, obstacle_y;//arg 3 and 4

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

int board[MAX][MAX];
int state[MAX][MAX];
//state[i][j] = state[i-1][j] + state[i][j-1] 
//each place could be possibly derived from other two places which is converse to the directions
//contricted by problem

void go(){
	int i,j;
	//they are not like c++, where only global variables would have default value of 0
	//they are like java, where all variables could be initialized with default value of 0

	//initilization
	memset(board, 0, sizeof(board));
	memset(obstacle, 0 ,sizeof(obstacle));

	//place the obstacles on the board
	//obstacle itself
	board[obstacle_x][obstacle_y] = 1;
	//obstacle expansion
	for(i=0; i<8; ++i){
		if(obstacle_x + dx[i] >=0 && obstacle_x + dx[i] <= board_width
				&& obstacle_y + dy[i] >=0 && obstacle_y + dy[i] <= board_height){
			//avoid the off-limits areas
			board[ obstacle_x + dx[i] ][ obstacle_y + dy[i] ] = 1;
		}
	}

	state[0][0] = 1;
	//i.e. all the places on the boarding line would be 1
	for(i=1; i<=board_width; ++i){
		if(!board[i][j])
			//for the places that have no obstacles
			state[i][0] = state[i-1][0];//all 1s
	}

	for(j=1; j<=board_height; ++j){
		if(!board[i][j])
			state[0][j] = state[0][j-1];
	}

	for(i=1; i<=n; ++i){
		for(j=1; j<=n; ++j){
			if(!board[i][j])
				state[i][j] = state[i-1][j] + state[i][j-1];
		}
	}

}


int main(){
	scanf("%d%d%d%d", &board_width, &board_height, &obstacle_x, &obstacle_y);
	go();
	printf("%d \n", state[board_width][board_height])
	//because state is also declared as global variable
	//thus even after the calling of go()
	//the state of state variable will still within its lifetime
	//in c++ we could use reference &vector to avoid global var
	//and also change the value very conveniently

	return 0;
}