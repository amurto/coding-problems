// https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array/0
// Move all zeros to end of array
import java.util.*;
import java.io.*;

public class p13 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            int zero = -1, one = -1;
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(line[i]);
                if (a[i] == 0 && zero < 0)
                    zero = i;
                if (a[i] > 0 && one == -1 && zero >= 0)
                    one = i;
            }
            while (zero < one && one < n) {
                a[zero] = a[one];
                a[one] = 0;
                zero++;
                one++;
                while (one < n - 1 && a[one] == 0)
                    one++;
            }
            for (int v : a)
                System.out.print(v + " ");
            System.out.println();
        }
    }
}