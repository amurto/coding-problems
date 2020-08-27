// https://practice.geeksforgeeks.org/problems/minimum-platforms/0
// Minimum Platforms

import java.util.*;
import java.io.*;

public class p27 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] arrival = br.readLine().trim().replaceAll("  "," ").split(" ");
            String[] departure = br.readLine().trim().replaceAll("  "," ").split(" ");
            int[] arr = new int[n];
            int[] dep = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(arrival[i]);
                dep[i] = Integer.parseInt(departure[i]);
            }
            Arrays.sort(arr);
            Arrays.sort(dep);
            int p = 1, res=1, i=1,j=0;
            while (i<n && j<n) {
                if (arr[i] <=dep[j]) {
                    p++;
                    i++;
                }  
                else {
                    p--;
                    j++;
                }
                res=Math.max(res, p);
            }
            System.out.println(res);
        }
    }
}