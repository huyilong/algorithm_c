

//k=1
void BuildMaxHeap(int *arr, int length){
	//from the bottom to top 
	//creating the heap
	//attention: when adjust the up, down might be damaged and readjusted
	for(int i = length/2; i>0; --i){
		//from the last parent node 
		//from bottom to up
		adjustDown(arr, i, length);
		//actually this time we are creating the max heap 
		//and thus the adjust down should be called for n/2 times

		//but in sorting we only need to adjustDown once to readjust the "new root"
	}
}

//from down to up i=n/2 ... 1
//or used in heapsort for i=1
void adjustDown(int arr[], int k, int length){
	arr[0] = arr[k];
	//store the current root
	//might be the last root in creating heap
	//might be the root root in sorting and readjusting the heap
	for(i=2*k; i<=len; i=i*2){
		//for its left child
		//or the left child of left child...
		if(i<len && arr[i] < arr[i+1]){
			++i;//find the largest value of the children
			//attention!!! this is if not while
			//we just need to judge if there is a right children existing 
			//then use the right instead of the left 
			//but no matter with the sibling!!!
		}
		if(arr[0] >= arr[i])
			//we find the current root's suitable place
			//break and then swap!!
			break;

		else{
			arr[k] = arr[i];
			k = i;
			//both move up the node and the index!!!!!
		}
	}

	//after the for looping
	arr[k] = arr[0];
	//we place the node to current place
	//because
	/*
	arr[k] = arr[i];
	k = i;
	have already moved up all the nodes and make a vacant position
	*/
}


void HeapSort(int arr[], int length){
	BuildMaxHeap(arr, length);
	//using the passed in unsorted array to initialize a max heap
	//using O(n)
	//max heap :: arr[i] >= arr[2i] && arr[i] >= arr[2i+1]
	//min heap :: arr[i] <= arr[2i] && arr[i] <= arr[2i+1]
	for(i = len; i>1; i--){
		swap(arr[i], arr[1]);
		//every time move the top of the current max heap
		//down to the last element

		//but this time the top is no longer max
		//we need to readjust the heap each time after we swapped
		adjustDown(arr, 1, i-1);
		//k =1 i.e. k is the index of the root of max heap
		//why? because we will need arr[0] left blank for storing the temporarily root when adjust
	}
}