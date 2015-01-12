//every round pick up (select) the smallest element in the later array
//and put the next place in the first sorted array

void go_select(int arr[], int start, int end){
	int temp;
	int i, j, k;
	//as long as the o(n^2) we always need a variable named temp

	for(i=start; i<end; ++i){
		//k is the index of minimum element of the last array
		k=i;

		//find the minmum from i to end-1
		for(j=i+1; j<end; ++j){
			if(arr[j] < arr[k])
				k=j;
		}

		//swap
		//each time i will go for next position of sorted array
		//but k is always the index of minimum element in the unsorted array
		if(k!=i){
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}

//heap sort actually is counted as the selection sort
//always create the max heap
//and swap and readjust the heap for next selecting the root for the last position