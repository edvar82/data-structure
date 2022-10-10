#include <stdio.h> 

//bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i=n-1;i>0;i--){

        for(j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}

//selection sort
void selectionSort(int arr[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(){
    int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
    int i;
    bubbleSort(arr, 10);
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}