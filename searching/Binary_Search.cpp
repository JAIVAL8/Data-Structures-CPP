#include <bits/stdc++.h>

using namespace std;
//requires sorting but only takes logn time to find by using divide each by half to find val. 
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
    sort(vp.begin(),vp.end());
    
    int i=0,mid;
    while(i<=n){
        mid=(i+n)/2;
        if(vp[mid]>v){
            n=mid-1;
        }
        else if(vp[mid]<v){
            i=mid+1;
        }
        else if(vp[mid]==v){
            cout<<"value Found!";
            return 0;
        }

    };

    
    cout<<"Not found!";
    
}