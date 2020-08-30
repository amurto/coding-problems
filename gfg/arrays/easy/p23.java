// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
// Subarray with given sum

import java.util.*;
import java.io.*;

public class p23 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            int s = Integer.parseInt(params[1]);
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
            int sum=0;
            HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();
            h.put(0, -1);
            Boolean ans=false;
            for (int i=0; i<n; i++) {
                sum+=a[i];
                if (h.containsKey(sum-s)) {
                    System.out.println((h.get(sum-s)+2) + " " + (i+1));
                    ans=true;
                    break;
                }
                h.put(sum, i);
            }
            if (!ans)
                System.out.println(-1);
        }
    }
}