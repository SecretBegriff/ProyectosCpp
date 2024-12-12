#include <iostream>
#include <vector>

using namespace std;

int busquedaBinaria(vector<int> n, int target, bool searchfirst){
    int left = 0, right = n.size()-1;
    int res = -1;

    while(left <= right){
        int mid = left + (right-left) / 2;
        if(n[mid] == target){
            res = mid;
            if(searchfirst){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else if(target < n[mid]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    return res;
}


int main(){
    vector<int> nums = {1, 2, 2, 5, 5, 5, 11, 11, 11, 11};
    cout << "Ingresa el numero a contar\n";
    int x;
    cin >> x;

    int menor = busquedaBinaria(nums, x, true);
    if(menor == -1){
        cout << "El numero no aparece en la lista\n";
    }
    else{
        int mayor = busquedaBinaria(nums, x, false);
        int conteo = mayor - menor + 1;
        cout << "El numero aparece " << conteo << " veces en la lista\n";

    }

    return 0;
}