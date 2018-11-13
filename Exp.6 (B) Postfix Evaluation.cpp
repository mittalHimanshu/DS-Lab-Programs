#include<iostream>
using namespace std;
class Stack{
    struct node{
        int data;
        struct node *next;
    };
    struct node *head, *ptr, *prev;
    public:
        bool push(int x);
        void pop(char);
        bool isEmpty();
        int top();
        Stack(){
            head = NULL;
        }
};

void infixToPostfix(string str){
    Stack obj;
    string output = "";
    int chr;
    int length = str.length();
    for(int i=0; i<length; i++){
        chr = str[i] - '0';
        if(chr >= 0 && chr <= 9){
            obj.push(chr);
        }
        else{
            obj.pop(str[i]);
        }
    }

    cout<<obj.top();
}

void Stack :: pop(char str){
    if(head == NULL)
        return;

    int val1 = prev->data;
    int val2 = ptr -> data;
    ptr = head;
    
    while(ptr -> next != prev  && ptr -> next != NULL){
        ptr = ptr -> next;
    }
    ptr -> next = NULL;
    delete prev;
    
    switch(str){
        case '+':
            push(val1+val2);
            break;
        case '-':
            push(val1-val2);
            break;
        case '*':
            push(val1*val2);
            break;
        case '/':
            push(val1/val2);
            break;
        case '^':{
            int ans = 1;
            for(int i=0; i<val2; i++)
                ans = val1 * ans;
            push(ans);
            break;
        }
    }
    
}

bool Stack :: push(int x){
    struct node *node1 = new node;
    node1 -> data = x;
    node1 -> next = NULL;
    if(head == NULL){
        head = node1;
        ptr = head;
        prev = ptr;
    }
    else{
        ptr -> next = node1;
        prev = ptr;
        ptr = ptr -> next;
    }
}

int Stack :: top(){
    return ptr->data;
}

int main(){
    string exp = "568+*2/";
    infixToPostfix(exp);
    return 0;
}
