#include <iostream>
#include <vector>

using namespace std;

class POINT {
public:
    int x, y;

    void input() {
        cin >> x >> y;
    }

    double distance(const POINT& other) {
        int dx = x - other.x;
        int dy = y - other.y;
        return (dx * dx + dy * dy);
    }

    void output() {
        cout <<"("<<x<<","<<" "<<y<<")";
    }
};

class RECTANGLE {
public:
    int x1,x2,y1,y2;
    RECTANGLE(const POINT A, const POINT B){
        if(A.x>B.x){
            x2=A.x;
            x1=B.x;
        }
        else{
            x2=B.x;
            x1=A.x;
        }
        if(A.y>B.y){
            y2=A.y;
            y1=B.y;
        }
        else{
            y2=B.y;
            y1=A.y;
        }

    }

    bool contain(const POINT& point) {
        return point.x > x1  && point.x < x2 &&
               point.y > y1 && point.y < y2;
    }
};

int main(){
    int n;
    cin >> n;
    vector<POINT> arr(n);
    for (int i = 0; i < n; i++){
        arr[i].input();
    }
    int furthest = 0, furthest_i, furthest_j = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if (arr[i].distance(arr[j]) > furthest){
                furthest = arr[i].distance(arr[j]);
                furthest_i = i;
                furthest_j = j;
            }
        }
    }

    RECTANGLE rect(arr[furthest_i], arr[furthest_j]);
    for (int i = 0; i < n; i++){
        if (rect.contain(arr[i])){
            arr[i].output();
            cout << endl;
        }
    }
}
