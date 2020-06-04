#include <iostream>
#include <ctime>
using namespace std;
//imprimible
const long long arraySize = 10;
//pequeño
//const long long arraySize = 100;
//mediano
//const long long arraySize = 1000;
//grande
//const long long arraySize = 10000;
//realista
//const long long arraySize = 100000;
//gigante
//const long long arraySize = 1000000;
//nivel pro
//const long long arraySize = 10000000;
/*--------------------INICIO MERGE SORT--------------------------------------*/
void merge(long long *Arr, long long start, long long mid, long long end) {
    long long *temp = new long long[(end - start + 1)];
    long long i = start, j = mid+1, k = 0;
    while(i <= mid && j <= end) {
        if(Arr[i] <= Arr[j]) {
            temp[k] = Arr[i];
            k += 1; i += 1;
        }
        else {
            temp[k] = Arr[j];
            k += 1; j += 1;
        }
    }
    while(i <= mid) {
        temp[k] = Arr[i];
        k += 1; i += 1;
    }
    while(j <= end) {
        temp[k] = Arr[j];
        k += 1; j += 1;
    }
    for(i = start; i <= end; i += 1) {
        Arr[i] = temp[i - start];
    }
    delete temp;
}
void mergeSort(long long *Arr, long long start, long long end) {
    if(start < end) {
        long long mid = (start + end) / 2;
        mergeSort(Arr, start, mid);
        mergeSort(Arr, mid+1, end);
        merge(Arr, start, mid, end);
    }
}
/*--------------------FIN MERGE SORT--------------------------------------*/
void swap(long long *xp, long long *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/*--------------------INICIO QUICK SORT--------------------------------------*/
long long partition (long long *arr, long long low, long long high)
{
    long long pivot = arr[high];
    long long i = (low - 1);
    for (long long j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(long long* arr, long long low, long long high)
{
    if (low < high)
    {
        long long pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/*--------------------FIN QUICK SORT--------------------------------------*/
/*--------------------FIN QUICK SELECT--------------------------------------*/
long long quickSelect(long long* arr, long long low, long long high, long long k){
    if (k > 0 && k <= high - low + 1) {
        long long index = partition(arr, low, high);
        if (index - low == k - 1)
            return arr[index];
        if (index - low > k - 1)
            return quickSelect(arr, low, index - 1, k);
        return quickSelect(arr, index + 1, high,k - index + low - 1);
    }
    return NULL;
}
/*--------------------FIN QUICK SELECT--------------------------------------*/
/*--------------------INICIO BUBBLE SORT--------------------------------------*/
void bubbleSort(long long* arr, long long n) {
    long long i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap( arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
/*--------------------FIN BUBBLE SORT--------------------------------------*/
/*--------------------INICIO INSERTION SORT--------------------------------------*/
void insertionSort(long long* arr, long long n)
{
    long long i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
/*--------------------FIN INSERTION SORT--------------------------------------*/
/*--------------------INICIO SELECTION SORT--------------------------------------*/
void selectionSort(long long* arr, long long n)
{
    long long i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
/*--------------------FIN SELECTION SORT--------------------------------------*/
int main() {
    srand(time(0));
    long long * hola = new long long[arraySize];
    for (long long i = 0; i < arraySize; ++i) {
        hola[i] = rand()%(arraySize + 50) + 1;
    }
    if(arraySize <=10){
        for (long long j = 0; j < arraySize; ++j) {
            cout<<hola[j]<<" ";
        }
        cout<<endl;
    }
    unsigned inicio, final;
    inicio = clock();
    quickSort(hola, 0, arraySize - 1);
    final = clock();
    float duracion = (float(final - inicio)/(CLOCKS_PER_SEC/1000));
    cout<<"Demoro el ordenamiento: "<<duracion<<endl;
    if(arraySize <= 10){
        for (long long j = 0; j < arraySize; ++j) {
            cout<<hola[j]<<" ";
        }
    }
    return 0;
}
