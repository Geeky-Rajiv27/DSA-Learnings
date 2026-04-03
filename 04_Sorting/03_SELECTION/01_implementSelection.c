#include<stdio.h>
int main(){
    int temp ;
    int size ;
    printf("Enter the size for the array you want to create : \t");
    scanf("%d", &size);
    int arr[size] ;

    printf("Enter the element for the array : \t");
    for(int i = 0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    printf("Array before Selection sort : \t");
    for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    // implementing Selection sort
  for(int i=0; i<size-1; i++)
  {
    int min = i ;
    for(int j=i+1; j<size; j++)
    {
        if(arr[j] < arr[min]){
            min = j ;
        }
    }
    if(min != i){
        temp = arr[min] ;
        arr[min] = arr[i] ;
        arr[i] = temp ;
    }
  }

    printf("Array after Selection sort : \t");
   for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}