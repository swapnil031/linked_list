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
class queue{
    node *front;
    node *rear;
    public:
            queue(){
                this->front=NULL;
                this->rear=NULL;
            }
            void enqueue(int data){
                node *new_node=new node(data);
                if(front==NULL &&  rear==NULL){
                    front=new_node;
                    rear=new_node;
                    return;
                }
                rear->next=new_node;
                rear=new_node;
                return;
            }
            void dequeue(){
                node *temp=front;
                front=front->next;
                free(temp);
            }
            void display(){
                node* temp=front;
                while(temp!=NULL){
                    cout<<temp->data<<"->";
                    temp=temp->next;
                }
                cout<<"end";
                cout<<endl;
            }
};
int main(){
    queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(20);
    q1.dequeue();
    q1.display();
}