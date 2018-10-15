#include<iostream>
using namespace std;
class quick
{
  int i,j,size,a[100];
  public:
    void input(int n)
    {
      size=n;
      cout<<"Enter the elements: ";
    	for(i=0; i<size; i++)
    	{
    		cin>>a[i];
    	}
    }
    void quicksort(int low,int high)
    {
      if (high > low)
      {
        int mid = split(a,low,high) ;
        quicksort(low,mid-1) ;
        quicksort(mid+1,high) ;
      }
    }
    int  split(int a[], int low, int high)
    {
      int mid, p, q, t ;
      p = low+1;
      q = high;
	    mid = a[low] ;
      while( q >= p )
      {
        while(a[p] < mid)
			  p++ ;
	    	while(a[q] > mid)
	  		q-- ;
		    if(q>p)
		    {
          t = a[p];
			    a[p] = a[q] ;
			    a[q] = t ;
		    }
      }
      t = a[low] ;
      a[low] = a[q] ;
      a[q] = t ;
      return q ;
    }
    void display()
    {
      for(i=0; i<size; i++)
    	{
    		cout<<a[i]<<" ";
    	}
    }
};
int main()
{
	quick q;
  int size;
  cout<<"Enter size of array: ";
  cin>>size;
  q.input(size);
  q.quicksort(0,size-1);
	cout<<"Array after sorting: ";
	q.display();
}
