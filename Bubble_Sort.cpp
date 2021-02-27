#include <iostream>

void sort(int a[], int n); //function for sorting

void display(int a[], int n); //function for display array after sorting


int main(){

	int n;

	std::cout << "Enter the size of the array : ";
	std::cin >> n;

	int a[n]; //this process will not work without gcc compiler

	std::cout << "Enter the array : " << std::endl;

	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}

	sort(a, n); //calling function

	display(a, n); //calling function

	return 0;
}

void sort(int a[], int n){
	
	int temp;

	//main work started from below
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1-i; j++){
			if(a[j] > a[j+1]){
				
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			
			}
		}
	}
}

void display(int a[], int n){

	std::cout << "Sorted array : ";

	for(int i = 0; i < n; i++){
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
