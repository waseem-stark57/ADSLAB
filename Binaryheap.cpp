#define MAX 10
#include <iostream>

using namespace std;

class BinaryHeapADT
{
  public:
        void heapSort(int a[MAX], int n);
        void buildHeap(int a[MAX],int,int);
};

void BinaryHeapADT::heapSort(int a[MAX], int n)
{
    int i;
	int temp,k,z=0;
	    for(i=(n/2);i>0;i--)
	         buildHeap(a,i,n);

	    for(i=n;i>=1;i--)
	    {
	       temp = a[1];
	       a[1] = a[i];
	       a[i] = temp;
	       buildHeap(a,1,i-1);
	    }
}

void BinaryHeapADT::buildHeap(int a[MAX],int root,int bottom)
{
    int temp,maxc;
		int done = 0;
		 while((root*2 <= bottom) && (!done))
		 {
			  if(root*2==bottom)
				    maxc = root*2;
			  else
			  if(a[root*2] > a[root*2+1])
				    maxc = root*2;
			  else
				    maxc = root*2+1;

			   if(a[root] < a[maxc])
			   {
		  		    temp = a[root];
				    a[root] = a[maxc];
				    a[maxc] = temp;
				    root = maxc;
			   }
			  else 
				   done = 1;
		 }
}

int main()
{
    int a[7]={0,33,66,22,88,55,44};
    BinaryHeapADT b;
    b.heapSort(a,7);
    for(int i=1;i<=7;i++)
      cout<<a[i]<<"  ";

    return 0;
}
