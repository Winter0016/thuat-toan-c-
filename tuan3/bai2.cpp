#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class POINT {
public:
    int x;
    int y;

    void input() {
        cin >> x >> y;
    }

    double square_distance(const POINT& other) {
        int dx = x - other.x;
        int dy = y - other.y;
        return dx * dx + dy * dy;
    }
};

class CIRCLE {
private:
    POINT center;
    int radius;

public:
    void input() {
        center.input();
        cin >> radius;
    }

    bool contain(const POINT& temp) {
        double distance = center.square_distance(temp);
        return distance < radius * radius;
    }
};

int main() {
    int n;
    cin >> n;

    vector<POINT> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].input();
    }

    CIRCLE C;
    C.input();

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (C.contain(arr[i])) {
            count += 1;
        }
    }

    cout << count;

    return 0;
}
