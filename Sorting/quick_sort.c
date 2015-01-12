//quick sort each time would randomly pick up one element
//and divide up the sequence into two subseq and left would be less than the pivot 
//and ensure that the right side would be larger than the pivot
//then using recursion in these two subsequences etc, etc

int go_quick(int arr[], const int start, const int end){
	int i = start;
	int j = end-1;
	const int pivot = arr[i];

	while(i<j){
		while(i<j && arr[j] >=pivot)
		{
			//for these ele they are already in thier positions
			//i.e. the right subseq would be larger than pivot
			j--;
		}
		arr[i] = arr[j];
		//find one that is less than pivot 
		//then just insert to left subseq wher i is left side < pivot
		//does not matter where to correctly insert

		while(i<j && arr[i] <= pivot)
		{
			i++;
		}

		arr[j] = arr[i];
		//just insert the larger ele > pivot into right side

	}

	arr[i] = pivot;
	//the collision point would be the new pivot position
	//two subseq could be no same length
	return i;
}

void recursive_call(int arr[], const int start, const int end){
	if(start < end-1){
		//this is also the terminal condition for recursion
		const int pivot_pos = go_quick(arr, start, end);
		recursive_call(arr, start, pivot_pos);
		recursive_call(arr, pivot_pos+1, end);
	}
}