#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll                          long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll ,ll>>A(n);
        for(int i=0;i<n;i++){
            cin>>A[i].first;
            A[i].second = i;
        }
        sort(A.begin() , A.end());
        unordered_map<ll, ll>new_ind;
        for(int i=0;i<n;){
            ll j=i;
            while(j<n && A[j].first==A[i].first) j++;
            for(int k=i;k<j;k++){
                new_ind[A[k].second] = i;
            }
            i = j;
        }
        
        vector<ll>pref(n, 0);
        for(int i=0;i<n;i++){
            pref[i] = (i?pref[i-1]:0) + A[i].first;
        }
            
        ll q;
        cin>>q;
        while(q--){
            ll c, k;
            cin>>c>>k;
            vector<ll>temp(k);
            for(int i=0;i<k;i++){
                cin>>temp[i];
                temp[i]--;
                temp[i] = new_ind[temp[i]];
            }
            sort(temp.begin() , temp.end());

            ll l=0;
            ll r = lower_bound(pref.begin() , pref.end() , c+1) - pref.begin()-1;
            ll cnt =0;
            ll want = c;
            for(int i=0;i<k;i++){
                if(temp[i]<=r){
                    cnt++;
                    want += A[temp[i]].first;
                    r = lower_bound(pref.begin() , pref.end() , want+1) - pref.begin()-1;
                }
                else break;
            }
            cout<<(r+1)-cnt<<endl;
        }
    }
    return 0;
}