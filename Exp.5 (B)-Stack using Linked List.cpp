#include<iostream>
using namespace std;
struct node
{
  node *next;
  int data;
};
node *head=NULL;
void push(int val)
{
  node *ptr;
  ptr=new node;
  ptr->data=val;
  ptr->next=head;
  head=ptr;
}
bool isempty()
{
  if(head==NULL)
    return true;
  else
    return false;
}
void pop()
{
  if(isempty())
    cout<<"Stack is empty";
  else
  {
    node *ptr=head;
    head=head->next;
    delete(ptr);
  }
}
void show_top()
{
  if(isempty())
    cout<<"Stack is empty";
  else
  {
    cout<<"Element at top is: "<<head->data<<endl;
  }
}
void displayStack()
{
  if(isempty())
    cout<<"Stack is empty";
  else
  {
    cout<<"Stack is ";
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
      cout<<ptr->data<<" ";
      ptr=ptr->next;
    }
    cout<<endl;
  }
}
int main()
{
  int choice, flag=1,value;
  do
  {
  cout<<"\nEnter your choice:\n1.PUSH 2.POP 3.SHOW TOP 4.DISPLAY STACK 5.EXIT\n";
  cin>>choice;
  switch (choice)
  {
  case 1: cout<<"Enter Value: ";
          cin>>value;
          push(value);
          break;
  case 2: pop();
          break;
  case 3: show_top();
          break;
  case 4: displayStack();
          break;
  case 5: exit(0);
          break;
  }
}while(choice!=5);
  return 0;
}
