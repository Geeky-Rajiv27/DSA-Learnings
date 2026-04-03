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
    printf("Array before Insertion sort : \t");
    for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    // implementing insertion sort
   for(int i=1; i<size;i++){
    temp = arr[i] ;
    int j = i -1 ;
    while(j >= 0 && arr[j] < temp){
        arr[j+1] = arr[j];
        j-- ;
    }
    arr[j+1] = temp ;
   }

    printf("Array after Insertion sort : \t");
   for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}