#include <iostream>

void merge(int a[], int l, int m, int h);

void mergeSort(int arra[], int low, int high);

int main(){

    int size;

    std::cout << "Enter the size of the array : ";
    std::cin >> size;

    int myarra[size];

    std::cout << "Enter " << size << " num of elements : ";
    for(int i = 0; i < size; i++){
        std::cin >> myarra[i];
    }

    std::cout << "\nArray before sorting : ";
    for(int i = 0; i < size; i++){
        std::cout << myarra[i] << " ";
    }
    
    mergeSort(myarra, 0, size-1);

    std::cout << "\n\nArray after sorting : ";
    for(int i = 0; i < size; i++){
        std::cout << myarra[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}

void merge(int a[], int l, int m, int h){
    int i = l;
    int j = m + 1; 
    int k = l;
    int size = (h - l) + 1;
    int temp[size];

    while(i <= m && j <= h){
        if(a[i] <= a[j]){
            temp[k] = a[i];
            i++;
            k++;
        }
        else{
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while(i <= m){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j <= h){
        temp[k] = a[j];
        j++;
        k++;
    }

    for(int p = l; p <= h; p++){
        a[p] = temp[p];
    }
}

void mergeSort(int arra[], int low, int high){
    
    int mid;

    if(low < high){
        mid = (low + high) / 2;

        mergeSort(arra, low, mid);
        mergeSort(arra, mid+1, high);

        merge(arra, low, mid, high);
    }
}
