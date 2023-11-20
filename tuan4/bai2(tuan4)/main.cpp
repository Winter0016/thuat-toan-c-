#include <iostream>
#include <vector>
using namespace std;
class POINT {
private:
    int x;
    int y;
public:
    void input(){
        cin>>x>>y;
    }
    int distance(const POINT & other){
        int newx= x - other.x;
        int newy= y - other.y;
        return newx*newx + newy*newy;
    }
    friend class RECTANGLE;
};
class RECTANGLE{
private:
    int largest_x;
    int smallest_x;
    int smallest_Y;
    int largest_y;
public:
    RECTANGLE( const POINT A, const POINT B){
        if(A.x>B.x){
            largest_x=A.x;
            smallest_x=B.x;
        }
        else{
            largest_x=B.x;
            smallest_x=A.x;
        }
        if(A.y>B.y){
            largest_y=A.y;
            smallest_Y=B.y;
        }
        else{
            largest_y=B.y;
            smallest_Y=A.y;
        }
    }
    int area(){
        return abs((largest_x-smallest_x)*(largest_y-smallest_Y));
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
    cout << rect.area();
}
