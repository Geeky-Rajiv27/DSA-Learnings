void swap(int arr[], int a, int b){         // a = start , b = end
    int temp ;
    temp = arr[b] ;
    arr[b] = arr[a] ;
    arr[a] = temp ;

}

int partition(int arr[], int lowerbound, int upperbound)
{
   int pivot = arr[lowerbound] ;
   int start = lowerbound ;
   int end = upperbound ;

   while (start < end)
   {
    while (arr[start] <= pivot && start <= upperbound)
    {
        start++ ;
    }
    while(arr[end] > pivot) {
        end -- ;
    }
   if(start < end){
    swap(arr, start, end) ; // swap element of start and end
   }
}
 swap(arr, lowerbound, end) ; // swapping lb(element) with end(element)
 return end;  
}

void QuickSort(int arr[], int lb, int ub){
    if(lb < ub){ // recursive case
      int  pivotloc = partition(arr,lb,ub); // calling for partitioning the array
        QuickSort(arr, lb, pivotloc-1); // calling for left partitioning 
        QuickSort(arr,pivotloc+1, ub); // calling for right partitioning 
    }else{
        return ; // base case
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

    printf("The element of array before QuickSort :\t");
       for(int i=0; i<size; i++){
        printf("%d\t",arr[i]);
    }   

    //Applying Quick sort algorithm
    int lb, ub ;
    lb = 0;// assuming 1st element of unsorted array given by user as lowerbound
    ub = size-1; // assuming last element of unsorted array given by user as upperbound
    QuickSort(arr, lb, ub);

    // After sorting array
    printf("\nElements of array after sorting : \t");
    for(int i=0; i<size; i++){
        printf("%d\t",arr[i]);
    }
    return 0 ;
}