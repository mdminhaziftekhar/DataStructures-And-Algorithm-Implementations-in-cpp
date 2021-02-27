#include <iostream>

void displayArray(int a[], int size); //for outputting array

void swap(int *a, int *b); //for swapping 2 values

void sorts(int a[], int size); //for sorting

int main(){
    int n;

    std::cout << "Enter the size of the array : ";
    std::cin >> n;

    int arra[n];

    std::cout << "Enter the elements of the array : " << std::endl;

    for(int i = 0; i < n; i++){
        std::cin >> arra[i];
    }

    std::cout << std::endl;
    std::cout << "Array before sorting : ";
    displayArray(arra, n);

    sorts(arra, n);

    std::cout << std::endl;
    std::cout << "Array after sorting : ";
    displayArray(arra, n);

    return 0;
}

void displayArray(int a[], int size){
    for(int i = 0; i < size; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sorts(int a[], int size){
    for(int i = 0; i < size; i++){
        int cn = i;
        for(int j = i+1; j < size; j++){
            if(a[cn] > a[j]){
                cn = j;
            }
        }
        swap(&a[cn], &a[i]);
    }
}
