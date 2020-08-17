// https://practice.geeksforgeeks.org/problems/amount-of-water/0
// Amount of Water

import java.util.*;
import java.io.*;

public class p16 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a =new int[n];
            int[] left =new int[n];
            int[] right =new int[n];
            for (int i=0; i<n; i++) 
                a[i] =Integer.parseInt(line[i]);
            if (n<=2) 
                System.out.println(0);
            else {
                left[0]=0;
                right[n-1]=0;
                for (int i=1;i<n-1;i++) {
                    left[i] = Math.max(left[i-1], a[i-1]);
                    right[n-i-1] = Math.max(right[n-i], a[n-i]);
                }   
                int need = 0;
                for (int i=1;i<n-1;i++) {
                    if (a[i]< Math.min(left[i], right[i]))
                        need=need+Math.min(left[i], right[i])-a[i];
                }
                System.out.println(need);
            }
        }
    }
}