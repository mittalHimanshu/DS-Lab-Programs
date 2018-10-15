#include<iostream>
using namespace std;
class array
{
  int arr[100],i,n,key;
  public:
  void create();
  void search();
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
void array::search()
{
  cout<<"Enter the element to be searched: ";
  cin>>key;
  for(i=0;i<n;i++)
  {
    if(arr[i]==key)
    {
      cout<<"The element is present at position "<<i<<endl;
      break;
    }
  }
  if(i==n)
  {
    cout<<"The element does not exist\n";
  }
}
int main()
{
  array a;
  a.create();
  a.search();
}
