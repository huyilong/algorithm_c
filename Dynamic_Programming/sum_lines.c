#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

typedef struct line{
	int a, b, c;
}line;
//then it is called line afterwards

int n;
line line_set[MAX];
int state[MAX];

void go(){
	int i, j;
	qsort(line_set, n, sizeof(line), line_cmp);
	//here we design our own comparator for the new delf-defined comparator
	state[0] = line_set[0].c;
	//the initial value is the value of the first line

	for(i=1; i<n; ++i){
		int max;
		for(j=0; j<i; j++){
			if(line_set[j].b <= line_set[i].a){
				//the previous line's ending is smaller than the beginning of the latter line
				max = max > state[j] ? max : state[j];
			}
			state[i] = max + line[i].c;
		}
	}
}

static int find_max(const int state[], int begin, int end){
	int i;
	int max = INT_MIN;//#include <limits.h>
	int max_pos = -1;
	for(i=begin; i<end; ++i){
		if(max<state[i]){
			max = state[i];
			max_pos = i;
		}
	}

	return max_pos;
}

int main(){
	int i;
	scanf("%d", &n);

	for(i=0; i<n; ++i){
		scanf("%d%d%d", &line_set[i].a, &line_set[i].b, &line_set[i].c);
	}

	go();

	printf("%d \n", state[find_max(state, 0, n)]);
	return 0;
}