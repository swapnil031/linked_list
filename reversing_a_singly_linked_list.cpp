#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *link;
    node(int adata){
        this->data=adata;
        this->link=NULL;
    }
};
class linkedlist{
    node *head;
    public:
            
         linkedlist(){
                this->head=NULL;
            }
        void insertatTail(int value){
            node *new_node=new node(value);
            if(head==NULL){
                head=new_node;
                return;
            }
            node *temp=head;
            while(temp->link!=NULL){
                temp=temp->link;
            }
            temp->link=new_node;
            
        }
        void display(){
            node *temp=head;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->link;
            }
            cout<<"end";
        }
    
};
int main(){
    linkedlist l1;
    l1.insertatTail(1);
    l1.insertatTail(2);
    l1.insertatTail(3);
    l1.insertatTail(4);
    l1.display();
}