// https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k/0
// Sub-Array sum divisible by K

import java.util.*;
import java.io.*;

public class p22 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            int k = Integer.parseInt(params[1]);
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
            int sum=0, c=0;
            int[] map = new int[k];
            map[0]=1;
            for (int i=0; i<n;i++) {
                sum+=a[i];
                sum=((sum%k)+k)%k;
                map[sum]++;
            }
            for (int i=0; i<k;i++) 
                if (map[i] > 1) 
                    c+=map[i]*(map[i]-1)/2;
            System.out.println(c);
        }
    }
}