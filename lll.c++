#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n=5;
    for(int i=0; i<n; i++){
        if(i%2!=0){
           arr[i] = arr[i]*2;
        }
        else{
            arr[i]=arr[i]+10;
        }
    }
    cout<<"Modified array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}