#include<iostream>
using namespace std;

class list{
	struct node {
		int data;
		struct node *prev;
		struct node *next;
	};
	public:
		struct node *head,*ptr,*tail,*ptr1;
		list(){
			head=NULL;
			tail=NULL;
		}
		void insert_at_end(int);
		void insert_at_beginning(int);
		void insert_inbetween(int);
		void delete_element(int);
		void search_element(int);
		void display();
};
void list::insert_at_end(int num){
	struct node *f1 =new node;
	f1->data=num;
	if(head==NULL && tail==NULL){
		head=f1;
		tail=f1;
		f1->prev=NULL;
		f1->next=NULL;
	}
	else{
		tail->next=f1;
		f1->prev=tail;
		f1->next=NULL;
		tail=tail->next;
	}
}
void list::insert_at_beginning(int num){
	struct node *f1= new node;
	f1->data=num;
	if(head==NULL && tail==NULL){
		head=f1;
		tail=f1;
		f1->prev=NULL;
		f1->next=NULL;
	}
	else{
		f1->next=head;
		head->prev=f1;
		f1->prev=NULL;
		head=head->prev;
	}
}
void list::insert_inbetween(int num){
	struct node *f1=new node;
	int ele;
	cout<<"Enter a element where you want to insert to number : ";
	cin>>ele;
	ptr=head;
	while(ptr->next->data!=ele){
		ptr=ptr->next;
	}
	f1->data=num;
	f1->prev=ptr;
	f1->next=ptr->next;
	ptr->next=f1;
	f1->next->prev=f1;
	
}
void list::display(){
	ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}
void list::delete_element(int num){
	ptr=head;
	ptr1=head;
	while(ptr->next->data!=num){
		ptr=ptr->next;
	}
	while(ptr1->data!=num){
		ptr1=ptr1->next;
	}
	ptr->next=ptr->next->next;
	delete ptr1;
	
}
void list::search_element(int num){
	ptr=head;
	while(ptr!=NULL){
		if(ptr->data==num){
			cout<<"Search is successful. Number exist in link list"<<endl;
			break;
		}
		ptr=ptr->next;
	}
}
int main(){
	list l;
	int num,choice,sub_choice,del;
	cout<<"Enter 1 for insert, 2 for delete, 3 for search, 4 for display and 5 for exit : ";
	cin>>choice;
	while(choice!=5){
		switch(choice){
			case 1:
				cout<<"Enter element : ";
				cin>>num;
				cout<<"Enter 1 for inserting at end, 2 for inserting at beginning or 3 for inserting inbetween : ";
				cin>>sub_choice;
				switch(sub_choice){
					case 1:
						l.insert_at_end(num);
						break;
					case 2:
						l.insert_at_beginning(num);
						break;
					case 3:
						l.insert_inbetween(num);
						break;	
				}
				break;
			case 2:
				cout<<"Enter element to delete : ";
				cin>>del;
				l.delete_element(del);
				break;
			case 3:
				int search;
				cout<<"Enter Element for search : ";
				cin>>search;
				l.search_element(search);
				break;
			case 4:
				l.display();
				break;
		}
		cout<<"Enter Choice : ";
		cin>>choice;
	}
}
