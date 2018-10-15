#include<iostream>
using namespace std;
class array
{
  int arr[100],i,n,pos,val,key;
  public:
  void create();
  void insert();
  void delet();
  void search();
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
void array::insert()
{
  cout<<"Enter the position of element to be inserted: ";
  cin>>pos;
  cout<<"Enter the element to be inserted: ";
  cin>>val;
  for(i=n-1;i>=pos;i--)
  {
    arr[i+1]=arr[i];
  }
  arr[pos]=val;
  n=n+1;
}
void array::delet()
{
  cout<<"Enter the position of the element to be deleted: ";
  cin>>pos;
  val=arr[pos];
  for(i=pos;i<n-1;i++)
  {
    arr[i]=arr[i+1];
  }
  n=n-1;
  cout<<"The deleted element is = "<<val<<endl;
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
void array::display()
{
  cout<<"The array elements are: ";
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
  int choice;
  do{
    cout<<"\nEnter your choice:\n";
    cout<<"1.Insert\t2.Delete\t3.Search\t4.Display\t5.Exit\n";
    cin>>choice;
    switch(choice)
    {
      case 1: a.insert();
              break;
      case 2: a.delet();
              break;
      case 3: a.search();
              break;
      case 4: a.display();
              break;
      case 5: exit(0);
              break;
      default: cout<<"Invalid choice";
               break;
    }
  } while(choice!=5);
}
