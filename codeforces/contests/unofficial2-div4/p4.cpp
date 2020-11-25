#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t-- > 0)
    {
        ll a, s;
        cin >> a >> s;
        ll b = s - a;
        vector<int> A, B;
        ll temp = a;
        while (temp > 0)
        {
            A.pb(temp % 10);
            temp /= 10;
        }
        temp = b;
        while (temp > 0)
        {
            B.pb(temp % 10);
            temp /= 10;
        }
        bool p = true;
        if (A.size() != B.size())
            p = false;
        else
        {
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i] != B[i])
                {
                    p = false;
                    break;
                }
            }
        }
        p ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}