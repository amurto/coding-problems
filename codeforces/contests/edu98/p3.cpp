#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string str;
        cin >> str;
        int st1 = 0, st2 = 0, res = 0;
        for (char ch : str)
        {
            if (ch == '(')
                st1++;
            if (ch == ')' && st1 > 0)
            {
                st1--;
                res++;
            }
            if (ch == '[')
                st2++;
            if (ch == ']' && st2 > 0)
            {
                st2--;
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}