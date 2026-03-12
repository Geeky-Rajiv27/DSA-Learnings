#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node* prev ;
    struct Node* next ;
};

struct Node*head = NULL, *temp, *newnode; 
int count = 0 ;

struct Node* createNode(){
    newnode = (struct Node*) malloc(sizeof(struct Node));
    if(newnode == NULL){
        printf("Memory allocation failed !\n");
        return NULL ;
    }else{
        return newnode ;
    }
}

void insert_beginning(){
    newnode = createNode() ;
    printf("Enter the data for node : \t");
    scanf("%d", &newnode->data);
    if(head == NULL){
        head = newnode ;
        newnode->prev = NULL ;
        newnode->next = NULL ;
        count++ ;
    }else{
        temp = head ;
        while(temp->next != head){      // reaching the last node
            temp = temp->next ; // updating temp 
        }
        newnode->prev = temp ; // connecting newnode with the last node
        newnode->next = head ;// connecting newnode with 1st node
        temp->next = newnode ;// connecting last node with newnode 
        head->prev = newnode ; // connecting 1st node with newnode 
        head = temp->next ; // pointing the newly added node by head node using last node connection pointed by temp
        count ++ ;
    }
}

void insert_specific(){
    int posi ;
    int i = 1 ;
    printf("Enter the position where you wnat to insert a new node : \t");
    scanf("%d", &posi);
    if(posi > count || posi <= 0){
        printf("Invalid position !\n");
        printf("Unfortunately we only have %d Nodes\n",count);
    }else if(posi == 1){
        insert_beginning();
        return ;
    }else{
        newnode = createNode();
        printf("Enter the data for the node : \t");
        scanf("%d", &newnode->data);
        temp = head ;
        while(i < posi)     // reaching to target - 1 position after which we have to insert
        {
            temp = temp->next ; // shifting temp toward right step by step
            i++ ;
        }
        newnode->next = temp->next ;// connecting (2)newnode with last node (3)
        newnode->prev = temp ; // connecting the (2)newnode with node(1)
        temp->next = newnode ; // connecting the node(1) with newnode (2)
        temp->next->prev = newnode ;// connecting the node(3) with newnode(2)
        count++ ;
    }
}

void insert_END(){
    newnode = createNode();
    printf("Enter the data for node : \t");
    scanf("%d", &newnode->data);
if(head == NULL){
    head = newnode ;
    newnode->prev = NULL ; 
    newnode->next = newnode ; // connecting to self [making doubliy circular of 1 node]
    count++ ;
}else{
    temp = head ;
 
    while(temp->next != head){ // trying to reach last node 
        temp = temp->next ;// updating temp 
    }
    newnode->prev = temp ; // connecting newnode with last node
    newnode->next = head ; // connecting newnode with 1st node 
    temp->next = newnode ;//conecting last node with newnode
    head->prev = newnode ; // connecting 1st node with newnode 
    count ++ ;
}
}

void traverse(){
    if(head == NULL){
        printf("LIst is empty\n");
        return;
    }
    temp = head ; //resetting the temp to the location where head is pointing to
    int i = 1 ;
   
    do{
        printf("The data of the Node %d is (%d) , previous address is %p and next address is %p\n",i,temp->data, temp->prev, temp->next);
        temp = temp->next ;
        i++ ;
    } while(temp != head);
}

int main(){
        int choice;
while(0 != 1){
    printf("\nPress : 1 ---> Insert at the end\n");
    printf("Press : 2 ---> Insert at the beginning\n");
    printf("Press : 3 ---> Insert at the specific location\n");
    printf("Press : 4 ---> traverse\n");
    printf("Press : 5 ---> exit\n");

            printf("Enter where you want to insert : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:  insert_END();
                        break;
            case 2 : insert_beginning();
                        break;
            case 3 : insert_specific();
                        break;

            case 4 : traverse();
                        break;

            case 5 : exit(0); 

            default: printf("Invalid choice !\n");
        }
     
}
}