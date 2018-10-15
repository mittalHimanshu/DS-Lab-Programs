#include<iostream>
using namespace std;
class insertion
{
  int i,j,size,arr[100];
  public:
    insertion()
    {
      cout<<"Enter size of array: ";
      cin>>size;
    }
    void create()
    {
      cout<<"Enter the elements: ";
      for(i=0;i<size;i++)
      {
        cin>>arr[i];
      }
    }
    void insertionsort()
    {
      int temp=0;
      for(i=0; i<size; i++)
    	{
    		temp=arr[i];
    		j=i-1;
    		while((temp<arr[j]) && (j>=0))
    		{
    			arr[j+1]=arr[j];
    			j=j-1;
    		}
    		arr[j+1]=temp;
    	}
    }
    void insert(int val)
    {
      i=size-1;
      while(val<arr[i] && i>=0)
      {
        arr[i+1]=arr[i];
        i--;
      }
      arr[i+1]=val;
      size++;
    }
    void display()
    {
      for(i=0; i<size; i++)
    	{
    		cout<<arr[i]<<" ";
    	}
    }
};
int main()
{
  insertion l;
  l.create();
	l.insertionsort();
  cout<<"Array after sorting: ";
  l.display();
  int val;
  cout<<"\nEnter the element to be inserted: ";
  cin>>val;
  l.insert(val);
  cout<<"Array after sequential insertion: ";
  l.display();
}
