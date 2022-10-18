#include <stdio.h> 
#include <time.h>

//Bubblesort, selectionSort, QuickSort, MergeSort, radix, bin, shell e insert

//bubble sort normal

void bubbleSort(int numeros[], int n) {
    int i, j, aux;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) { 
            if (numeros[j] > numeros[j + 1]) {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }
}


//bubble sort mais eficiente
void bubbleSort2(int numeros[], int n) {
    int i, j, aux;
    for(i = n - 1; i >0; i--){
        for (j = 0; j < i; j++) { //MUDANÇA no for** não precisa percorrer o vetor inteiro
            if (numeros[j] > numeros[j + 1]) {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }
}


//selection sort normal
void selectionSort3(int numeros[], int n) {
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (numeros[j] < numeros[min]) {
                min = j;
            }
        }
        aux = numeros[i];
        numeros[i] = numeros[min];
        numeros[min] = aux;
    }
}

//selection sort mais eficiente
void selectionSort4(int numeros[], int n) {
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (numeros[j] < numeros[min]) {
                min = j;
            }
        }
        if (i != min) { //MUDANÇA no if**
            aux = numeros[i];
            numeros[i] = numeros[min];
            numeros[min] = aux;
        }
    }
}

//insertion sort normal
void insertionSort5(int numeros[], int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        aux = numeros[i];
        j = i - 1;
        while (j >= 0 && numeros[j] > aux) {
            numeros[j + 1] = numeros[j];
            j--;
        }
        
        numeros[j + 1] = aux; //MUDANÇA no j++
    }
}

//insertion sort mais eficiente
void insertionSort6(int numeros[], int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        aux = numeros[i];
        j = i - 1;
        while (j >= 0 && numeros[j] > aux) {
            numeros[j + 1] = numeros[j];
            j--;
        }
        if (j != i - 1) { //MUDANÇA no if** 
        //se o valor de j for diferente do valor de i-1, significa que houve troca
            numeros[j + 1] = aux;
        }
    }
}

//Quick sort normal
void quickSort7(int numeros[], int inicio, int fim) {
    int i, j, pivo, aux;
    i = inicio;
    j = fim - 1;
    pivo = numeros[(inicio + fim) / 2];
    while (i <= j) {
        while (numeros[i] < pivo && i < fim) {
            i++;
        }
        while (numeros[j] > pivo && j > inicio) {
            j--;
        }
        if (i <= j) {
            aux = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = aux;
            i++;
            j--;
        }
    }
    if (j > inicio) {
        quickSort7(numeros, inicio, j + 1);
    }
    if (i < fim) {
        quickSort7(numeros, i, fim);
    }
}

//Quick sort mais eficiente
void quickSort8(int numeros[], int inicio, int fim) {
    int i, j, pivo, aux;
    i = inicio;
    j = fim - 1;
    pivo = numeros[(inicio + fim) / 2];
    while (i <= j) {
        while (numeros[i] < pivo && i < fim) {
            i++;
        }
        while (numeros[j] > pivo && j > inicio) {
            j--;
        }
        if (i <= j) {
            aux = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = aux;
            i++;
            j--;
        }
    }
    if (j - inicio > 1) { //MUDANÇA no if**
        quickSort8(numeros, inicio, j + 1);
    }
    if (fim - i > 1) { //MUDANÇA no if**
        quickSort8(numeros, i, fim);
    }
}

//bin sort normal
void binSort9(int numeros[], int n) {
    int i, j, k, count, *aux;
    aux = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (numeros[j] < numeros[i]) {
                count++;
            } else if (numeros[j] == numeros[i] && j < i) {
                count++;
            }
        }
        aux[count] = numeros[i];
    }
    for (k = 0; k < n; k++) {
        numeros[k] = aux[k];
    }
    free(aux);
}

//bin sort mais eficiente
void binSort10(int numeros[], int n) {
    int i, j, k, count, *aux;
    aux = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (numeros[j] < numeros[i]) {
                count++;
            } else if (numeros[j] == numeros[i] && j < i) {
                count++;
            }
        }
        if (aux[count] != numeros[i]) { //MUDANÇA no if**
            aux[count] = numeros[i];
        }
    }
    for (k = 0; k < n; k++) {
        numeros[k] = aux[k];
    }
    free(aux);
}


//merge sort normal
void mergeSort11(int numeros[], int inicio, int fim) {
    int meio;
    if (inicio < fim - 1) {
        meio = (inicio + fim) / 2;
        mergeSort11(numeros, inicio, meio);
        mergeSort11(numeros, meio, fim);
        intercala11(numeros, inicio, meio, fim);
    }
}

//merge sort mais eficiente
void mergeSort12(int numeros[], int inicio, int fim) {
    int meio;
    if (fim - inicio > 1) { //MUDANÇA no if**
        meio = (inicio + fim) / 2;
        mergeSort12(numeros, inicio, meio);
        mergeSort12(numeros, meio, fim);
        intercala11(numeros, inicio, meio, fim);
    }
}

//shell sort normal
void shellSort13(int numeros[], int n) {
    int i, j, value;
    int gap = 1;
    do {
        gap = 3 * gap + 1;
    } while (gap < n);
    do {
        gap /= 3;
        for (i = gap; i < n; i++) {
            value = numeros[i];
            j = i - gap;
            while (j >= 0 && value < numeros[j]) {
                numeros[j + gap] = numeros[j];
                j -= gap;
            }
            numeros[j + gap] = value;
        }
    } while (gap > 1);
}

//shell sort mais eficiente
void shellSort14(int numeros[], int n) {
    int i, j, value;
    int gap = 1;
    do {
        gap = 3 * gap + 1;
    } while (gap < n);
    do {
        gap /= 3;
        for (i = gap; i < n; i++) {
            value = numeros[i];
            j = i - gap;
            while (j >= 0 && value < numeros[j]) {
                numeros[j + gap] = numeros[j];
                j -= gap;
            }
            if (j != i - gap) { //MUDANÇA no if**
                numeros[j + gap] = value;
            }
        }
    } while (gap > 1);
}

//radix sort normal
void radixSort17(int numeros[], int n) {
    int i, b[10], maior = numeros[0], exp = 1;
    for (i = 0; i < n; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }
    while (maior / exp > 0) {
        int bucket[10] = { 0 };
        for (i = 0; i < n; i++) {
            bucket[(numeros[i] / exp) % 10]++;
        }
        for (i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
        for (i = n - 1; i >= 0; i--) {
            b[--bucket[(numeros[i] / exp) % 10]] = numeros[i];
        }
        for (i = 0; i < n; i++) {
            numeros[i] = b[i];
        }
        exp *= 10;
    }
}

void intercala11(int numeros[], int inicio, int meio, int fim) {
    int *aux;
    int i, j, k;
    aux = (int*) malloc((fim - inicio) * sizeof(int));
    i = inicio;
    j = meio;
    k = 0;
    while (i < meio && j < fim) {
        if (numeros[i] <= numeros[j]) {
            aux[k] = numeros[i];
            i++;
        } else {
            aux[k] = numeros[j];
            j++;
        }
        k++;
    }
    while (i < meio) {
        aux[k] = numeros[i];
        i++;
        k++;
    }
    while (j < fim) {
        aux[k] = numeros[j];
        j++;
        k++;
    }
    for (i = inicio; i < fim; i++) {
        numeros[i] = aux[i - inicio];
    }
    free(aux);
}


void free(int *p) {
    if (p != NULL) {
        free(p);
    }
}

  