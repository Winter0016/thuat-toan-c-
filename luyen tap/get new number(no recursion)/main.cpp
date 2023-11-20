#include <iostream>
#include <vector>
#include<string>
using namespace std;
class number
{
private:
    vector<int>digits;
    int x;
public:
    number()
    {

    }
    void input(auto a){
        x = a - '0';
        digits.push_back(x);
    }
    void output(){
        for(int i = 0 ; i < digits.size();i++){
            cout<<digits[i];
        }
    }
    void function(){
        int maxnumber=0;
        for(int i = 0 ;i <digits.size();i++){
            int y = i+1;
            if(digits[i]>digits[y]){
                maxnumber=digits[i];
                /*cout<<"max: "<<maxnumber<<endl;*/
                break;
            }
        }
        if(maxnumber==0)
            function2();
        else
            function1(maxnumber);
    }
    void function2(){
        cout<<0;
    }
    void function1(int maxnumber){
        vector<int>kq;
        int check=0;
        for(int i = 0;i<digits.size();i++){
            if(digits.size()==1){
                cout<<0;
                break;
            }
            if(i==0&&digits[i]==0){
                while(digits[i]==0){
                    i++;
                }
            }
            if(digits[i]==maxnumber&&check==0){
                check=1;
            }
            else{
                kq.push_back(digits[i]);
            }
        }
        function4(kq);
    }
    void function4(vector<int>kq){
        vector<int>check;
        for(int i = 0;i<kq.size();i++){
            if(i==0&&kq[i]==0){
                while(kq[i]==0){
                    i++;
                }
            }
            check.push_back(kq[i]);
            cout<<kq[i];
        }
        if(check.size()==0)
            cout<<0;
    }
};


int main()

{
    string n;
    cin>>n;
    number p;
    for(int i = 0; i<n.length();i++){
        p.input((n[i]));
    }
    p.function();

}
