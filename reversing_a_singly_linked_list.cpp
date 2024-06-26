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
        void insertathead(int data){
        node *temp=new node(data);
        temp->link=head;
        head=temp;
    }
void reverse_it()
    {
        // Initialize current, previous and next pointers
        node* current = head;
        node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->link;
            // Reverse current node's pointer
            current->link = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
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
    cout<<endl;
    l1.reverse_it();
    l1.display();
}
