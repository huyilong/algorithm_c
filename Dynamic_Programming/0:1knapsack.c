//KP : 0-1KP  UKP  BKP
#include <stdio.h>
#include <string.h>

#define MAXN 10
#define MAXW 10

int n ,w ;
int w[MAXN+1], v[MAXN+1];
int state[MAXN+1][MAXW+1];

void go(){
	int i,j;
	memset(state, 0, sizeof(state));
	//void * memset ( void * ptr, int value, size_t num );
	for(i=1; i<=n; ++i){
		for(j=1; j<=w; ++j){

			//this is default as not put in the ith thing
			//thus the available weight j will remain the change
			//this is for the case ith = 0 
			state[i][j] = state[i-1][j];

			if(j >= w[i]){
				//find that could put in
				int temp = state[i-1][j- w[i]] + v[i];
				//be careful about previous state
				//we need to decrease both index
				//state[i-1][j- w[i]] before we add the ith v[i]

				if(temp > state[i][j]){
					state[i][j] = temp;
				}
			}
		}
	}
}

int main(){
	int i, times;
	scanf("%d", &times);
	//this time times-- and --times will not the same
	while(times--){
		scanf("%d %d", &n, &w);
		for(i=1; i<=n; ++i){
			scanf("%d", &v[i]);
		}

		for(i=1; i<=n; ++i){
			scanf("%d", &w[i]);
		}

		go();
		printf("%d \n", state[n][w]);
	}

	return 0;

}