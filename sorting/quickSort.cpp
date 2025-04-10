#include <iostream>
#include <algorithm> 
using namespace std;


int partition(int arr[], int low, int high){
    int pivot = low;
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<=high) i++;
        while(arr[j]>arr[pivot] && j>=0) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main(){
    int arr[] = {4,6,2,5,7,9,1,3};
    int low = 0;
    int high = sizeof(arr)/sizeof(arr[0])-1;

    quickSort(arr,low,high);

    return 0;
}