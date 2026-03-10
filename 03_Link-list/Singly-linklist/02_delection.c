
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

void traverse()
{
    temp = head ;
       int i = 0;
    while(temp != NULL)
    {//printing the data and addresses of the nodes
           printf("The data of the node %d : (%d) and it's address is (%p) \n",i+1,temp->data,temp->next);
           temp = temp->next ;
    }
}

void delete_start(){
temp = head ;
head = temp->next ;
free(temp);     // delete the starting node
count-- ;

}

void delete_specific(){
int posi ;
struct Node * helper ;
printf("Enter the position of node which you want to delete\t");
scanf("%d",&posi);
    int i = 1 ;


    if(posi > count || posi <= 0){
        printf("position is unexpected !\n");
        printf("Unfortunately, we have created only %d Node\n",count);
    }else if(posi == 1){
            delete_start();
            return;
    }
    else{
        temp = head ;
    while(i < posi - 1)
    {
        temp = temp->next ;
        i++ ;
    }
      // after reaching the position
      helper = temp->next ;
      temp->next = helper->next;
      free(helper);  // deleting the specific node
       count--;
       temp =head ;
}
}

void TotalNode(){
    printf("There are total %d Nodes\n",count);
}

void delete_end(){
// case : if there is no list
    if(head == NULL){
        printf("List is empty\n");
        return ;
    }

    // case : if there is only one node
    if(head->next == NULL){
        free(head);
        head = NULL ;
        count-- ;
        return ;
    }

temp = head ;

while(temp->next->next != NULL){
    temp = temp->next ;
}
    // after reaching the position
     
      free(temp->next);  // deleting the specific node
      temp->next = NULL ;
       count--;

}

int main(){
    //inserting in the beginning of the list
   int choice;
while(0 != 1){
    printf("\nPress : 1 ---> Insert at the end\n");
    printf("Press : 2 ---> Insert at the beginning\n");
    printf("Press : 3 ---> Insert at the specific position.\n");
    printf("Press : 4 ---> traverse\n");
    printf("Press : 5 ---> Delete from the start position\n");
    printf("Press : 6 ---> Delete from the specific position.\n");
    printf("Press : 7 ---> Delete from the end position.\n");
    printf("Press : 8 ---> Check total node created\n");
    printf("Press : 9 ---> exit\n");




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
            case 5 : delete_start();
                        break;
            case 6 : delete_specific();
                        break;
            case 7 : delete_end();
                        break;
            case 8 : TotalNode();
                        break;

            case 9 : exit(0); 

            default: printf("Invalid choice !\n");
        }
     
}
   return 0;
}



