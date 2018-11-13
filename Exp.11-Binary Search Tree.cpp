#include<iostream>
using namespace std;
struct node{
		int data;
		struct node *left,*right;
	};
class tree{
	public:
		struct node *root;
		tree(){
			root=NULL;
		}
		void Insert(int);
		struct node *insertNode(struct node *,int);
		struct node *insertnode(int);
		void inorder(struct node *);
		void in_order();
		void postorder(struct node *);
		void post_order();
		void preorder(struct node *);
		void pre_order();
		struct node *Delete(struct node *,int);
		void Delete_element(int);
		struct node *findMin(struct node *);
		
};
void tree::Insert(int num){
	root = insertNode(root,num);
}
struct node* tree:: insertnode(int num){
	struct node *f1=new node;
	f1->data = num;
	f1->left=f1->right=NULL;
	return f1;
}
struct node* tree:: insertNode(struct node *root,int num){
	if(root==NULL){
		root=insertnode(num);
		return root;
	}
	else if(num<root->data){
		root->left = insertNode(root->left,num);
	}
	else if(num>root->data){
		root->right = insertNode(root->right,num);
	}
	return root;
}

void tree :: inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void tree :: postorder(struct node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
void tree :: preorder(struct node *root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}


void tree::in_order(){
	inorder(root);
}
void tree::post_order(){
	postorder(root);
}
void tree::pre_order(){
	preorder(root);
}
struct node* tree::Delete(struct node *head,int num){
	if(head==NULL){
		return head;
	}
	else if(num < head->data){
		head->left = Delete(head->left,num);
	}
	else if(num > head->data){
		head->right = Delete(head->right,num);
	}
	else{
		if(head->left==NULL && head->right==NULL){
			delete head;
			head=NULL;
			return head;
		}
		else if(head->left==NULL){
			struct node *temp=head;
			head=head->right;
			delete temp;
			return head;
		}
		else if(head->right==NULL){
			struct node *temp=head;
			head=head->left;
			delete temp;
			return head;
		}
		else{
			struct node *temp=findMin(head->right);
			head->data =temp->data;
			head->right = Delete(head->right,temp->data);
		}
	}
	return head;
}
struct node* tree::findMin(struct node *curr){
	while(curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}
void tree::Delete_element(int del){
	root = Delete(root,del);
}
int main(){
	tree t;
	int choice,num,del;
	cout<<"Enter choice 1 for insertion, 2 for deletion, 3 for inorder traversal, 4 for preorder traversal, 5 for postorder traversal and 6 for exiting the program"<<endl;
	cin>>choice;
	while(choice!=6){
		switch(choice){
			case 1:
				cout<<"Enter element : ";
				cin>>num;
				t.Insert(num);
				break;
			case 2:
				cout<<"Enter node to be deleted : ";
				cin>>del;
				t.Delete_element(del);
				break;
			case 3:
				t.in_order();
				break;
			case 4:
				t.pre_order();
				break;
			case 5:
				t.post_order();
				break;	
		}
		cout<<"Enter choice 1 for insertion, 2 for deletion, 3 for inorder traversal, 4 for preorder traversal, 5 for postorder traversal and 6 for exiting the program"<<endl;
		cin>>choice;
	}
}
