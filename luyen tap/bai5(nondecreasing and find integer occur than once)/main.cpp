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
    cin>>vector1[0];
    for (int i = 1; i < n; i++){
        do{
            cin>>vector1[i];
            if(vector1[i]< vector1[i-1]){
                cout<<"try input a number which is atleast as large as the previous"<<endl;
            }
        }while( vector1[i]< vector1[i-1]);
    }
    /*for(int i = 0; i < n;i++){
        cout<<vector1[i]<<" ";
    }*/
    vector<int>vector2;
    int i = 0;

    while (i < vector1.size()) {
        int j = i + 1;
        bool foundDuplicate = false;

        while (j < vector1.size()) {
            if (vector1[j] == vector1[i]) {
                foundDuplicate = true;
                j++;
            }
            else{
                break;
            }
        }

        if (foundDuplicate) {
            vector2.push_back(vector1[i]);
            cout<<endl;
            cout << vector1[i] << " is a repeat" << endl;
        }

        if(foundDuplicate){
            i = j;
        }
        else{
            i++;
        }
    }
    cout<<"The list contains numbers which occur more than once: "<<endl;
    for(int i = 0; i < vector2.size();i++){
        cout<<vector2[i]<<" ";
    }
    return 0;
}
