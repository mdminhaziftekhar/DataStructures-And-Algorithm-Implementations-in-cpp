#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,arra[100],size,number;
    cout<<"Enter the size of the array : ";
    cin>>size;

    int low=0, high = size-1, mid;
    cout<<"Enter array : "<<endl;

    for(i=0; i<size; i++){
        cin>>arra[i];
    }

    sort(arra, arra+size); //Sorted the array for binary search

    cout<<"Array after sorting : "<<endl;
    for(i=0; i<size; i++){
        cout<<arra[i]<<endl;
    }
    cout<<"Enter the number to find : ";
    cin>>number;

    while(low<=high){
        mid = (low+high)/2;
        if(number == arra[mid]){
            break;
        }
        if(number < arra[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }

    if(low>high){
        cout<<"The number was not found in the array"<<endl;
    }
    else{
        cout<<"The number was found in the position "<<mid+1<<endl;
    }


    return 0;
}
