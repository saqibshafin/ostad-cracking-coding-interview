#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int height=0;

    for(int minutes=0; minutes<N; minutes++){
        if(minutes%2 == 1){
            height+=3;
        }else{
            height-=1;
        }
    }
    cout << height;
    return 0;
}