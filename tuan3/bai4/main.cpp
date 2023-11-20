
#include <iostream>
#include <map>
using namespace std;

map<int*, int> BOOK;

void cap_phat(int *&a, int size){
    int *x = new int[size];
    BOOK[x] = size;
    a = x;
}

void giai_phong(int *a){
    delete a;
    BOOK.erase(a);
}




void check(Array A, int n, int l, int r){
    if (BOOK.size() > 1) cout << "WRONG";
    if (BOOK.begin()->second > 2*n) cout << "WRONG";

    for(int i = l ; i <= r; i++){
        cout << A.A[i] << " ";
    }
    cout << endl;
}


int main(){
    Array A;

    int x;
    A.na = 0;
    while(cin >> x){
        A.array_insert(x);

        int l, r; cin >> l >> r;
        check(A, A.na, l, r);
    }
}

