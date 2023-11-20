#include <bits/stdc++.h>
using namespace std;




int main () {
    int n;
    cin >> n;

    fract *arr = new fract[n];

    int index = 0;
    for(int i = 0; i < n; i++) {
        try{
            arr[index++].input();
        }
        catch(exception e){
            index--;
        }
    }

    n = index;

    int c = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++){
            if (arr[i].equal(arr[j]) )c++;
        }
    }

    cout << c;
}
