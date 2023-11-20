#include <iostream>
#include <vector>
using namespace std;
class function1
{
private:
    int a;
    vector<int>checking;
public:
    function1(auto x){
        a=x;
    }
    int give(){
        return a;
    }
    void output(auto i,auto maxnumber,auto & skip,auto maxnumberaddress,auto &check){
        if(i==0&&a==0){
            skip = 1;
        }
        if(maxnumberaddress==0&&i==0){
            skip = 1;
            check = 1;
        }
        else if(skip==1){
            if(a==0){

            }
            else{
                if(a==maxnumber&&check==0){
                    check = 1;
                }
                else{
                    cout<<a;
                    skip = 0;
                }
            }
        }
        else if(skip==0){
            if(a==maxnumber&&check==0){
                check=1;
            }
            else{
                cout<<a;
                checking.push_back(a);
            }
        }
        if(checking.size()<0&&skip==0){
            cout<<"0";
        }
    }
};
int main()
{
    string n;
    cin >> n;
    int Count = n.size();
    vector<function1>numbers;
    for (int i = 0; i < Count; i++) {
        int x = n[i] - '0';
        function1 f(x);
        numbers.push_back(f);
    }
    int maxnumber=0;
    int maxnumberaddress=0;
    int i =0;
    int check = 0;
    while(i<Count){
        int a = numbers[i].give();
        int b = numbers[i+1].give();
        if(a>b){
            maxnumber=a;
            maxnumberaddress=i;
            break;
        }
        i++;
    }
    if(maxnumber==0){
        cout<<"0";
    }
    else{
        int skip = 0;
        for(int i = 0;i<Count;i++){
            numbers[i].output(i,maxnumber,skip,maxnumberaddress,check);
        }
    }
}
