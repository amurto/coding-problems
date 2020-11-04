// DFS Approach O(n2)
import java.util.*;
import java.io.*;
 
public class ke {
    final static int N = 1010;
    final static int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
    final static int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
 
    public static int arr[][] = new int[N][N];
    public static int n;
 
    public static void dfs(int r, int c) {
        arr[r][c] = 2;
        for (int i = 0; i < 8; i++) {
            int x = dx[i] + r;
            int y = dy[i] + c;
 
            if (x > 0 && y > 0 && x <= n && y <= n && arr[x][y]< 1)
                dfs(x, y);
        }
    }
 
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        n = in.nextInt();
        int ax = in.nextInt();
        int ay = in.nextInt();
        int bx = in.nextInt();
        int by = in.nextInt();
        int cx = in.nextInt();
        int cy = in.nextInt();
        in.close();
        int i, j;
        for (i = 1; i <= n; i++) {
            arr[i][ay] = 1;
            arr[ax][i] = 1;
        }
        i = ax;
        j = ay;
        while (i < n && j < n) {
            arr[i][j] = 1;
            i++;
            j++;
        }
        i = ax;
        j = ay;
        while (i > 0 && j < n) {
            arr[i][j] = 1;
            i--;
            j++;
        }
        i = ax;
        j = ay;
        while (i < n && j > 0) {
            arr[i][j] = 1;
            i++;
            j--;
        }
 
        i = ax;
        j = ay;
        while (i > 0 && j > 0) {
            arr[i][j] = 1;
            i--;
            j--;
        }
        dfs(bx, by);
 
        if (arr[cx][cy] == 2)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}

public class ke2 {
    public static boolean in_middle(int L, int x, int R) {
        return ((L <= x && x <= R) || (R <= x && x <= L));
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int n = in.nextInt();
        int ax = in.nextInt();
        int ay = in.nextInt();
        int bx = in.nextInt();
        int by = in.nextInt();
        int cx = in.nextInt();
        int cy = in.nextInt();
        in.close();
        boolean qx = in_middle(bx, ax, cx);
        boolean qy = in_middle(by, ay, cy);
        if (qx || qy)
            System.out.println("NO");
        else
            System.out.println("YES");
    }
}