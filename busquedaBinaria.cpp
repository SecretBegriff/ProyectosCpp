#include <iostream>

using namespace std;

int busquedaBinaria(int arr[], int l, int h, int x){
    if(l > h){
        return -1;
    }

    int mid = l + (h-l)/2;
    cout << mid << endl;
    if(arr[mid] == x){
        return mid;
    }
    if(x < arr[mid]){
        return busquedaBinaria(arr, l, mid-1, x);
    }
    return busquedaBinaria(arr, mid+1, h, x);
}

int main(){
    int array[10] = {1, 2, 5, 7, 10, 12, 16, 20, 32, 50};
    int low = 0, high = 9;
    int x;

    cin >> x;
    
    int resultado = busquedaBinaria(array, low, high, x);

    if(resultado == -1){
        cout << "No esta ese numero en el arreglo" << endl;
    }
    else{
        cout << "El " << x << " esta en la posicion " << resultado << endl;
    }

    return 0;
}