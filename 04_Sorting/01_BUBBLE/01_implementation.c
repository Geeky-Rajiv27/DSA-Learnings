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
    printf("Array before bubble sort : \t");
    for(int i = 0; i < 5; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    // implementing bubble sort
    for(int i = 0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp ;
            }
        }
    }
    printf("Array after BUBBLE sort : \t");
   for(int i = 0; i < 5; i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}