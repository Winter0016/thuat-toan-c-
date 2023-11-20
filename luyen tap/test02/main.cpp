#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
class big_integer
{
private:
    vector<string>digits;
    int base = 1000000000;
    int num_of_digits=log10(base);
public:
    big_integer(){

    }
    big_integer(string x){
        digits.push_back(x);
    }
    int get_length(string& a){
        return a.size();
    }
    vector<string> get_reverse() {
        vector<string> reversedDigits;

        for (int i = digits.size() - 1; i >= 0; i--) {
            string reversed;
            string temp = digits[i];

            for (int j = get_length(temp) - 1; j >= 0; j--) {
                reversed += temp[j];
            }
            reversedDigits.push_back(reversed);
        }
        return reversedDigits;
    }
    void output1( vector<string>& vec) {
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i];
        }
        cout << endl;
    }
    void output2(){
        for(int i = digits.size() - 1;i>=0;i--){
            cout<<digits[i];
        }
        cout<<endl;
    }
    big_integer operator+(vector<string> & vec){
        big_integer kq;
        kq.digits.resize(max(digits.size(),vec.size()));
        int i = 0;
        int remember = 0;
        long long a;
        long long b;
        while(1){
            if(i==digits.size())
                break;
            if(i==vec.size())
                break;
            a = stoi(digits[i]);
            b = stoi(vec[i]);
            auto temp = a + b + remember;
            kq.digits[i] = to_string(temp % base);
            remember = temp / base;
            i++;
        }
        if(i<digits.size()){
            long long a;
            for(;i<digits.size();i++){
                a = stoi(digits[i]);
                auto temp = a + remember;
                kq.digits[i]= to_string(temp%base);
                remember = temp/base;
            }
        }
        if (i < vec.size()){
            long long a;
            for(;i<digits.size();i++){
                a = stoi(digits[i]);
                auto temp = a + remember;
                kq.digits[i]= to_string(temp%base);
                remember = temp / base;
            }
        }
        if(remember != 0){
            kq.digits.push_back(to_string(remember));
        }
        return kq;
    }
    bool operator == ( vector<string> &vec){
        return digits==vec;
    }
    int length(){
        return digits.size();
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

    vector<big_integer> results;
    while(i <= limit_rep and s.length() <= limit_len){
        s = s + rs;
        /*cout<<"s new: ";
        s.output2();*/
        rs = s.get_reverse();
        /*cout<<"rs new: ";
        s.output1(rs);*/
        results.push_back(s);
        if (s == rs){
            cout << "NO" << endl;
            for(auto i : results){
                i.output2();
                cout << endl;
            }
            return 0;
        }
        i = i + 1;
    }
    cout << "YES" << endl;

    cout << i << " "; s.output2();
    return 0;
}
