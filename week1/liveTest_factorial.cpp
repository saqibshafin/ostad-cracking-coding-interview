#include <iostream>

using namespace std;

long long factorial(int);

int main(){
    int n;
    long long output=0;

    cin >> n;

    output = factorial(n);
    cout << output << endl;
    
    return 0;
}

long long factorial(int n){
    if(n == 0) return 1;

    return n * factorial(n-1);
}