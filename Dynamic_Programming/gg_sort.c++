/*
对数组排序，使得a1<=a2>=a3<=a4>=...
也是很简单的O(n)，注意写的时候不用swap元素
*/

////////version @1
感觉还是swap来得简洁啊。你code里面维持current其实等效于swap吧?
//two cases 
//therefore we need a boolean flag to split up two conditions 
//so that they could be always entering one of the following cases
//smallHead && arr[i] > arr[i + 1] || !smallHead && arr[i] < arr[i + 1]
  void reorder(int[] arr) {
    assert (arr != null);
    if (arr.length == 0)
      return;

    boolean smallHead = true;

    for (int i = 0; i < arr.length - 1; i++) {
      if (smallHead && arr[i] > arr[i + 1] || !smallHead && arr[i] < arr[i + 1]) {
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
      }
      smallHead = !smallHead;
      //flip the flag
    }
  }

////////version @2
  假设一开始保证a0>=a1, 考虑a2的时候，可能有
1) case 1: a2<a1
2) case 2: a2>=a1 and a2<a0
3) case 3: a2>=a0

case 2 and 3 无所谓，case 1的话只需考虑swap a1, a2,就可以满足条件了，
依次类推，只需在不满足的时候swap尾端的两个值，不是很理解原Po主说不让swap

code 如下

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sortWave(int A[], int n)
//this function sort the array in the following way
// e.g., A={1,2,3,4,5,6}
//       ->{2,1,4,3,6,5}

{
        if(n<=1)
        return;
        
        if(A[0]<A[1])
                swap(A[0],A[1]);
        
        bool flag=true;
        
        for(int i=2;i<n;i++)
        {
                if((flag && A[i-1]>A[i])||(!flag && A[i-1]<A[i]))
                swap(A[i-1],A[i]);
                
                flag=!flag;
        }
        
        cout<<endl;
}

bool testWaveSort(int A[], int n)
{
        sortWave(A,n);
        bool flag=true;
        for(int i=1;i<n;i++)
        {
                if((flag && A[i-1]<A[i])||(!flag && A[i-1]>A[i]))
                return false;
                
                flag=!flag;
        }
        return true;
}
int main() {
        // your code goes here
        int A[0];
        if(testWaveSort(A,0))
        cout<<"test 0 succeed"<<endl;
        else
        cout<<"test 0 failed"<<endl;
        
        for(int i=0;i<500;i++)
        {
                int n=rand()%10;
                //cout<<n<<endl;
                int B[n];
                for(int j=0;j<n;j++)
                {
                B[j]=rand()%100;
                //cout<<B[j]<<" ";
                }
                //cout<<endl;
                
                if(testWaveSort(B,n))
                cout<<"test "<<i<<" succeed"<<endl;
                else
                {
                        cout<<"test "<<i<<" failed"<<endl;
                        for(int j=0;j<n;j++)
                        cout<<B[j]<<" ";
                }
        }
        return 0;
}


发帖赚点经验