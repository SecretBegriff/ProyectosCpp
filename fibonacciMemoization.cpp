#include <iostream>
#include <vector>

using namespace std;

int fib[100];

int fibonacci(int n){ 
    if(n<=1){
        return n;
    }
    if(fib[n] != -1){
        return fib[n];
    }
    fib[n] = fibonacci(n-1) + fibonacci(n-2);
    return fib[n];
}


int main(){
    for(int i = 0; i < 100; i++){
        fib[i] = -1;
    }

    int n;
    cin >> n;

    int res = fibonacci(n);
    cout << res;
    return 0;
}