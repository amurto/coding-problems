#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

class grid
{
public:
    int n;
    vector<string> mat;
    grid() {}
    grid(int n) : n(n)
    {
        mat.resize(n);
        for (int i = 0; i < n; i++)
        {
            string tmp = "";
            for (int j = 0; j < n; j++)
                tmp.pb('0');
            mat[i] = tmp;
        }
    }

    void clear()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = '0';
    }

    void display()
    {
        cout << "?" << endl;
        for (string s : mat)
            cout << s << endl;
    }

    void colorRow(int l, int r, char ch)
    {
        for (int i = l; i <= r; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = ch;
    }

    void colorCol(int l, int r, char ch)
    {
        for (int i = 0; i < n; i++)
            for (int j = l; j <= r; j++)
                mat[i][j] = ch;
    }

    int hasPath(pii src, pii des)
    {
        int di[2] = {0, 1}, dj[2] = {1, 0};
        vector<vector<bool>> vis(n, vector<bool>(n));
        queue<pii> q;
        if (mat[src.first][src.second] == '0')
            return false;
        vis[src.first][src.second] = true;
        q.push({src.first, src.second});
        while (!q.empty())
        {
            pii cur = q.front();
            q.pop();
            for (int dir = 0; dir < 2; dir++)
            {
                int i = cur.first + di[dir], j = cur.second + dj[dir];
                if (i < n && j < n && !vis[i][j] && mat[i][j] == '1')
                {
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        return vis[des.first][des.second];
    }

    int query()
    {
        int ans;
        display();
        cin >> ans;
        if (ans == -1)
            exit(0);
        return ans;
    }

    bool checkRow(int row)
    {
        clear();
        colorRow(0, row - 1, '1');
        colorRow(row + 1, n - 1, '1');
        return query();
    }

    bool checkCols(vector<int> cols)
    {
        clear();
        colorRow(0, 0, '1');
        colorRow(n - 1, n - 1, '1');
        for (int col : cols)
        {
            if (col - 1 >= 0)
            {
                for (int i = 1; i < n - 2; i++)
                    mat[i][col - 1] = '1';
            }
            if (col + 1 < n)
            {
                for (int i = 2; i < n - 1; i++)
                    mat[i][col + 1] = '1';
            }
        }
        return query();
    }

    int colBS(int r)
    {
        int low = 1, high = n - 2;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            clear();
            colorRow(n - 1, n - 1, '1');
            colorCol(0, mid, '1');
            colorRow(r, r, '0');
            if (query())
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    int rowBS(int c)
    {
        int low = 1, high = n - 2;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            clear();
            colorRow(0, mid, '1');
            colorCol(c, c, '0');
            colorCol(c + 1, n - 1, '1');
            if (query())
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

pii solve(int n)
{
    grid g = grid(n);
    int r = 0, c = 0;
    if (g.checkRow(1))
    {
        r = 1;
        c = g.colBS(r);
    }
    else if (g.checkRow(n - 2))
    {
        r = n - 2;
        c = g.colBS(r);
    }
    else
    {
        int s = 2;
        for (int i = 0; s == 2 && i < 2; i++)
        {
            vector<int> cols;
            for (int j = 0; j < n; j++)
                if (j % 3 == i)
                    cols.pb(j);
            if (g.checkCols(cols))
                s = i;
        }
        vector<int> cols;
        for (int j = 0; j < n; j++)
            if (j > 0 && j < n - 1 && j % 3 == s)
                cols.pb(j);
        int low = 0, high = cols.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            g.clear();
            g.colorRow(n - 1, n - 1, '1');
            g.colorCol(0, cols[mid], '1');
            vector<int> tmp(cols.begin(), cols.begin() + mid + 1);
            if (g.checkCols(tmp))
                high = mid;
            else
                low = mid + 1;
        }
        c = cols[low];
        r = g.rowBS(c);
    }
    return {r, c};
}

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
        pii res = solve(n);
        cout << "!" << endl;
        cout << res.first << " " << res.second << endl;
        int ans;
        cin >> ans;
    }
    return 0;
}