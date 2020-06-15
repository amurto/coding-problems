import java.util.*;
import java.io.*;
import java.math.*;

public class evenm {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            int n = Integer.parseInt(br.readLine());
            int[][] m = new int[n][n];
            int k= 1;
            for (int i=0; i<n; i++) {
                for (int j=0;j<n;j++) {
                    int ans = i%2 == 0 ? j+1 : n-j;
                    ans+=i*n;
                    System.out.print(ans  + " ");
                    m[i][j] = k;
                    k++;
                }
                System.out.print("\n");
            }
            t--;
        }
    }
}
