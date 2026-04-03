#include<stdio.h>
#include<stdlib.h>

void swap(int arr[], int a,int b){ // int a = root , b = largest
    int temp = arr[b] ;
    arr[b] = arr[a] ;
    arr[a] = temp ;
}

    //implementing max heapify method to perform Heap Sort
 void MaxHeapify(int arr[], int n, int i){ // n = size , i = largest element index
    int largest = i ;
    int l = (2*i) ; // this is to determine the index of left child of the largest index element i
    int r = (2*i) + 1 ; // for determining the index of right child of that  ''    ''    ''
    if(l<= n && arr[l] > arr[largest]){
        largest = l ;
    }
    if(r<= n && arr[r] > arr[largest]){
        largest = r ;
    }
    if(largest != i){
        swap(arr,i,largest); // for swaping the last element with the largest top root element
        MaxHeapify(arr, n, largest);
    }
 }

void HeapSort(int arr[],int n){ 
    // NOTE : this for loop is responsible for building a maxheap
    for(int i=n/2; i>=1; i--){
        MaxHeapify(arr, n, i) ; // calling for building maxheap 
    }
    // NOTE : this for loop is responsible for deleting a maxheap[to get a sorted array]
    for(int i=n ; i>=2; i--){
        swap(arr,1,i) ; // sending i means the index of the last element so that it can be swapped 
        //from the top root element
        MaxHeapify(arr, i-1, 1); // i that is size(n) must decrease after each swap 
    }

    //printing the sorted array 
    printf("\nThe elements of the array after Heapsort is : \t");
    for(int i=1 ; i<=n ;i++){
        printf("%d, ",arr[i]);
    }    
}

int main(){
    int n ;
    printf("Enter the size of the array you want to create : \t");
    scanf("%d", &n);
    int arr[n+1] ;
    printf("\nEnter the element for the array : \t");
    for(int i=1 ; i<=n ;i++){
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the array before Heapsort is : \t");
    for(int i=1 ; i<=n ;i++){
        printf("%d, ",arr[i]);
    }

    //Heap sorting the given array
    HeapSort(arr, n);

    return 0 ;
}