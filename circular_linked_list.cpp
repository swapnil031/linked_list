#include<iostream>
using namespace std;
class node{
    public:
    int value;
    node *next;
    node(int data){
        this->value=data;
        this->next=NULL;
    }
};
class circular_nexted_list{
    node* head;
    public:
    circular_nexted_list(){
        this->head=NULL;
    }

    void insert_at_start(int value){
        node *new_node=new node(value);
        if(head==NULL){
            head=new_node;
            new_node->next=head;
            return;
        }
        node *tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=new_node;
        new_node->next=head;
        head=new_node;
    }

    void insert_at_tail(int value){
        node *new_node=new node(value);
        if(head==NULL){
            insert_at_start(value);
            return;
        }
        node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=new_node;
        new_node->next=head;
        return;
    }

    void insert_At_Position(int position,int value){
    if(position==1){
        insert_at_start(value);//using a common function
        return ;
    }
    node *temp=head;
    node *insert=new node(value);
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insert_at_tail(value);//using a common function;
        return;
    }
    insert->next=temp->next;
    temp->next=insert;
    }

    void delete_at_head(){
        if(head==NULL){
            return;
        }
        node *temp=head;
        node *tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        head=head->next;
        tail->next=head;
        free(temp);
        return;
    }

    void delete_at_end(){
        node* tail=head;
        while(tail->next->next!=head){
            tail=tail->next;
        }
        tail->next=head;
    }
    void display(){
        node *tail=head;
        do
        {
            cout<<tail->value<<"->";
            tail=tail->next;
        } while (tail!=head);
        cout<<"endl";
    }
};
int main(){
    circular_nexted_list c1;
    c1.insert_at_start(1);
    c1.insert_at_start(2);
    c1.insert_at_start(3);
    c1.insert_at_start(4);
    c1.insert_at_start(5);
    c1.insert_at_tail(6);
    c1.insert_At_Position(1,8);
    c1.delete_at_head();
    c1.delete_at_end();
    c1.display();
}