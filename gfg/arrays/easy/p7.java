// Largest Fibonacci Subsequence
// https://practice.geeksforgeeks.org/problems/largest-fibonacci-subsequence/0

import java.util.*;
import java.io.*;

public class p6 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] count = new int[1001];
            int beg = 0, sec = 1;
            count[0]++;count[1]++;
            while (beg + sec <= 1000) {
                int temp = beg+sec;
                count[temp]++;
                beg = sec;
                sec = temp;
            }
            
            for (int i=0; i<n; i++) {
                int v = Integer.parseInt(line[i]);
                if (count[v]>0)
                    System.out.print(v + " ");
            }
            System.out.println();
        }
    }
}