#include <iostream>
#include<vector>

using namespace std;
void insertion_sort(vector<int>&vector1,int n){
    for(int j = 2;j <=n ;j++){
        int i = 1;
        while (vector1[j]>vector1[i]){
            i = i + 1;
        }
        int m = vector1[j];
        for(int k = 0; k <= j - i - 1;k++){
            vector1[j-k] = vector1[j-k-1];
        }
        vector1[i]=m;
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
    vector<int>vector1(n+1);
    for(int i = 1; i <= n;i++){
        cin>>vector1[i];
    }
    insertion_sort(vector1,n);
    for(int i = 1;i< vector1.size();i++){
        cout<<vector1[i]<<" ";
    }
}
