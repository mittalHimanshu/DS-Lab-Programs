#include<iostream>
using namespace std;
void insertArray(int arr[],int size){
	int i;
	for(i=0;i<size;i++){
		cout<<"Enter elements : ";
		cin>>arr[i];
	}
}
void showArray(int arr[],int size){
	int i;
	for(i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void selectionSort(int arr[],int size){
	int i, j, min; 
    for (i = 0; i < size-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < size; j++){
			if (arr[j] < arr[min]){
            	min
				 = j;
            }
		}
		int temp = arr[min];
		arr[min]=arr[i];
		arr[i]=temp; 
    } 
}
void mergeArray(int arr1[], int arr2[], int size1,int size2, int arr3[]) 
{ 
    int i = 0, j = 0, k = 0;
    while (i<size1 && j <size2) 
    {  
        if (arr1[i] < arr2[j]) 
            arr3[k++] = arr1[i++]; 
        else
            arr3[k++] = arr2[j++]; 
    }
    while (i < size1) 
        arr3[k++] = arr1[i++];  
    while (j < size2) 
        arr3[k++] = arr2[j++]; 
} 
  
int main(){
	int arr1[10],arr2[10],size1,size2;
	cout<<"Enter size of Array 1 : ";
	cin>>size1;
	insertArray(arr1,size1);
	cout<<"Enter size of Array 2 : ";
	cin>>size2;
	insertArray(arr2,size2);
	selectionSort(arr1,size1);
	selectionSort(arr2,size2);
	int arr3[size1+size2];
	mergeArray(arr1,arr2,size1,size2,arr3);
	showArray(arr3,size1+size2);
	return 0;
}
