#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define ALL(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOD(i,a,b) for(int i=a;i>=b;i--)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);
ll gcd(ll a, ll b){if(b==0) return a;return gcd(b,a%b);}

const int N = 1e6;



int dp[1003][1003]; //C(n,k)

void tohop()
{
    dp[1][0] = dp[1][1] = 1;
    FOR(i,2,40)
    FOR(j,1,40)
    {
        if (j == 1) dp[i][j] = i;
        else 
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
    }
}


void testcase()
{
    int n, m, k;
    cin >> n >> m >> k;
    while(n != 0 || m != 0)
    {
        // cout << n << " " << m << " " << k << "\n";
        // cout << dp[m + n - 1][m] << " ";
        if (k <= dp[m + n - 1][m]) 
        {
            n--;
            cout << "a";
        }
        else 
        {
            k -= dp[m + n - 1][m];
            m--;
            cout << "b";
        }
    }

    while(n > 0)
    {
        cout << 'a'; n--;
    }

    while(m > 0)
    {    
        cout << 'b'; m--;
    }
}

signed main()
{
    IOS;
    int tc = 1;
    tohop();
    // cin >> tc;
    while(tc--) testcase();
    return 0;
}