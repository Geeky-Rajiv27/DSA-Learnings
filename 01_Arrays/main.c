//----------------------------------------------------------------------------//
//                          Arrays
//----------------------------------------------------------------------------//

// traversal insertion operation of array
/*
#include <stdio.h>
int main(void)
{   int size = 0;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    int array[size];
    printf("enter the elements for the array : \t");
    for(int i = 0 ; i <= size - 1 ; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("The elements of the array are : \n");
    for (int i = 0; i <= size - 1; i++) {
        printf("%d ",array[i]);
    }
    return 0;
}
*/


//-------------------------------------------------------------------------------------------------------//
//                             Insertion
//-------------------------------------------------------------------------------------------------------//

// Inserting an element(10) in a location(3rd) of an array already containing elements
// Condition : the old element of that specific location mustn't be overwritten and should
//              be moved to n + 1 index forward
 //             given array = [6, 2, 0, 2, 4, 5.......]

/*
#include <stdio.h>
int main(void)
{
    int array[50], size = 0, pos = 0 ,numTOinsert = 0, targetPos = 0;
    
    printf("Enter the num you want to insert as a new value : \t");
    scanf("%d",&numTOinsert);
    
    printf("Enter the position in array where you want to insert new value : \n");
    scanf("%d", &pos); // pos = 1 ,2 ,3 ,4 ..... n
    
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    if(size > 50)
    {
        printf("Elements of array will get overflow. \n");  // checking upperbounds
    }else{
        printf("enter the elements for the array : \t");
        for(int i = 0 ; i <= size - 1 ; i++)
        {
            scanf("%d", &array[i]);
        }
        //conditions for position checking:
        for(int i=size+1; i >= pos- 1; i--)
        {
            array[i] = array[i-1] ;
            targetPos = i ; // storing the obtained position where we want to insert
        }
        // final : inserting part
        array[targetPos] = numTOinsert ;
        
        // Final outcome after operation
        printf("The elements of the array are : \n");
        for (int i = 0; i <= size; i++) {
            printf("%d ",array[i]);
        }
    }
  
    return 0;
}
*/

//-------------------------------------------------------------------------------------------------------//
//                  Deletion from specific Position.
//-------------------------------------------------------------------------------------------------------//

//Deleting an element of specific location given by user from a array of an elements also given by user
// of size also given by user.

/*
#include <stdio.h>
int main(void)
{
    int array[50], size = 0, pos = 0 ;  // pos = position to delete element
    
    
    printf("Enter the position of an element you want to delete : \n");
    scanf("%d", &pos); // pos = 1 ,2 ,3 ,4 ..... n
    
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    if(size > 50)
    {
        printf("Elements of array will get overflow. \n");  // checking upperbounds
    }else{
        printf("enter the elements for the array : \t");
        for(int i = 0 ; i <= size - 1 ; i++)
        {
            scanf("%d", &array[i]);
        }
        //conditions for position checking:
        for(int i=pos-1; i < size-1; i++)
        {
            array[i] = array[i+1] ; // ommiting the place of that position
        }

        // Final outcome after operation
        printf("The elements of the array are : \n");
        for (int i = 0; i <= size- 2 ; i++) {
            printf("%d ",array[i]);
        }
    }
  
    return 0;
}
*/

