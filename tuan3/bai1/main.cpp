#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int crossProduct(const Point& p1, const Point& p2, const Point& p3) {
    int cross = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return cross;
}

int countRightTurns(const vector<Point>& points) {
    int count = 0;
    int size = points.size();

    for (int i = 0; i < size - 2; i++) {
        int cross = crossProduct(points[i], points[i + 1], points[i + 2]);
        if (cross < 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int rightTurns = countRightTurns(points);
    cout << rightTurns << endl;

    return 0;
}
