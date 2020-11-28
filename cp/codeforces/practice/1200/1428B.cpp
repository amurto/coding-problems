// https://codeforces.com/problemset/problem/1428/B
// Belted Rooms

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
        int n;
        cin >> n;
        string str;
        cin >> str;
        int ac = 0, c = 0, bi = 0;
        for (int i = 0; i < n; i++)
            if (str[i] == '<')
                ac++;
            else if (str[i] == '>')
                c++;

        int start = 0, end = n - 1;
        while (str[start] == '-')
            start++;
        while (str[end] == '-')
            end--;
        if (start == end)
            bi = n;
        else if (start > 0 && end < n - 1)
            bi += start + n - end;
        else if (start > 0)
            bi += start + 1;
        else if (end < n - 1)
            bi += n - end;
        while (start < end)
        {
            int temp = start;
            while (start < end && str[start] == '-')
                start++;
            if (start > temp)
                bi += start - temp + 1;
            start++;
        }
        if (ac > 0 && c > 0)
            cout << bi << "\n";
        else
            cout << n << "\n";
    }
    return 0;
}