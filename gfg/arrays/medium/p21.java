// https://practice.geeksforgeeks.org/problems/rotate-and-delete/0
// Rotate and delete

import java.util.*;
import java.io.*;

public class p21 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n= Integer.parseInt(br.readLine().trim());
            String[] line = br.readLine().trim().split(" ");
            int[] a =new int[n];
            for (int i=0; i<n; i++)
                a[i] = Integer.parseInt(line[i]);
            if (n==1)
                System.out.println(a[n-1]);
            else {
                int ans=n/4;
                if (n%4==1 || n%4==2)
                    ans+=1;
                else if (n%4==3)
                    ans+=2;
                System.out.println(a[ans]);
            }
        }
    }
}