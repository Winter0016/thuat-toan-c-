#include <iostream>
#include<vector>

using namespace std;
vector<int>vector1;

void linear_search(vector<int>&vector1,int y){
    int i = 0;
    int location;
    while(i<vector1.size() && vector1[i]!=y){
        i++;
    }
    if(i<vector1.size()){
        location=i+1;
    }
    else
        location = 0;
    cout<<"LOCATION!!!: "<<location;

}
int main()
{
    int n,x,y;
    do{
        cout<<"Nhap so luong ban muon nhap: ";
        cin>>n;
        if(n==0){
            cout<<"It's not funny bro, try again!!! -_-"<<endl;

        }
    }while(n==0);
    for(int i = 0; i < n;i++){
        cin >> x;
        vector1.push_back(x);
    }
    cout<<"nhap so ban muon tim!!!!!: ";
    cin>>y;
    linear_search(vector1,y);
}
