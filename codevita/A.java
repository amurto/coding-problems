import java.util.*;
import java.io.*;

public class A {
    public static int max = -1;
    public static int[] Count(int val) {
        String res = Integer.toBinaryString(val);
        int zeros=0, ones=0;
        zeros = max-res.length();
        for (int i=0; i<res.length(); i++) {
            if (res.charAt(i) == '0')
                zeros++;
            else
                ones++;
        }
        int[] ans = {zeros, ones};
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");

        int[] a = new int[n];
        for (int i=0; i<n; i++) {
            a[i] = Integer.parseInt(line[i]);
            max = Math.max(max, a[i]);
        }
        max = Integer.toBinaryString(max).length();
        int[][] dp = new int[n][2];
        for (int i=0;i<n;i++) {
            int[] ans = Count(a[i]);
            dp[i][0] = ans[0];
            dp[i][1] = ans[1];
        }
        int out = 0;
        for (int i=0; i<n;i++) {
            int t0=0, t1 = 0;
            for (int j=i; j<n;j ++) {
                t0+=dp[j][0];
                t1+=dp[j][1];
                if (t0 == t1)
                    out++;
            }
        }
        String outp = Integer.toBinaryString(out);
        while (max-- > outp.length())
            System.out.print("0");
        System.out.print(outp);
        System.out.println();
    }
}