void Merge(int arr[], int lowerbound, int mid, int upperbound){
    int i = lowerbound ;
    int j = mid+1;
    int k = 0 ;

    // detemining size for the dummy array we need to create
    int size = (upperbound - lowerbound) + 1 ;

// creating an array to store sorted element of array a 
    int b[size] ;

    while(i <= mid && j <= upperbound){
        if(arr[i] <= arr[j]){
            b[k] = arr[i];
            i++ ;
        }else{
            b[k] = arr[j];
            j++ ;
        }
        k++ ; // this happens for both after if and else
    }

    if(i > mid){
        while(j <= upperbound){
            b[k] = arr[j] ;
            j++ ;
            k++ ;
        }
    }else{
        while(i <= mid){
            b[k] = arr[i];
            i++ ;
            k++ ;
        }
    }

    // copying the sorted element in the array a from array b
    for(int k = 0 ; k < size; k++){
        arr[lowerbound + k] = b[k] ; // copying each element
    }
}

void MergeSort(int arr[], int lb, int ub){
    if(lb < ub){ // recursive case
       int mid = (lb + ub) / 2 ;
    MergeSort(arr, lb, mid) ;//left sub array splitting and sorting
    MergeSort(arr, mid+1, ub); // right sub array splitting and sorting
    Merge(arr, lb, mid, ub) ; // To merge the left sub sorted array and right sub sorted array
    }  
}



#include<stdio.h>
int main()
{
    int size ;
    printf("Enter the size of the array you want to create : \t");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the element for the array you have created : \t");
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }

    printf("The element of array before MergeSort :\t");
       for(int i=0; i<size; i++){
        printf("%d\t",arr[i]);
    }   

    //Applying Merge sort algorithm
    int lb = 0 ;
    int ub = size-1 ;
    MergeSort(arr, lb, ub) ;

    // After sorting array
    printf("\nElements of array after sorting : \t");
    for(int i=0; i<size; i++){
        printf("%d\t",arr[i]);
    }
    return 0 ;
}