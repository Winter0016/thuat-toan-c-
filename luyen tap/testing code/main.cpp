#include <bits/stdc++.h>
#include <vector>
using namespace std;
class big_integer
{
private:
    vector<string>digits;
    int base=10;
    int num_of_digits = log10(base);
public:
    big_integer(){}
    big_integer(string x){
        digits.push_back(x);
    }
    big_integer get_reverse(){
        for(int i =digits.size()-1;i>=0;i--){
            string temp = digits[i];
            return big_integer(temp);
        }
    }
    big_integer operator+(const big_integer & lhs){
        big_integer kq;
        kq.digits.resize(max(digits.size(),lhs.digits.size()));
        int i = 0;
        int remember = 0 ;
        while(1){
            if(i==digits.size())
                break;
            if(i==lhs.digits.size())
                break;
            auto temp = stoi(digits[i])+ stoi(lhs.digits[i]) + remember;
            /*cout<<"temp: "<<temp<<endl;*/
            kq.digits[i]=to_string(temp%base);
            /*cout<<"kq.digits[i]: "<<kq.digits[i]<<endl;*/
            remember = temp / base;
            i++;
        }
        if(i<digits.size()){
            for(;i<digits.size();i++){
                auto temp = stoi(digits[i]) + remember;
                /*cout<<"temp: "<<temp<<endl;*/
                kq.digits[i]= to_string(temp%base);
                /*cout<<"kq.digits[i]: "<<kq.digits[i]<<endl;*/
                remember = temp/base;
            }
        }
        if (i < lhs.digits.size()){
            for(;i<digits.size();i++){
                auto temp = stoi(digits[i])+remember;
                /*cout<<"temp: "<<temp<<endl; */
                kq.digits[i]= to_string(temp%base);
                /*cout<<"kq.digits[i]: "<<kq.digits[i]<<endl; */
                remember = temp / base;
            }
        }
        if(remember != 0){
            kq.digits.push_back(to_string(remember));
        }
        return kq;
    }
    int length(){
        return digits.size();
    }
    bool operator == ( big_integer & other){
        return digits==other.digits;
    }
    void output1(){
        for(int i = digits.size()-1;i>=0;i--){
            cout<<digits[i];
        }
    }
    void output2(){
        for(int i = 0; i <digits.size();i++){
            cout<<digits[i];
        }
    }
};


int main()
{
	int n;


    int i = 0;
    int limit_rep = 1e4, limit_len = 1.5e4;

    string input;
    cin >> input;


    auto s = big_integer(input);
    auto rs = s.get_reverse();
    /*cout<<"s :";
    s.output2();
    cout<<endl;
    cout<<"rs: ";
    rs.output2();
    cout<<endl;*/

    vector<big_integer> results;
    while(i <= 3 and s.length() <= limit_len){

        s = s + rs;
        cout<<"new s = ";
        s.output1();
        cout<<endl;
        rs = s.get_reverse();
        cout<<"new rs = ";
        rs.output1();
        cout<<endl;
        results.push_back(s);
        if (s == rs){
            cout << "NO" << endl;
            for(auto i : results){
                i.output1();
                cout << endl;
            }
            return 0;
        }
        i = i + 1;
    }
    cout << "YES" << endl;

    cout << i << " "; s.output1();
    return 0;
}

