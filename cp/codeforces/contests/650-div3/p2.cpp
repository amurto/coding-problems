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
        int n, evn, evnc = 0, oddc = 0, problem = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (n % 2 > 0)
            evn = n / 2 + 1;
        else
            evn = n / 2;
        int odd = n / 2;
        for (int i = 0; i < n; i++)
        {
            int temp = arr[i];
            if (temp % 2 == 0)
                evnc++;
            else
                oddc++;
            if (i % 2 != temp % 2)
                problem++;
        }

        if (evn != evnc || odd != oddc)
            cout << "-1\n";
        else
        {
            if (problem % 2 > 0)
                cout << "-1\n";
            else
                cout << problem / 2 << "\n";
        }
    }
    return 0;
}