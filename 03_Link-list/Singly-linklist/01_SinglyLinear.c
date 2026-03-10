//-----------------------------------------------------------------------------------------------------------
//                      Arrays Vs linked list
//-----------------------------------------------------------------------------------------------------------
/**
                                Arrays
 1) Cost of accessing an element in arrays is cheaper since the time complexity is 0(1)     [since we don't have to travel and can directyly access using base address
 2) Memory utilization in arrays is poor since there will be waste of memory if not used all location to store items.
 3) Memory requirement is less in array for eg : we can store 7 data in 28 bytes
 4)Linear and binary search is possible .
 
 */

/**
            Linked list
 1) Cost of accessing an element in linked  - list is expensive since time complexity is 0(n) [since we have to travel first to reach that particulart node]
 2)Memory utilization in linked-list is effiecient because there is no waste of memory since we have to add newnode each type for every new item we want to store.
 3) Memory requirement is more in linked-list for eg : in order to store 7 data we will need 7 * 8 byte = 56 bytes since 1 node is of 8 bytes .like 4 byte to store item and 4 bytes to store address of another node
 4)Only Linear search is possible and binary search is not possible.


 */


//-----------------------------------------------------------------------------------------------------------
//disadvanges
//-----------------------------------------------------------------------------------------------------------
/*
 1) we cannot insert directly to the last node we must traverse.
 */


//-----------------------------------------------------------------------------------------------------------
//                                      OPERATION
//-----------------------------------------------------------------------------------------------------------
/*
 1)Creation
 2)Insertion
 3)Deletion
 4)Tranversing
 5)searching or finding
 6)Concatenation
 */

//-----------------------------------------------------------------------------------------------------------
//Implementation of linklist
//-----------------------------------------------------------------------------------------------------------
/*
#include<stdio.h>
#include<stdlib.h>  // required for dynamic memory allocation
struct node{
    int data ;
    struct node* next ;
};

struct node *head = NULL , *newnode , *temp;

// making a head pointer which is initially empty so we need to make it 0 (better)
// here newnode is for helping for connecting head to newly created newnode

  // now dynamically allocating memory to a just created  newnode
struct node* createNode() {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));

    if (newnode == NULL) {      // sometimes malloc provides newnode with null due to segmentation failure so we need to check 
        printf("Memory allocation failed\n");
        return NULL;
    }

    return newnode; // this will return address of newnode of struct node type 
}


int main(void)
{
   
    //creating node 1

     newnode =  createNode(); // creating a newnode
    printf("Enter data : \t");
    scanf("%d", &newnode->data);//putting data 5 in the newly created node
    newnode->next = NULL; // putting next  = null
    
    // here we will make empty head node point to the newly created node
    if(head == 0)
    {   // newnode has the address of node1
        head = temp = newnode ;    // this means now head is poiting to newly created node also temp is poiting to newnode
    }
    else{   // adding node2 at the end
        temp->next = newnode ;  // now node1 is pointing to last node
        temp = newnode ;
   }

   //inserting node 2 at the end
   newnode = createNode() ;
   
   printf("Enter data for node2 : \t");
   scanf("%d", &newnode->data);
   newnode->next = NULL ;
     // adding node2 at the end
        temp->next = newnode ;  // now node1 is pointing to last node
        temp = newnode ;


   //checking the value of node1 and node2
   printf("The value of node 1 is (%d) and address in next is %p\n",head->data,(void*)head->next);
   printf("The value of node 2 is (%d) and address in next is %p\n",newnode->data,(void*)newnode->next);


    return 0;
}
 */
//-----------------------------------------------------------------------------------------------------------
//  Doing same program using loops
//-----------------------------------------------------------------------------------------------------------
/*

#include<stdio.h>
#include<stdlib.h>  // required for dynamic memory allocation
struct node{
    int data ;
    struct node* next ;
};

struct node *head = NULL , *newnode , *temp;

// making a head pointer which is initially empty so we need to make it 0 (better)
// here newnode is for helping for connecting head to newly created newnode

  // now dynamically allocating memory to a just created  newnode
struct node* createNode() {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));

    if (newnode == NULL) {      // sometimes malloc provides newnode with null due to segmentation failure so we need to check 
        printf("Memory allocation failed\n");
        return NULL;
    }

    return newnode; // this will return address of newnode of struct node type 
}


int main(void)
{
   
   for(int i = 1; i<=2 ; i++)
   {
    
      newnode =  createNode(); // creating a newnode
    printf("Enter data for node %d : \t",i);
    scanf("%d", &newnode->data);//putting data 5 in the newly created node
    newnode->next = NULL; // putting next  = null
    
    // here we will make empty head node point to the newly created node
    if(head == 0)
    {   // newnode has the address of node1
        head = temp = newnode ;    // this means now head is poiting to newly created node also temp is poiting to newnode
    }
    else{   // adding node2 at the end
        temp->next = newnode ;  // now node1 is pointing to last node
        temp = newnode ;
   }
    
   }

   //checking the value of node1 and node2
   printf("The value of node 1 is (%d) and address in next is %p\n",head->data,(void*)head->next);
   printf("The value of node 2 is (%d) and address in next is %p\n",newnode->data,(void*)newnode->next);


    return 0;
}


*/


//-----------------------------------------------------------------------------------------------------------
//              Practicing same quesitons
//-----------------------------------------------------------------------------------------------------------

/*
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node* next ;
};

struct Node* head = NULL, *temp , *newnode ;

// func;tion to create newnode
struct Node* createNode(){
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)) ;

  if(newnode == NULL){
    printf("Memory allocation failed !\n");
    return NULL;
  }
  return newnode ;
}

int main()
{
   for(int i = 0 ; i<2 ; i++){
    newnode = createNode();
    printf("Enter the data for node %d\t",i+1);
    scanf("%d", &newnode->data);
    newnode->next = NULL ;

    if(head == 0){
        head = temp = newnode ;
    }else{
        temp->next = newnode ;
        temp = newnode ;
    }
   }

   //printing the data and addresses of the nodes
   printf("The data of the node 1 : (%d) and it's address is (%p) \n",head->data,head->next);
   printf("the data of the node 2 : (%d) and it's address is (%p) \n:",newnode->data, newnode->next);
   return 0;
}
*/


//-----------------------------------------------------------------------------------------------------------
//    inserting in the beginning of already existed linked-list
//-----------------------------------------------------------------------------------------------------------

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
    count = count + 1;

        printf("Enter the data for Node \t");
        scanf("%d",&newnode->data);
        newnode->next = NULL ;

        newnode->next = temp ;
        head = newnode ;
}

void insert_END(){
        newnode = createNode();
        count = count + 1;
        printf("Enter the data for Node : \t");
        scanf("%d",&newnode->data);
        newnode->next = NULL ;

       if(head == NULL){
            head = temp = newnode ;
        }else{
            temp->next = newnode ;
            temp = newnode ;
        }

 
}

void specific_position(){
        //again resetting the temp back to the 1st node
        temp = head ;
    count = count + 1;
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

int main(){
    //inserting in the beginning of the list
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



