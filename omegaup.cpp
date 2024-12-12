#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int binarySearch(int arr[], int start, int end, int x){
    int mid;

    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == x){
            return mid;
        }
        else if(x < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return -1;
}

int main(){
    int arreglo[10] = {2, 5, 7, 10, 15, 21, 30, 31, 44, 50};
    int x;
    cin >> x;

    cout << binarySearch(arreglo, 0, 9, x);

    return 0;

}