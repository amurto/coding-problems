// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0
// Zero Sum Subarrays

import java.util.*;
import java.io.*;

public class p15 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n= Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
            HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();
            h.put(0, 1);
            int sum=0, c=0;
            for (int i=0; i<n; i++) {
                sum+=a[i];
                if (h.get(sum) == null)
                    h.put(sum,1);
                else {
                    int v=h.get(sum);
                    c=c+v;
                    h.put(sum, v+1);
                }
            }
            System.out.println(c);
        }
    }
}