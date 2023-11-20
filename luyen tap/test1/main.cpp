#include <iostream>
#include <string>
using namespace std;

long long customStollPositive(const string& str) {
    long long result = 0;

    for (int i = 0; i < str.size(); i++) {
        result = result * 10 + (str[i] - '0');
    }

    return result;
}

int main() {
    string numStr;
    cin >> numStr;

    long long num = customStollPositive(numStr);

    cout << "Converted Number: " << num << endl;

    return 0;
}
