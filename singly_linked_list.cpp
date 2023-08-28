#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *link;
    //use of constructor
    node(int adata){
        this->data=adata;//data=adata;
        this->link=NULL;
    }
};
//head entering
void insertathead(node* &head,int data){
        node *temp=new node(data);
        temp->link=head;
        head=temp;
    }
//tail entering
void insertAtTail(node* &head,int d){
    node *temp=new node(d);
            node *t=head;
            while(t->link!=NULL){
                t=t->link;
            }
            t->link=temp;
}
//inserting at nth position
void insertAtPosition(node* &head,int position,int value){
    if(position==1){
        insertathead(head,value);//using a common function
        return ;
    }
    node *temp=head;
    node *insert=new node(value);
    int count=1;
    while(count<position-1){
        temp=temp->link;
        count++;
    }
    if(temp->link==NULL){
        insertAtTail(head,value);//using a common function;
        return;
    }
    insert->link=temp->link;
    temp->link=insert;
}
void deleteathead(node* &head){
    node *temp=head;
    head=head->link;
    free(temp);
}
void deleteattail(node* &head){
    node *second_last=head;
    while(second_last->link->link!=NULL)//coming to the penultimate node
    {
        second_last=second_last->link;
    }
    node *temp=second_last->link;
    second_last->link=NULL;
    free(temp);
}
//delete at any position
void deleteatAnyPoint(node* &head,int position){
    if(position==1){
        deleteathead(head);
        return;
    }
    else{
    node*prev=head;
    int count=1;
    while(count<position-1){
        prev=prev->link;
        count++;
    }
    node *temp=prev->link;
    prev->link=temp->link;
    free(temp);}
}

//printing node
void printnode(node* &head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->link;
    }
    cout<<"END";
}
int main(){
   node *head=new node(1);
   insertathead(head,2);
   insertathead(head,3);
   insertathead(head,4);
   insertAtTail(head,0);
   insertAtPosition(head,1,10);
   insertAtPosition(head,2,11);
   printnode(head);
   cout<<endl;
   deleteatAnyPoint(head,4);
   //deleteathead(head);
   //deleteattail(head);
   printnode(head);
   /*insertathead(head,99);
   printnode(head);*/
}