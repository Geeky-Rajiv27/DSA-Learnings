//-------------------------------------------------------------------------------------------------------//
//                                          2D  Arrays and pointers
//-------------------------------------------------------------------------------------------------------//

/*🔹 Question 1 (Basic pointer access)
 
 Create a 2D array of size 3×3.
 Using only pointers (no arr[i][j]),

 do the following:

 Input all elements from the user
 Print the matrix
 Print the element at row 2, column 3 using pointer arithmetic

 📌 Hint focus: *(*(arr + i) + j)
 */

/*
#include<stdio.h>
int main(void)
{
    int arr[3][3];
    int *p = &arr[0][0] ;
    
    printf("enter the elements of the array : \n");
    for (int i=0; i < 3; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d", (p + (i * 3) + j));
        }
        printf("\n");
    }
    
    //printing the value of the 2D array
    for (int i=0; i < 3; i++) {
        for (int j=0; j<3; j++) {
            if(i == 1 && j == 2)
            {
                printf("The value is : %d", *(p + (i * 3) + j));
            }
        }
        printf("\n");
    }
    return 0;
}
*/


//-------------------------------------------------------------------------------------------------------//


/*
 🔹 Question 2 (Function + pointer to 2D array)

 Write a function that accepts a 2D array using pointers and:

 Finds the sum of all elements
 Finds the largest element in the matrix

 In main():

 Declare a 2D array of size 3×4
 Pass it to the function using a pointer

 📌 Focus: function parameter like
 void process(int (*arr)[4], int rows)
 */

/*
#include<stdio.h>

void process(int (*p)[4], int rows) // (*p)[4]  means declaring a pointer p to an array of 4 ints
{
//(*p)[4]  also means int *p = &arr[][4]
    int sum = 0 ;
    printf("The elements of the 2D array are : \n");
    for (int i = 0; i<3; i++) {
        for (int j = 0; j < 4; j++) {
            sum  = sum + *(*(p+i)+j) ;
        }
    }
    
    //checking largest value :
    int max = *(*p) ;   // max = a[0][0]
    for (int i = 0; i<3; i++) {
        for (int j = 0; j < 4; j++) {
            if(max < *(p[i] + j))
               {
                   max = *(p[i] + j) ;
            }
        }
    }
    
    printf("The sum of elements of 2D array is : %d\n",sum);
    printf("The max value in a 2D array is : %d\n", max);
}

int main(void)
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    } , rows = 3;

    process(arr, rows);
}
*/

//-------------------------------------------------------------------------------------------------------//
/*
 Question 1 – Row & Column Sums

 Write a function that accepts a 2D array via a pointer and:

 Calculates sum of each row and prints it.

 Calculates sum of each column and prints it.

 Use int (*arr)[COLS] for function parameter.
 */


#include<stdio.h>
void rowSum(int(*p)[3], int rows, int cols)
{
   
    for (int i= 0 ; i < rows; i++) {
        int Rowsum = 0 ;
        for (int j = 0; j < cols; j++) {
            Rowsum = Rowsum + (*(p[i]+j));
        }
        printf("The sum of  row(%d) is : %d\n",i+1,Rowsum);
        }
    printf("\n");
    
    //sum of columns
    for (int j= 0 ; j < cols; j++) {
        int Colsum = 0 ;
        for (int i = 0; i < rows; i++) {
            Colsum = Colsum + (*(p[i]+j));
        }
        printf("The sum of column (%d) is : %d\n",j+1,Colsum);
    }
}


int main(void)
{
    int rows = 3 , cols = 3 ;
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    rowSum(arr, rows, cols);
    return 0;
}
