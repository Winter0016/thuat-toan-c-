#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,x, z;

    do {
        cout << "Nhap so luong ban muon nhap: ";
        cin >> n;
        if (n == 0) {
            cout << "It's not funny bro, try again!!! -_-"<< endl;
        }
    } while (n == 0);

    vector<int> vector1(n);
    cin >> vector1[0];

    int i = 1;
    do {
        cin >> z;
        if (z >= vector1[i - 1]) {
            vector1[i] = z;
            i++;
        } else {
            cout << "Ban phai nhap so it nhat bang hoac lon hon so phia truoc!" << endl;
        }
    } while (i < n);
    cout<<"NHAP SO BAN MUON ADD: ";
    cin>>x;
    for(int i = 0 ; i < n ; i ++){
        if(x < vector1[i]){
            vector1.insert(vector1.begin()+i,x);
            break;
        }
        else if(x> vector1[vector1.size()-1]){
            vector1.insert(vector1.begin()+vector1.size(),x);
            break;
        }
    }
    for(int i = 0 ; i < vector1.size() ; i ++){
        cout<<vector1[i]<<" ";
    }

    return 0;
}
