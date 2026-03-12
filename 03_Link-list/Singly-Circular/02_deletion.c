#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node* next ;
};

struct Node* head = NULL, *temp, *newnode ;
int count = 0 ;

struct Node* createNode(){
newnode = (struct Node*) malloc(sizeof(struct Node)) ;
if(newnode == NULL){
    printf("Memory allocation failed!\n");
    return NULL ;
}else{
    return newnode ;
}
}

void insert_END(){
    newnode = createNode() ;
    printf("Enter the data for the node : \t");
    scanf("%d", &newnode->data);
    if(head == NULL){
        head = temp = newnode ;
        newnode->next = head ;
    }else{
        temp = head ; // resetting the position of temp to the location where head is pointing since we have to traverse in this case 
        // now need to reach the 2nd last node 
        while(temp->next != head){
            temp = temp->next ;
        }
     
        newnode->next = head ; // connecting the new last node with the 1st node
        temp->next = newnode; // connecting the prevous last node with new last node 
        count++ ;
    }
}

void insert_beginning(){
        newnode = createNode() ;     
        printf("Enter the data for the node : \t");
        scanf("%d", &newnode->data);
    if(head == NULL){
        head = temp = newnode ;
        count ++ ;
    }else{
        while(temp->next != head){
            temp = temp->next ; // reaching the last node position 
        }
        newnode->next = head ;// connecting the new node to be inserted with the the node head is pointing (1st node)
        temp->next  = newnode ; // connecting the 1st node with newnode 
        head = newnode ;// now head is pointing to newly inserted node that is 1st node
        count ++ ;
    }
}



void insert_specific(){
    int specific_posi ;
    int i = 1;
    printf("Enter the position where you want to insert the node : \t");
    scanf("%d", &specific_posi);
    if(specific_posi > count || specific_posi <= 0){
        printf("INvalid position !\n");
        printf("Unfortunately we only have %d Nodes\n",count);
    }else if(specific_posi == 1){
        insert_beginning();
        return ;
    }else {
        temp = head ; // resetting temp 
        // reaching to the specific_location - 1 (i.e ; 2nd last node) after which we have to insert
        while(i < specific_posi){
            temp = temp->next ; // updating temp till we reach target position
            i++ ;
        }
        newnode = createNode() ;
        count ++ ;
        printf("Enter the data for the node : \t");
        scanf("%d", &newnode->data);

        newnode->next = temp->next ;// connecting the last node with newnode
        temp->next = newnode ;// conecting the node of target location with the newly inserting node
    }
}

void delete_start()
{
    if(head == NULL){
        printf("There is no node to delete. Linked-list is empty !\n");
    }else{
        temp = head ; // resetting temp 
    while(temp->next != head){  // reaching last node
        temp = temp->next ;
    }
    temp->next = head->next ; // connecting last node to new 1st node that is previous 2nd node
    temp = head ; // again resetting temp to the location where head is pointing to (1st node) which is to be deleted
    head = temp->next ;// shifting head to the new 1st ndoe that is previous 2nd node
    free(temp) ; // deleting the 1st node.
    count -- ;
    }
}

void delete_specific(){
int del_posi ;
int i = 1 ;
struct Node* helper ;
printf("Enter the position from where you want to delete : \t");
scanf("%d", &del_posi);
if(del_posi > count || del_posi <= 0){
    printf("position is unexpected !\n");
    printf("Unfortunately, we have created only %d Node\n",count);
}else if(del_posi == 1){
    delete_start();
    return;
}else{
temp = head ;
    while( i < del_posi -1){
        temp = temp->next ;
        i++ ;
    }
    // let node to be deleted : 2
    // let node before node 2 is node 1
    // let node after node 2 : is node 3
    helper = temp->next;
    temp->next = helper->next ; // connecting the node 1 with node 3
    free(helper) ;
    count -- ;
}
}

void delete_end(){
    temp = head ;
    struct Node* carrier ;
     if(head == NULL){
        printf("There is no node to delete. Linked-list is empty !\n");
    }else{
    while(temp->next->next != head){ // reaching 2nd last node
        temp = temp->next ;
    }
    carrier = temp->next ;// storing the node in a pointer temporarily that is to be deleted
    temp->next = head ;// pointing the node (going to be last node) to 1st node using head
    free(carrier) ;
    count--;
    }
}

void traverse(){
    temp = head ; // resetting temp
    int i = 1 ;
    do{
        printf("Value of Node %d is : %d and address of next node is : %p\n",i,temp->data, temp->next);
        temp = temp->next ; // shifting temp one node by node
        i++ ;
    }while(temp != head);
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
   return 0;
}