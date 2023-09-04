#include<iostream>
using namespace std;

class node{
    public:
            int value;
            node *prev;
            node *next;
        node(int data){
            this->value=data;
            this->next=NULL;
            this->prev=NULL;
        }
};

class doublylinked_list{
    public:
        node* head;
        node* tail;
    doublylinked_list(){
        this->head=NULL;
        this->tail=NULL;
    }
    void insertatstart(int value){
        node *new_node=new node(value);
        if(head==NULL){ //checking whether empty or not
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
    }
    void insertat_End(int value){
        node *new_node=new node(value);
        if(tail==NULL){ //checking whether empty or not
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail; 
        tail=new_node;
        return;
    }
    void insertat_any_Position(int value,int k){
        node*temp=head;
        int count=1;
        while(count<k-1){
            temp=temp->next;
            count++;
        }
        node *new_node=new node(value);
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next->prev=new_node;
        return;
    }
    void deleteat_head(){
        if(head==NULL) //checking whether empty or not
            return;
        node *temp=head;
        head=head->next;
        if(head==NULL){ //checking whether only one node is there or not
            tail=NULL;
        }
        else{
            head->prev=NULL;
            free(temp);
        }
        
    }
    void deleteat_tail(){
        if(tail==NULL){ //checking whether empty or not
            return;
        }
        node *temp=tail;
        tail=tail->prev;
        if(tail==NULL){ //checking whether only one node is there or not
            head=NULL;
        }
        else{
            tail->next=NULL;
        }
    }
    void deleteat_any_position(int k){
        if(k==1){
            deleteat_head();
            return;
        }
        else if(k==size()){
            deleteat_tail();
            return;
        }
        node* temp=head;
        int counter=1;
        while(counter<k){
            temp=temp->next;
            counter++;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }
    void display(){
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->value<<"<->";
            temp=temp->next;
        }
        cout<<"end";
    }
    int size(){
        node *temp=head;
        int n=1;
        while(temp->next!=NULL){
            temp=temp->next;
            n++;    
        }
        return n;
    }
};

int main(){
    doublylinked_list dl;
    /*dl.insertatstart(1);
    dl.insertatstart(2);
    dl.insertatstart(3);*/
    dl.insertat_End(1);
    dl.insertat_End(2);
    dl.insertat_End(3);
    dl.insertat_any_Position(4,3);
    dl.display();cout<<endl;
    //dl.size();
    //dl.deleteat_head();
   // dl.display();cout<<endl;
    //dl.deleteat_tail();
   // dl.display();
    /*cout<<dl.head->value<<endl;
    cout<<dl.tail->value<<endl;*/
    dl.deleteat_any_position(4);
    dl.display();
    return 0;
}