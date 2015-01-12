//prerequisite: must have two or more already sorted subsequences to merge up
//drawback: need large space complexity
static void go_merge(int arr[], int temp_arr[], const int start, const int mid, const int end)
{
	int i, j,k;
	//i and j are scanning ptrs and k is the storing ptr
	for(i=1; i<end; i++){
		//store all the element in the "two sub" in one array into the temporary arr
		temp_arr[i] = arr[i];
	}

	for(i=start, j=mid, k = start; i<mid && j<end; k++){

		//because in temp_arr[i] the elements are already sorted from the scratch: 2 ele
		if(temp_arr[i] < temp_arr[j])
		{

			//here we are comparing the two sub array within the sorted temp_arr!!!
			//if(temp_arr[i] < temp_arr[j])

			//we finally have to get the sorted ele into arr[]
			//which is the official arr we finally use
			arr[k] = temp_arr[i++];
		}else{
			arr[k] = temp_arr[j++]
		}

	}

	//whenever treating the two linkedlist 
	//we must need to take care of the left one
	//because two are not always the same or terminate meanwhile
	//we need to wrap up the left one


	//wrap up the left elements in each array
	//actually the following two could only be called one
	while(i<mid)
	{
		arr[k++] = temp_arr[i++];
	}
	while(j<end)
	{
		arr[k++] = temp_arr[j++];
	}
}

void recursive_call(int arr[], int temp_arr[], const int start, const int end){
	//if(start < end-1){
	//will ensure that the recursive will continue until the subseq has two elements at least 
	if(start < end-1){
		//we need to update the mid each time before calling the recursion
		const int mid = (start+end)/2;
		recursive_call(arr, temp_arr, start, mid);
		recursive_call(arr, temp_arr, mid, end);
		//firstly split up the unsorted array into minimum size
		//i.e. only two elements
		go_merge(arr, temp_arr, start, mid, end);
	}
}