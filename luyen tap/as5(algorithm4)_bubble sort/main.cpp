#include <iostream>
#include<vector>

using namespace std;
vector<int>vector1;
void bubble_sort(vector<int>&vector1){
    for(int i = 0;i < vector1.size()-2;i++){
        for(int j =0;j<vector1.size()-2;j++){
            if(vector1[j]>vector1[j+1])
                swap(vector1[j],vector1[j+1]);
        }
    }
}

int main()
{
    int n,x,y;
    do{
        cout<<"Nhap so luong ban muon nhap: ";
        cin>>n;
        if(n==0 || n <=2){
            cout<<"It's not funny bro, try again!!! -_-"<<endl;
        }
    }while(n==0 || n <=2 );
    for(int i = 0; i < n;i++){
        cin >> x;
        vector1.push_back(x);
    }
    bubble_sort(vector1);
    for(int i = 0;i<vector1.size();i++){
        cout<<vector1[i]<<" ";
    }
}
