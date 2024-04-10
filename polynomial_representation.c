#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int coef;
    int expo;
    struct node* next;
}Node;
typedef struct polynomial{
    Node *head;
}polynomial;

//*todo CORRECT

void createnode(Node **head){
    int n,p,c;
    scanf("%d",&n);
    while(n>0){
       
        printf("enter the power");scanf("%d",&p);
        printf("enter the coef: ");scanf("%d",&c);
        if(*head==NULL){
            Node * new_node=(Node *)malloc(sizeof(Node));
            new_node->expo=p;
            new_node->coef=c;
            new_node->next=NULL;
            *head=new_node;
        }
        else{
            Node *ptr=*head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            Node * new_node=(Node *)malloc(sizeof(Node));
            ptr->next=new_node;
            new_node->coef=c;
            new_node->expo=p;
            new_node->next=NULL;
        }
        n--;
    }
    
}

//*todo CORRECT

void display(Node* head){
    Node *temp=head;
    while(temp!=NULL){
        printf("^%d%d ",temp->expo,temp->coef);
        temp=temp->next;
    }
}
int main(){
    //node *a;
    polynomial p1;
    p1.head=NULL;
    printf("Enter the no of terms for 1st polynomial:");
    createnode(&p1.head);
    //display(p1.head);
}