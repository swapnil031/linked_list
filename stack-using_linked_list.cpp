#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int adata){
            this->data=adata;
            this->next=NULL;
        }
};
class stack{
    node *top;
    int limit=5;
    public:
        stack(){
            this->top=NULL;
        }
        int x=0;
        void push(int data){
            if(x<limit){
            node *new_node=new node(data);
            if(top==NULL){
                top=new_node;
                return;
            }
            new_node->next=top;
            top=new_node;
            x++;
            return;
            }
            else {
               return;
            }
        }
        void pop(){
            node *temp=top;
            if(temp==NULL){
                cout<<"the stack is empty";
                return;
            }
            top=top->next;
            free(temp);
        }
        int top_element(){
            return top->data;
        }
        void print(){
            node *temp=top;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"end";
        }
};
int main(){
    stack s1;
    s1.push(12);
    s1.push(20);
    s1.push(15);
    s1.push(18);
    s1.push(22);
    s1.push(26);
    s1.push(27);
    s1.print();
    cout<<endl;
    cout<<"the top element is "<<s1.top_element()<<endl;
    s1.pop();
    s1.print();
}