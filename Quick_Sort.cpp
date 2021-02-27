#include <iostream>

int partition(int arra[], int low, int high); //function for partitioning

void swap(int *a, int *b); //function for swapping

int quickSort(int arra[], int low, int high); // function for recursive iterations while sorting

void displayArray(int arra[], int n); //function for displaying the array

int main(){
    //int arra[] = {7, 6, 7, 5, 9, 2, 1, 15, 10};
    //int n = sizeof(arra) / sizeof(arra[0]); these 2 lines are for static code

    int n;
    std::cout << "Enter the size of the array : ";
    std::cin >> n;
    int arra[n];
    std::cout << "Enter the elements of the array : " << std::endl;
    for(int i = 0; i < n; i++){
        std::cin >> arra[i];
    }

    std::cout << "Input array is : ";
    displayArray(arra, n);
    std::cout << std::endl;

    quickSort(arra, 0, n-1);

    std::cout << "Array sorted with quicksort algorithm : ";

    displayArray(arra, n);

    return 0;
}

void displayArray(int arra[], int n){
    for(int i = 0; i < n; i++){
        std::cout << arra[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int arra[], int low, int high){
    int pivot = arra[low];
    int start = low;
    int end = high;

    while(start < end){
        while(arra[start] <= pivot){
            start++;
        }
        while(arra[end] > pivot){
            end--;
        }
        if(start < end){
            swap(&arra[start], &arra[end]);
        }
    }
    swap(&arra[low], &arra[end]);

    return end;

}

int quickSort(int arra[], int low, int high){

    if(low < high){
        int loc = partition(arra, low, high);
        quickSort(arra, low, loc-1);
        quickSort(arra, loc+1, high);
    }

}

void swap(int *a, int *b){
    int t = *a;

    *a = *b;

    *b = t;

}
