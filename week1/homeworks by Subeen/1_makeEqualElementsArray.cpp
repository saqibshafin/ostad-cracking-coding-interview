#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &A, int B);

int main(){
    int n, input, X;
    vector<int> A;

    cin >> n;

    while(n > 0){
        n--;
        cin >> input;
        A.push_back(input);
    }

    for (int i: A){
        cout << i << " ";
    }
    /*
        In this case, "int i: A" means that for each element of the vector A, which is of type int, 
        assign it to the variable i and execute the statement that follows, which is cout << i << " "; 
        This will print each element of the vector separated by a space.
    */    
    
    // for(int i = 0; i < A.size(); i++){
    //     cout << A[i] << " ";
    // }

    int x = solve(A, 2);

    cout << x << '\n';
}

int solve(vector<int> &A, int B){
    
    
    return 0;
}