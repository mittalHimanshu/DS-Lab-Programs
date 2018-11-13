#include<iostream>
using namespace std;
class queue
{
  int size,front,rear,i,a[100];
  public:
  queue()
  {
    cout<<"Enter size of queue: ";
    cin>>size;
    front=-1;
    rear=-1;
  }
  bool isempty()
  {
    if(front==-1 && rear==-1)
      return true;
    else
      return false;
  }
  void enqueue(int val)
  {
    if((front==rear + 1) || (front==0 && rear==size-1))
       cout<<"Queue is full\n";
    else
    {
       if(front==-1)
          front = 0;
       rear=(rear+1)%size;
       a[rear] = val;
    }
  }
  void dequeue()
  {
    if(isempty())
      cout<<"Queue is empty\n";
    else if(front==rear)
      front=rear=-1;
    else
      front=(front+1)%size;
  }
  void showfront( )
  {
    if( isempty())
      cout<<"Queue is empty\n";
    else
      cout<<"Element at front is:"<<a[front]<<"\n";
  }
  void displayQueue()
  {
    if( isempty())
      cout<<"Queue is empty\n";
    else if(front<=rear)
    {
      cout<<"Queue is: ";
      for(i=front;i<=rear;i++)
  	     cout<<a[i]<<" ";
    }
    else
    {
      cout<<"Queue is: ";
  	  for(i=front;i<size;i++)
      {
  	    cout<<a[i]<<" ";
  	  }
  	  for(i=0;i<=rear;i++)
  	  {
  	    cout<<a[i]<<" ";
  	  }
    }
    cout<<endl;
   }
};
int main()
{
  queue q;
  int flag=1,choice,value;
  while(flag==1)
  {
    cout<<"\nEnter your choice:\n1.ENQUEUE 2.DEQUEUE 3.SHOW FRONT 4.DISPLAY QUEUE 5.EXIT\n";
    cin>>choice;
    switch (choice) {
      case 1: cout<<"Enter value: ";
              cin>>value;
              q.enqueue(value);
              break;
      case 2: q.dequeue();
              break;
      case 3: q.showfront();
              break;
      case 4: q.displayQueue();
              break;
      case 5: flag=0;
              break;
    }
  }
}
