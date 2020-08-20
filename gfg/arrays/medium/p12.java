// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
// Maximum of all subarrays of size k 

import java.util.*;
import java.io.*;

public class p12 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            int k = Integer.parseInt(params[1]);
            int[] a = new int[n];
            String[] line = br.readLine().split(" ");
            StringBuffer sb = new StringBuffer();
            for (int i=0; i<n; i++) 
                a[i] = Integer.parseInt(line[i]);
            Deque<Integer> dq = new LinkedList<Integer>();
            for (int i=0; i<k; i++){
                while (!dq.isEmpty() && a[i]>=a[dq.peekLast()]) 
                    dq.removeLast();
                dq.add(i);
            }

            for (int i=k; i<n; i++) {
                sb.append(a[dq.peek()] +" ");
                if (!dq.isEmpty() && dq.peek()<=i-k)
                    dq.removeFirst();
                while (!dq.isEmpty() && a[i]>=a[dq.peekLast()]) 
                    dq.removeLast();
                dq.add(i);
            }
            sb.append(a[dq.peek()] +" ");
            System.out.println(sb);
        }
    }
}