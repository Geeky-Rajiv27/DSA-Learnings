#include<stdio.h>

void swap(int arr[], int j_posi, int i_posi){       // j_posi = i+gap & i_posi = i
    int temp = arr[j_posi] ;
    arr[j_posi] = arr[i_posi] ;
    arr[i_posi] = temp ;
}

void shellsort(int arr[], int n){
    for(int gap = n/2; gap >= 1 ; gap = gap/2){
        for(int j=gap; j<n; j++){
            for(int i=j-gap; i>=0; i=i-gap){
                if(arr[i+gap] > arr[i]){
                    break; // this will exit out from the inner loop i
                }else{
                    swap(arr, i+gap, i); // swapping j, i index's elements
                }
            }
        }
    }

        //printing the sorted array 
    printf("\nThe elements of the array after Shell sorting is : \t");
    for(int i=0 ; i<n ;i++){
        printf("%d, ",arr[i]);
    }    
}

int main(){
        int n ;
    printf("Enter the size of the array you want to create : \t");
    scanf("%d", &n);
    int arr[n] ;
    printf("\nEnter the element for the array : \t");
    for(int i=0 ; i<n ;i++){
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the array before Shell Sorting is : \t");
    for(int i=0 ; i<n ;i++){
        printf("%d, ",arr[i]);
    }

    // calling shell sort function
    shellsort(arr, n) ;
}