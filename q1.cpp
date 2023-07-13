#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n,k;
string s;
int sum=0;
int z=1e9+7;
int dp[27][100001][27];
vector<int>frequency; //hashmap

int helper(int i,int val,int count)
{
    if(i==26)
    {
        if(count==k && sum==val)
        return 1;
        return 0;
    }

    if(dp[i][val][count]!=-1)
    return dp[i][val][count];

    int ans=0;
    if(frequency[i]==0)
    ans=(helper(i+1,val,count))%z;
    else
    ans=(((helper(i+1,val,count))%z)+(((frequency[i]%z)*helper(i+1,val+frequency[i],count+1)%z)%z))%z;
    ans%=z;
    return dp[i][val][count]=ans;
}

 
void solve(){

    cin>>n>>k;
    cin>>s;
    frequency.assign(26,0);
    for(int i=0;i<n;i++)
    frequency[s[i]-'a']++; //hashmap calculating
   
    sort(frequency.begin(),frequency.end());
    reverse(frequency.begin(),frequency.end()); //descending order
   
    if(k>26) // we have 26 alphabets only. cant make a string of len >26 with unique alphabets
    {
        cout<<0<<"\n";
        return;
    }

    if(frequency[k-1]==0) //where we have less than k unique characters. for ex: aabbaaab and k=5, 
      //here only frequency[0] and frequency[1] will be non zero numbers, thus frequency[k-1] will be 0
    {
        cout<<0<<"\n";
        return;
    }
    
    sum=0; //global variable
    for(int i=0;i<k;i++)sum+=frequency[i]; 
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
    int ans=helper(0,0,0);
    cout<<ans<<"\n";
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    solve();
}
