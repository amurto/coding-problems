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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        deque<int> q;
        int height = 0, cur = 1;
        q.push_back(arr[0]);
        while (cur < n && !q.empty())
        {
            deque<int> level;
            int par = q.size();
            while (par-- > 0)
            {
                while (cur < n && (level.empty() || level.back() < arr[cur]))
                    level.push_back(arr[cur++]);
                q.pop_front();
                while (!level.empty())
                {   
                    q.push_back(level.front());
                    level.pop_front();
                }
            }
            height++;
        }
        cout << height << "\n";
    }
    return 0;
}