//o(n^2)
//straight insertion sort
//initial sorted array is a[0] and after n-1 to insert the ele from unsorted array

void go(int arr[], const int start, const int end){
	int temp;
	int i,j;

	for(i=start+1; i<end; ++i){
		temp = arr[i];

		//SORTING IN THE SORTED ARRAY
		for(j=i-1; temp<arr[j] && j>=start; --j)
		{
			arr[j+1] = arr[j];
			//using temp to get the current element
			//and then move around all the other elements 
			//do not care the original position
			//just move, one time sort one
		}

		arr[j+1] = temp;
	}
}

//binary insertion sort
//just when searching the proper insertion using binary search
//the time will not change dramatically 
void go_binary(int arr[], const int begin, const int end){
	int temp;
	int i, j, left, right, mid;

	for(i=start+1; i<end; ++i){
		temp = arr[i];
		left = start;
		right = i-1;
		//right is the last element of first part :: sorted array

		while(left<=right){
			mid = left+right / 2;
			if(temp < arr[mid]){
				right = mid -1;
			}else{
				left = mid+1;
			}
		}

		for(j=i-1;j>=left; --j){
			arr[j+1] = arr[j];
		}

		arr[left] = temp;
		//place the element in the right place at last
	}
}

//shell insertion sort
//there is only one diff from the straight insertion sort
//which is that the distance between two nums are gap rather than 1
//then we decrease the gap each time until 1
static void go_shell(int arr[], const int start,  const int end, const int gap){
	int temp;
	int i, j;
	for( i=start+gap; i<end; i++){
		//here we still use i++
		temp = arr[i];
		for(j = i-gap; temp<arr[j] && j >= start ; j = j-gap){

			arr[j+gap] = arr[j];
		}

		arr[j+gap] = temp;
	}
}


void shell_call(int arr[] , const int start, const int end){
	int gap = end - start;
	while(gap > 1){
		gap = gap/3 +1;
		go_shell(arr, start, end , gap);
	}
}