#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
vector<int>s;
vector<vector<int>>rg(31);
int dp[102][1001];
int z=1e9+7;

//okay so rg is a 2d vector whose i th row indicates all numbers (from 1 to 1000 because of constraints) jinka sum of digits is i

int f(int i,int last)
{
    if(i==n)
    {
        return 1; //agar end tak agye ho toh 1 lejao
    }

    if(dp[i][last]!=-1)
    return dp[i][last]; //standard memoization

    int ans=0;

    for(auto it:rg[s[i]])
    {
        if(it>last) //agar pichle vale se bada hai toh ye uthalo aur aage lejao i aur agla element dhundo
        {
            ans+=f(i+1,it);
            ans%=z; // remainder by mod, standard
        }
    }
    ans%=z; // standard mod remainder
    return dp[i][last]=ans;
}
 
void solve(){

    cin>>n;

    s.assign(n+1,0);
    for(int i=0;i<n;i++)
    cin>>s[i];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            dp[i][j]=-1; // jo elements use hoge hamare ques me unhe -1 bana do, 
          //instead of this you can also just declare a dp vector of n x 1001 here
        }
    }

    int ans=f(0,0); //dp lagake ans leke ao
    cout<<ans<<"\n";
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=1000;i++) //1 se 1000 tak iterate karo
    {
        int sum=0;
        int temp=i;
        while(temp) //sum of digit nikalo
        {
            sum+=(temp%10);
            temp/=10;
        }
        if(sum>=1 && sum<=30)
        rg[sum].push_back(i); //line 10 padhlo
    }

    int t;cin>>t;while(t--)
    solve();
}
