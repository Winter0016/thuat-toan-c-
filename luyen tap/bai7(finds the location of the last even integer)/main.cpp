#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    do {
        cout << "Nhap so luong ban muon nhap: ";
        cin >> n;
        if (n == 0) {
            cout << "It's not funny bro, try again!!! -_-"<< endl;
        }
    } while (n == 0);
    vector<int> vector1(n);
    for (int i = 0; i < n; i++){
        cin >> vector1[i];
    }
    int last_even;
    bool found = false;
    for(int i = 0; i < n ; i ++){
        if(vector1[i]==0 || vector1[i] % 2 ==0){
            last_even=i;
            found = true;
        }
    }
    if(found){
        cout<<"the location of the last even integer is "<<last_even+1<<" whose value is: "<<vector1[last_even];
    }
    else
        cout<<"location = 0";
    return 0;
}
