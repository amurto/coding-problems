#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5005;
bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), barr(n + 1), cntA(N), cntB(N);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cntA[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> barr[i];
        cntB[barr[i]]++;
    }
    for (int i = 1; i < N; i++)
        if (cntA[i] != cntB[i])
            return false;
    for (int i = 1; i < N; i++)
        if (cntA[i] > 1)
            return true;
    for (int i = 1; i <= n - 2; i++)
    {
        int pos = -1;
        for (int j = i; pos == -1 && j <= n; j++)
            if (barr[i] == arr[j])
                pos = j;
        if (pos == -1)
            return false;
        while (pos > i)
        {
            if (pos - i >= 2)
            {
                swap(arr[pos - 1], arr[pos]);
                swap(arr[pos - 2], arr[pos - 1]);
                pos -= 2;
            }
            else
            {
                swap(arr[pos - 1], arr[pos]);
                swap(arr[pos], arr[pos + 1]);
                pos--;
            }
        }
    }
    return arr == barr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}