#include <iostream>
#include <vector>

using namespace std;

char search(vector<char>& letters, char target){
    int low = 0, high = letters.size()-1;

    while(low < high){
        int mid = low + (high-low) / 2;
        if(target < letters[mid]){
            high = mid-1;
        }
        if(target)
    }

    return

}


int main(){
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    char resultado = search(letters, target);

    cout << resultado;
    
    return 0;
}