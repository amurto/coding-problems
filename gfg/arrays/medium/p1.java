// https://www.geeksforgeeks.org/find-next-greater-number-set-digits/
// Asked in CarWale Technical Round
// Find next greater number with same set of digits

import java.util.*;
import java.io.*;

public class p1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line  = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++) 
                a[i] = Integer.parseInt(line[i]);
            int i = n-2;
            while (i >= 0 && a[i+1] <= a[i]) {
                i--;
            }
            if (i<0) 
                System.out.println("Not Possible");
            else {
                int j=n-1;
                while (j>i && a[j] < a[i])
                    j--;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                Arrays.sort(a, i+1, n);
                for (int v: a) 
                    System.out.print(v+" ");
                System.out.println();
            }
        }
    }
}