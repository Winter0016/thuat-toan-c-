#include <bits/stdc++.h>
#include <vector>
using namespace std;
class big_integer
{
private:
    int base = 10;
    int num_of_digits=log10(base);
    vector<int>digits;
public:
    big_integer(){

    }
    big_integer(int x){
        digits.push_back(x);
    }
    void output(){
        cout<<digits[digits.size()-1];
        for(int i = digits.size()-2;i>=0;i--){
            int length_of_digits = 1;
            if(digits[i]>0){
                length_of_digits = log10(digits[i])+1;
            }
            cout<<string(num_of_digits - length_of_digits,'0');
            cout<<digits[i];
        }
    }
    big_integer operator+(const big_integer&lhs){
        big_integer kq;
        int i = 0;
        kq.digits.resize(max(digits.size(),lhs.digits.size()));
        int remember = 0;
        while(1){
            if(i==digits.size())
                break;
            if(i==lhs.digits.size())
                break;
            auto temp = digits[i]+lhs.digits[i] + remember;
            kq.digits[i] = temp % base;
            remember = temp / base;
            i++;
        }
        if(i<digits.size()){
            for(;i<digits.size();i++){
                auto temp = digits[i] + remember;
                kq.digits[i] = temp % base ;
                remember = temp / base;
            }
        }
        if(i<lhs.digits.size()){
            for(;i<digits.size();i++){
                auto temp = digits[i] + remember;
                kq.digits[i] = temp % base ;
                remember = temp / base;
            }
        }
        if(remember==1) kq.digits.push_back(1);
        return kq;
    }
};


int main()
{
	big_integer f1 = 1, f2 = 1;
	int n;
	cin >> n;
	while(n >= 3){
		n--;
		auto temp = f2;
		f2 = f2+f1;
		f1 = temp;
	}
	f2.output();
    return 0;
}
