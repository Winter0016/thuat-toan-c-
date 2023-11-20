#include <iostream>
#include <vector>
#include<string>
using namespace std;
struct number
{
private:
    vector<int>digits;
    int x;
public:
    number()
    {

    }
    void inputRecursively(const string& n, int index) {
        if (index < n.length()) {
            x = n[index] - '0';
            digits.push_back(x);
            inputRecursively(n, index + 1);
        }
    }
    void functionrecursive(int & maxnumber,int &i){
        int y = i +1;
        if(i<digits.size()){
            if(digits[i]>digits[y]){
                maxnumber=digits[i];
                i = digits.size();
            }
            i++;
            functionrecursive(maxnumber,i);
        }
    }
    void function(){
        int maxnumber=0;
        int i = 0;
        functionrecursive(maxnumber,i);
        if(maxnumber==0)
            function2();
        else
            function1(maxnumber);
    }
    void function2(){
        cout<<0;
    }
    void w1(int &i){
        if(digits[i]==0){
            i++;
            w1(i);
        }
    }
    void function1_recursive(int maxnumber,int &i,vector<int>&kq,int &check){
        if(i<digits.size()){
            if(digits.size()==1){
                cout<<0;
                i = digits.size();
            }
            if(i==0&&digits[i]==0){
                w1(i);
            }
            if(digits[i]==maxnumber&&check==0){
                check=1;
            }
            else{
                kq.push_back(digits[i]);
            }
            i++;
            function1_recursive(maxnumber,i,kq,check);
        }
    }
    void w2(int &i,vector<int>&kq){
        if(kq[i]==0){
            i++;
            w2(i,kq);
        }
    }
    void function1(int maxnumber){
        vector<int>kq;
        int check=0;
        int i = 0;
        function1_recursive(maxnumber,i,kq,check);
        function4(kq);
    }
    void function4_recursive(vector<int>&check,vector<int>&kq,int &i){
        if(i<kq.size()){
            if(i==0&&kq[i]==0){
               w2(i,kq);
            }
            check.push_back(kq[i]);
            cout<<kq[i];
            i++;
            function4_recursive(check,kq,i);
        }
    }
    void function4(vector<int>kq){
        vector<int>check;
        int i =0;
        function4_recursive(check,kq,i);
        if(check.size()==0)
            cout<<0;
    }
};


int main()

{
    string n;
    cin>>n;
    number p;
    p.inputRecursively(n, 0);
    p.function();

}
