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
void swap(long long *xp, long long *yp)
{
    long long temp = *xp;
    *xp = *yp;
    *yp = temp;
}
long long partition (long long* arr, long long low, long long high)
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
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
/*--------------------FIN QUICK SELECT--------------------------------------*/
long long quickSelect(long long* arr, long long low, long long high, long long k){
    if (k > 0 && k <= high - low + 1) {
        long long index = partition(arr, low, high);
        if (index - low == k - 1)
            return arr[index];
        if (index - low > k - 1)
            return quickSelect(arr, low, index - 1, k);
        return quickSelect(arr, index + 1, high,k - (index + 1) + low);
    }
    return NULL;
}
/*--------------------FIN QUICK SELECT--------------------------------------*/
int main() {
    srand(time(0));
    long long *hola = new long long[arraySize];
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
    cout<<quickSelect(hola, 0, arraySize-1, 2)<<endl;
    final = clock();
    float duracion = (float(final - inicio)/(CLOCKS_PER_SEC/1000));
    cout<<"Demoro el ordenamiento: "<<duracion<<endl;
    return 0;
}
