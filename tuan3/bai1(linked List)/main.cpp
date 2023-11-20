#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
    Point* next;
};

int countRightTurns(Point* points) {
    int count = 0;

    Point* p1 = points;
    Point* p2 = p1->next;
    Point* p3 = p2->next;

    while (p3 != NULL) {
        int cross = (p2->x - p1->x) * (p3->y - p1->y) - (p2->y - p1->y) * (p3->x - p1->x);
        if (cross < 0) {
            count++;
        }

        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    Point* head = NULL;
    Point* prev = NULL;

    for (int i = 0; i < n; i++) {
        Point* newPoint = new Point;
        cin >> newPoint->x >> newPoint->y;
        newPoint->next = NULL;

        if (prev != NULL) {
            prev->next = newPoint;
        } else {
            head = newPoint;
        }

        prev = newPoint;
    }

    int rightTurns = countRightTurns(head);
    cout << rightTurns << endl;

    Point* current = head;
    while (current != NULL) {
        Point* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
