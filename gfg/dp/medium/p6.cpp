// https://practice.geeksforgeeks.org/problems/word-break/0
// Word Break

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[1001];

int findSegment(vector<string> &arr, int s, string &str, int idx)
{
    if (idx >= str.length())
        return 1;
    if (DP[idx] < 0)
    {
        int ans = 0;
        for (int i = s; i < arr.size(); i++)
        {
            if (str.compare(idx, arr[i].length(), arr[i]) == 0)
                if (findSegment(arr, s, str, idx + arr[i].length()) == 1)
                {
                    DP[idx] = 1;
                    return DP[idx];
                }
        }
        DP[idx] = 0;
    }
    return DP[idx];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<string> arr;
        string input, str;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            arr.pb(input);
        }
        cin >> str;
        memset(DP, -1, sizeof(DP));
        cout << findSegment(arr, 0, str, 0) << endl;
    }
    return 0;
}