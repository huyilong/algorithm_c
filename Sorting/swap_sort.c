//stable: radix, insertion, bubble, merge
//O(nlogn) : quick sort, heap sort, merge sort
//O (n^2) there are two looping nested to each other in the algorithm and always using temp

void go_bubble(int arr[], const int start, const int end){
	int exchange_flag;
	int temp;
	int i,j;

	//from the end to the beginning 
	//each time get the smallest ele into the first element
	for(i=start; i<end-1; ++i){
		exchange_flag = 0;
		for(j = end-1; j>i; --j ){
			if(arr[j-1] > a[j]){
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
				exchange_flag = 1; 
			}
		}

		if(exchange_flag == 0)
			return;//this round does not have any ele to sort
	}
}