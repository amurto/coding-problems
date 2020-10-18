// https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k/0
// Longest subarray with sum divisible by K

import java.util.*;
import java.io.*;

public class p24 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            int k = Integer.parseInt(params[1]);
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            int sum=0, max = 0;
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
            
            int[] map = new int[k];
            Arrays.fill(map, -2);
            map[0]=-1;
            for (int i=0; i<n; i++) {
                sum=((sum+a[i])%k+k)%k;
                if (map[sum]==-2)
                    map[sum]=i;
                else 
                    max=Math.max(max, i-map[sum]);
            }
            System.out.println(max);
        }
    }
}