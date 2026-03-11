
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ; 
    struct Node* next ;
};
struct Node* head = NULL, *temp , *newnode ;
int count = 0;

struct Node* createNode(){

    newnode = (struct Node*) malloc(sizeof(struct Node));

    if(newnode == NULL){
        printf("Memory allocation failed ! \n");
        return NULL;
    }
    return newnode ;
}

void insert_beginning(){
    temp = head ;
    newnode = createNode();
   

        printf("Enter the data for Node \t");
        scanf("%d",&newnode->data);
        newnode->next = NULL ;

        newnode->next = temp ;
        head = newnode ;
         count = count + 1;
}

void insert_END(){
        newnode = createNode();
        
        printf("Enter the data for Node : \t");
        scanf("%d",&newnode->data);
        newnode->next = NULL ;

       if(head == NULL){
            head = temp = newnode ;
            count = count + 1 ;
        }else{
            temp->next = newnode ;
            temp = newnode ;
            count = count + 1;
        }

 
}

void specific_position(){
        //again resetting the temp back to the 1st node
        temp = head ;
    
    int posi ;
    printf("Enter the location where you want to insert the node : \t");
    scanf("%d",&posi);      // remember if user gives 2 then it means we gonna add insert node after 2nd node
    int i = 1 ;
    if(posi > count){
        printf("position is unexpected !\n");
        printf("Unfortunately, we have created only %d Node\n",count);
    }else{
    while(i < posi)
    {
        temp = temp->next ;
        i++ ;
    }
        newnode = createNode();

    printf("Enter the data for the node : \t");
    scanf("%d", &newnode->data);

    newnode->next = temp->next ;    // connecting the newnode to the last node 
    temp->next = newnode ;  //connecting node before newnode to the newnode
    count = count + 1;
}
}

  struct Node* prev = 0, *nextnode , *currentnode ;
// Reverse linked-list
void ReverseList(){
  
    currentnode = nextnode = head ;
    while(nextnode != 0){
        nextnode = currentnode->next ; // updating nextnode
        currentnode->next = prev ;  // storing address of previous node
        prev = currentnode ; // shifting prevoius node
        currentnode = nextnode ; // shifting currentnode
    }
    head = prev ;
}

void traverse()
{
    temp = head ;
       int i = 1;
    while(temp != NULL)
    {//printing the data and addresses of the nodes
           printf("The data of the node %d : (%d) and it's address is (%p) \n",i,temp->data,temp->next);
           temp = temp->next ;
           i++ ;
    }
}


int main(){
  int choice;
while(0 != 1){
    printf("\nPress : 1 ---> Insert at the end\n");
    printf("Press : 2 ---> Insert at the beginning\n");
    printf("Press : 3 ---> Insert at the specific position.\n");
    printf("Press : 4 ---> traverse\n");
    printf("Press : 5 ---> reverse linked-list\n");

    printf("Press : 6 ---> exit\n");

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
            case 5 : ReverseList();
                        break;
          
            case 6 : exit(0); 

            default: printf("Invalid choice !\n");
        }
     
}
   return 0;
}