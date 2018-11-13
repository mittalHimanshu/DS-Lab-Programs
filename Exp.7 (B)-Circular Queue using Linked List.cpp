#include<iostream>
using namespace std;

typedef struct cqueue_node {
   int data;
   struct cqueue_node *next;
}node;

class cqueue {
private :
   node *front, *rear;
public :
   cqueue() {
      front = rear = NULL;
   }
   void enqueue(int element);
   int dequeue();
   void displayCQueue();
};

 
void cqueue :: enqueue(int element) {
   node *new_element = new node;
   new_element->data = element;
   new_element->next = NULL;
   if (front == NULL) {
      front = rear = new_element;
   }
   else {

      rear->next = new_element;
      rear = new_element;
   }
   rear->next = front;
}

int cqueue :: dequeue() {
   int element;
   if (front == NULL) {
      return -99999; 
   }
   else if (front == rear) {

      element = front->data;
      delete front;
      front = rear = NULL;
   }
   else {
      node *ptr = front;
      element = ptr->data;
      front = front->next;
      rear->next = front;
      delete ptr;
   }
   return element;
}


void cqueue :: displayCQueue() {
   node *ptr = front;
   cout<<"\nCircular Queue \n";
   do {
      cout<<ptr->data<<" ";
      ptr = ptr->next;
   } while (ptr != front);
}


int main() {
   cqueue cq;
   cq.enqueue(5);
   cq.enqueue(18);
   cq.enqueue(11);
   cq.enqueue(7);
   cq.enqueue(13);
   cq.enqueue(9);
   cq.displayCQueue();
   int dq_element = cq.dequeue();
   cout<<"\nDequeued element :: "<<dq_element;
   cout<<"\nAfter dequeueing :-";
   cq.displayCQueue();
   cout<<endl;
   return 0;
}
