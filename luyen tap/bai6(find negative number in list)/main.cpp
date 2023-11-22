#include <iostream>
#include <vector>
#include <algorithm>

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
    for (int i = 0; i < n; i++) {
        cin >> vector1[i];
    }

    // Sort the vector to bring duplicates together
    sort(vector1.begin(), vector1.end());

    // Remove duplicates from vector1
    auto newEnd = unique(vector1.begin(), vector1.end());
    vector1.erase(newEnd, vector1.end());

    vector<int> vector2;
    for(int i = 0; i < n; i++) {
        if (vector1[i] < 0) {
            vector2.push_back(vector1[i]);
        }
    }

    cout << "List of negative numbers from list 1: " << endl;
    for(int i = 0; i < vector2.size(); i++) {
        cout << vector2[i] << " ";
    }

    return 0;
}
