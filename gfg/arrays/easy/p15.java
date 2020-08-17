// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0
// First negative integer in every window of size k

import java.util.*;
import java.io.*;

public class p15 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n];
            Deque<Integer> d = new LinkedList<Integer>();
            String[] arr = br.readLine().split(" ");

            for (int i=0; i<n; i++) 
                a[i] = Integer.parseInt(arr[i]);
            
            int k = Integer.parseInt(br.readLine());
            for (int i=0; i<k; i++) 
                if (a[i]<0)
                    d.add(i);
            
            for (int i=k; i<n;i++) {
                if (d.isEmpty())
                    System.out.print(0+" ");
                else {
                    if (d.peek() == i-k)
                        System.out.print(a[d.poll()]+" ");
                    else
                        System.out.print(a[d.peek()]+" ");
                }

                if (a[i] < 0)
                    d.add(i);
            }
            System.out.print(d.isEmpty() ? 0 : a[d.poll()]);
            System.out.println();
        }
    }
}