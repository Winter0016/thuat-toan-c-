#include <iostream>
#include <algorithm>

using namespace std;

class fract {
public:
    long long int a, b;

    void input() {
        cin >> a >> b;
        if (b != 0) {
            long long int gcd = __gcd(a, b);
            a = a / gcd;
            b = b / gcd;
        } else {
            throw exception();
        }
    }

    bool equal(fract check) {
        if (b != 0 && check.b != 0) {
            if (a == check.a && b == check.b)
                return true;
            else {
                return false;
            }
        } else {
            return false;
        }
    }
};

int main() {
    int n;
    cin >> n;

    fract* arr = new fract[n];

    int index = 0;
    for (int i = 0; i < n; i++) {
        try {
            arr[index++].input();
        } catch (const std::exception& e) {
            index--;
        }
    }

    n = index;

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].equal(arr[j])) c++;
        }
    }

    cout << c;
    return 0;
}
