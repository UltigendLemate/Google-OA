#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n,k;
string s;
int sum=0;
int z=1e9+7;
int dp[27][100001][27];
vector<int>freq; //hashmap

int rec(int level,int val,int cnt)
{
    if(level==26)
    {
        if(cnt==k && sum==val)
        return 1;
        return 0;
    }

    if(dp[level][val][cnt]!=-1)
    return dp[level][val][cnt];

    int ans=0;
    if(freq[level]==0)
    ans=(rec(level+1,val,cnt))%z;
    else
    ans=(((rec(level+1,val,cnt))%z)+(((freq[level]%z)*rec(level+1,val+freq[level],cnt+1)%z)%z))%z;
    ans%=z;
    return dp[level][val][cnt]=ans;
}

 
void solve(){

    cin>>n>>k;
    cin>>s;
    freq.assign(26,0);
    for(int i=0;i<n;i++)
    freq[s[i]-'a']++; //hashmap calculating
   
    sort(freq.begin(),freq.end());
    reverse(freq.begin(),freq.end()); //descending order
   
    if(k>26) // we have 26 alphabets only. cant make a string of len >26 with unique alphabets
    {
        cout<<0<<"\n";
        return;
    }

    if(freq[k-1]==0) //where we have less than k unique characters. for ex: aabbaaab and k=5, 
      //here only freq[0] and freq[1] will be non zero numbers, thus freq[k-1] will be 0
    {
        cout<<0<<"\n";
        return;
    }
    
    sum=0; //global variable
    for(int i=0;i<k;i++)sum+=freq[i]; 
    for(int i=0;i<=26;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int x=0;x<=26;x++)
            {
                dp[i][j][x]=-1;
            }
        }
    }
    int ans=rec(0,0,0);
    cout<<ans<<"\n";
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    solve();
}
