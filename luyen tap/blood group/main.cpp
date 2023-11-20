#include <iostream>

using namespace std;

int main()
{
    string mom,father,child;
        cin>>mom>>father>>child;
        if(mom==father){
            if(father!="AB"||mom!="AB"){
                if(child=="O")
                    cout<<"YES";
                else if(father==child){
                    cout<<"YES";
                }
                else
                    cout<<"NO";
            }
            else{
                if(child=="O")
                    cout<<"NO";
                else
                    cout<<"YES";
            }
        }
        else{
            if((mom=="A"&&father=="B")||(mom=="B"&&father=="A"))
                cout<<"YES";
            else if(mom=="O"||father=="O"){
                if(father=="AB"||mom=="AB"){
                    if(child =="A"||child=="B")
                        cout<<"YES";
                    else
                        cout<<"NO";
                }
                else if(mom==child||father==child)
                    cout<<"YES";
                else
                    cout<<"NO";
            }
            else if(child=="A"||child=="B")
                cout<<"YES";
            else if(child=="AB")
                cout<<"YES";
            else
                cout<<"NO";
        }
}
