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

void delete_start(){
    if(head == NULL){
        printf("LIst is empty!, sorry!\n");
        return ;
    }else{
        while(temp->next != head)
        {
            temp = temp->next ; // updating the temp moving to right --> direction one by one node
        }
        temp->next = head->next ; // connecting the last node with the node(going to be 1st)
        head->next->prev = temp ; // connecting node(goint to be 1st) with last node
        temp = head ;// resetting the temp to the node which is to be deleted
        head = temp->next ; // updating head to the node(going to become 1st node)
        free(temp); // deleteing the node
        count--;
    }
}

void delete_specific(){
    int del_posi ; 
    int i = 1 ;
    printf("Enter the position of node which you want to delete: \n");
    scanf("%d", &del_posi);
    if(head == NULL){
        printf("List is empty, Sorry cannot delete any node!\n");
    }else if(del_posi > count || del_posi <= 0){
        printf("Invalid position !\n");
        printf("Unfortunately, we only have %d Nodes\n",count);
    }else if(del_posi == 1){
        delete_start();
        return ;
    }else{
        struct Node *helper ;
        temp = head ; //resetting the temp
        while(i < del_posi - 1){
            temp = temp->next ;// reaching to the target-1 position 
            i++ ;
        }
        helper = temp->next ; // storing address the node to be deledted temporarily in a pointer
        temp->next = helper->next ;// connecting node(1) to node(3)
        helper->next->prev = temp ;// connecting node(3) to node(1)
        free(helper) ; // deleting the node
        count--;
    }
}

void delete_end()
{
if(head == NULL){
    printf("List is empty, Sorry cannot delete any node!\n");
}else{
    struct Node *carrier ;
    while(temp->next->next != head){ /// reaching to the 2nd last node 
        temp = temp->next ; // updating the temp 
    }
    carrier = temp->next ; // storing the address of last node temporarily in a pointer
    temp->next = head ; // connecting the 2nd last node with 1st node
    head->prev = temp ; // connecting the 1st node to node(goint to become last node)
    free(carrier);
    count--;
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
    printf("Press : 5 ---> Delete from the beginning\n");
    printf("Press : 6 ---> Delete from the specific location\n");
    printf("Press : 7 ---> Delete from end of the list.\n");
    printf("Press : 8 ---> exit\n");

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
            case 5 : delete_start();
                        break;
            case 6 : delete_specific();
                        break;
            case 7 : delete_end();
                        break;

            case 8 : exit(0); 

            default: printf("Invalid choice !\n");
        }
     
}
}