// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0
// Find Missing And Repeating

import java.util.*;
import java.io.*;

public class p14 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] line = br.readLine().trim().split(" ");
            int[] a = new int[1000001];
            for (int i=0; i<n; i++) {
                if (a[i] == 0)
                    a[i]=Integer.parseInt(line[i]);
                else
                    a[i]*=Integer.parseInt(line[i]);
                if (a[Math.abs(a[i])] == 0)
                    a[Math.abs(a[i])] = -1;
                else
                    a[Math.abs(a[i])]*=-1;
            }
            int repeat=0;
            for (int i=0; i<n; i++) {
                if (a[Math.abs(a[i])]>=0){
                    repeat = Math.abs(a[i]);
                    break;
                }
            }
            int smallest=0, j=1;
            while (smallest<1) {
                if (a[j] >= 0 && j!= repeat)
                    smallest=j;
                j++;
            }
            System.out.println(repeat + " " + smallest);
        }
    }
}