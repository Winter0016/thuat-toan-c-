#include <iostream>
#include <vector>
using namespace std;

class POINT
{
private:
    int x;
    int y;
public:
    POINT(auto c,auto b){
        x=c;
        y=b;
    }
    bool caculate(POINT & B, POINT & C){
        int xAB = B.x-x;
        int yAB = B.y - y;
        int xBC = C.x - B.x;
        int yBC = C.y - B.y;
        int crossover = (xAB * yBC) - (yAB * xBC);
        if(crossover < 0)
            return true;
        else
            return false;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<POINT>a;
    int c;
    int b;
    for(int i = 0 ; i<n;i++){
        cin>>c>>b;
        POINT p(c,b);
        a.push_back(p);
    }
    int Count=0;
    for(int i = 0; i<n-2; i++){
        if(a[i].caculate(a[i+1],a[i+2]))
            Count++;
    }
    cout << "Count: " << Count << endl;
    return 0;

}
