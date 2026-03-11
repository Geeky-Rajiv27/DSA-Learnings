
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ; 
    struct Node* prev ;
    struct Node* next ;
};
struct Node* head = NULL, *temp , *newnode ;
int count = 0;

struct Node* createNode(){

    newnode = (struct Node*) malloc(sizeof(struct Node));

    if(newnode == NULL){
        printf("Memory allocation failed ! \n");
        return NULL;
    }else{
        return newnode ;
    }
}

void insert_END(){
        newnode = createNode();
    printf("enter the value for data : \n");
    scanf("%d", &newnode->data);
    newnode->prev = 0 ;
    newnode->next = 0 ;
    
    if(head == 0){
        head = newnode ;
    }else{
        temp = head ;   // pointing temp to the location where head is pointing to.
        //temp->next bhaneko temp ley jaa point garexa tyo address ma kaei data xa ki nai ?
        // it doesn't mean ki tyo address ko node ko next ma k xa ?
        while(temp->next != NULL){  // reaching the last step 
            temp = temp->next ;
        }
        temp->next = newnode ; // connecting lastnode to the newnode
        newnode->prev = temp ; // connecting newnode to the lastnode
        
    }
    count = count + 1;
}

void insert_beginning(){
    temp = head ;
    newnode = createNode();
    printf("Enter the data : \t");
    scanf("%d", &newnode->data);
    newnode->prev = 0 ;
    newnode->next = head; 

    if(head != NULL){
        newnode->next = head ; // connecting newnode to the 1st node
        head->prev = newnode ; // connecting 1st node with newnode
    }
head = newnode ; // updating head that is pointing to the newnode which is now 1st node
count = count + 1 ;

}

void specific_position(){
    int posi ;
    printf("Enter the position where you want to insert : \t");
    scanf("%d",&posi);

    temp = head ;
    
    int i = 1 ;
    if(posi > count){
        printf("position is unexpected !\n");
        printf("Unfortunately, we have created only %d Node\n",count);
    }else{
        while(i < posi)
        {
            temp = temp->next ;// shifting temp to the 
            i++ ;
        }
        newnode = createNode() ;
        count = count + 1;
        printf("Enter the data of Node : \t");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;

        temp->next->prev = newnode ;// connecting node before which we want to inset the newnode
        newnode->next = temp->next ; // connecting newnode to the node before which we want to insert
        newnode->prev = temp ; // connecting newnode to the node after which we want to insert
        temp->next = newnode ;// connecting the node(after which we want to insert) to newnode
    }

}

void traverse(){
    temp = head ; // resetting the temp to the location where head is pointing to.
    int i = 1;
    while(temp != 0){
        printf("The value of node %d is %d , value of previous is %p & value of next is %p\n",i,temp->data,temp->prev, temp->next);
        temp = temp->next ;
        i++;
    }
}

int main(){
  int choice;
while(0 != 1){
    printf("\nPress : 1 ---> Insert at the end\n");
    printf("Press : 2 ---> Insert at the beginning\n");
    printf("Press : 3 ---> Insert at the specific position.\n");
    printf("Press : 4 ---> traverse\n");

    printf("Press : 5 ---> exit\n");

            printf("Enter where you want to insert : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:  insert_END();
                        break;
            case 2 : insert_beginning();
                        break;
            case 3 : specific_position();
                        break;
            case 4 : traverse();
                        break;
          
            case 5 : exit(0); 

            default: printf("Invalid choice !\n");
        }
     
}
   return 0;
}
