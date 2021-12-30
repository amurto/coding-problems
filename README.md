## Coding Problems

```java
import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
        }
    }
}
```

```c++
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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    d(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
```

```cpp
g++ test.cpp -std=c++17 -Duse_debug -DDEBUG
g++ test.cpp -std=c++17 -Duse_debug -DDEBUG -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG -ggdb3 -fsanitize=address -fsanitize=undefined
g++ test.cpp -std=c++17 -Duse_debug -DDEBUG -Wall -Wextra -Wshadow
```

"": {
  "prefix": "",
  "body": [
    "#ifdef use_debug",
    "#define TERMINAL",
    "#include \"headers/debug.cpp\"",
    "#else",
    "#define d(...) 0",
    "#endif",
    "#include <bits/stdc++.h>",
    "using namespace std;",
    ""
  ],
  "description": ""
}