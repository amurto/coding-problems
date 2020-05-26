import java.util.*;
import java.io.*;

public class heating {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int n = in.nextInt();
        int c, sum, q, r, val;
        int ans[] = new int[n];
        for (int i = 0; i < n; i++) {
            c = in.nextInt();
            sum = in.nextInt();
            if (c > sum)
                ans[i] = sum;
            else {
                int cost = 0;
                q = sum / c;
                r = sum % c;
                for (int j = 0; j < c; j++) {
                    val = q + (r > 0 ? 1 : 0);
                    cost = cost + val * val;
                    r--;
                }
                ans[i] = cost;
            }
        }
        in.close();
        for (int a: ans) 
            System.out.println(a);
    }
}