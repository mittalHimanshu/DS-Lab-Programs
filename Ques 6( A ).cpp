#include<iostream>
using namespace std;

class stack{
	struct node{
		char data;
		struct node *next;
	};
	struct node *head,*ptr;
	public:
	stack(){
		head=NULL;
	}
	void push(char);
	void pop();
	char top();
	int priority(char);
	bool isempty();
};
bool stack::isempty(){
	if(head==NULL){
		return false;
	}
	return true;
}

char stack :: top(){
	return ptr->data;
}
int stack::priority(char s){
	if(s=='^'){
		return 3;
	}
	else if(s=='*' || s=='/'){
		return 2;
	}
	else if(s=='+' || s=='-'){
		return 1;
	}
	else{
		return -1;
	}
}
void stack :: pop(){
//	if(head==NULL){
//		return;
//	}
	ptr=head;
	if(ptr->next == NULL){
		delete ptr;
		head=NULL;
		return;
	}
	while(ptr->next->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=NULL;
	delete ptr->next;
}
void stack::push(char c){
	struct node *f1 = new node;
	f1->data=c;
	f1->next=NULL;
	if(head==NULL){
		head=f1;
		ptr=head;
	}
	else{
		ptr->next=f1;
		ptr=ptr->next;
	}
}

void infixToPostfix(string exp){
	stack obj;
	int i=0;
	string str="";
	for(i=0;i<exp.length();i++){
		if(exp[i]>='a' && exp[i]<='z'){
			str=str+exp[i];
		}
		else if(exp[i]=='('){
			obj.push(exp[i]);
		}
		else if(exp[i]==')'){
			while(obj.top()!='('){
				str=str+obj.top();
				obj.pop();
			}
			if(obj.top()=='('){
				obj.pop();
			}
		}
		else{
			if(!obj.isempty()){
				obj.push(exp[i]);
			}
			else{
				while(obj.priority(exp[i]) <= obj.priority(obj.top())){
					str=str+obj.top();
					obj.pop();
				}
				obj.push(exp[i]);
			}
		}
	}
	while(obj.isempty()){
		str=str+obj.top();
		obj.pop();
	}
	cout<<str;
}
int main(){
	string exp="(a+b/c*(d+e)-f)";
	infixToPostfix(exp);
	return 0;
}
