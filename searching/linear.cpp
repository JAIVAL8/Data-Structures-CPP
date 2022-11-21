#include <bits/stdc++.h>

using namespace std;
//does not requires sorting but takes n time to find by using divide each by half to find val.
int main(){
    int n,v;
    vector<int> vp;
    cout<<"Enter total count : "<<endl;
    cin>>n;
    cout<<"Enter values : "<<endl;

    for(int i=0;i<n;i++){
        cin>>v;
        vp.push_back(v);
    }
    cout<<"Enter the value to be found : "<<endl;
    cin>>v;
    for(int i =0 ;i<n;i++){
        if(vp[i]==v) {
            cout<<"value Found!";
            return 0;
            //break;
            
        }
    }
    cout<<"Not found!";
    
}