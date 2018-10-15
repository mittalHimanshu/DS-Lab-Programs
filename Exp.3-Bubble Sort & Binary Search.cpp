#include<iostream>
using namespace std;
class array
{
  int arr[100],i,j,n,key,temp;
  public:
  void create();
  void bubbleSort();
  void binarySearch();
  void display();
};
void array::create()
{
  cout<<"Enter the size of array: ";
  cin>>n;
  cout<<"Enter the elements for the array: ";
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
}
void array::bubbleSort()
{
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
}
void array::binarySearch()
{
  cout<<"Enter the element to be searched: ";
  cin>>key;
  int first=0;
  int last=n-1;
	int middle=(first+last)/2;
	while(first<=last)
	{
  	if(arr[middle]<key)
  	{
  		first=middle+1;
  	}
  	else if(arr[middle]==key)
  	{
  		cout<<key<<" found at index "<<middle<<"\n";
  		break;
  	}
  	else
  	{
      last=middle-1;
  	}
  	middle=(first+last)/2;
  }
  if(first>last)
  {
  	cout<<key<<" is not found in the array";
  }
}
void array::display()
{
  cout<<"Sorted array elements are: ";
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main()
{
  array a;
  a.create();
  a.bubbleSort();
  a.display();
  a.binarySearch();
}
