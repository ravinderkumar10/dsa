/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

void insertion(int arr[], int n){
    for(int i=0; i<n; i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
void selection(int arr[], int n){
    for(int i=0; i<n; i++){
        int mini = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        
        swap(arr[mini], arr[i]);
    }
}
void bubblesort(int arr[],  int n){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void merge(int arr[], int low, int mid, int high){
    int temp[10];
    int i =0;
    int left = low;
    int right = mid+1;
    while(left <=mid && right <= high){
        if(arr[left] <= arr[right]){
            temp[i] = arr[left];
            left++;
            i++;
        }
        else{
            temp[i] = arr[right];
            right++;
            i++;
        }
    }
    while(left <= mid){
        temp[i] = arr[left];
        left++;
        i++;
    }
    
    while(right <= high){
        temp[i] = arr[right];
        right++;
        i++;
    }
    
    for(int i=low; i<= high; i++){
        arr[i] = temp[i-low];
    }
}
void mergesort(int arr[], int low, int high){
    if(low >= high)
      return;
     
     int mid = (high+low)/2;
     mergesort(arr, low, mid);
     mergesort(arr, mid+1, high);
     merge(arr, low, mid, high);
}

int partition(int arr[], int low, int high){
    int piv = arr[low];
    int i = low;
    int j = high;
    
    while(i<j){
        while(arr[i] <= piv && i<high){
            i++;
        }
        while(arr[j] > piv && j > low){
            j--;
        }
        
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[low], arr[j]);
    
    return j;
}
void quicksort(int arr[], int low, int high){
    if(low >= high)
      return;
     
     int pivot = partition(arr, low, high);
     quicksort(arr, low, pivot-1);
     quicksort(arr, pivot+1, high);
}
int main()
{
    int n = 11;
    int arr[n] = {4, 71, 100, 1, 8, 3, 6, 9, 0, 5, 2};
    
    for(int i=0; i<n; i++){
        cout<< arr[i]<<" ";
    }
    
   // bubblesort(arr, n);
   // selection(arr, n);
   // insertion(arr, n);
  // mergesort(arr, 0, n-1);
  quicksort(arr, 0, n-1);
   
    cout<< endl;
    
     for(int i=0; i<n; i++){
        cout<< arr[i]<<" ";
    }
    return 0;
}