import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            int n = Integer.parseInt(br.readLine());

            String s = br.readLine();
            char[] c = s.toCharArray();
            int i=0, j=n-1;
            while (i<n && c[i] == ')') i++;
            while (j>0 && c[j] == '(') j--;
            int L = i, R = n-1-j;
            if (L == R) 
                System.out.println(L);
            else {
                Boolean start = false;
                int trash = Math.min(L, R);
                int k = Math.abs(L-R);
                if (L > R)
                    i-=k;
                else 
                    j+=k;
            int count = 0, trash = Math.abs(L-R);
            while (i < j) {
                if (c[i] == '(')
                    start = true;
                else {
                    trash++;
                    i++;
                }
                if (start) {
                    while (i < n && c[i] == '(') {
                        count++;
                        i++;
                    }
                    while (i < n && c[i] == ')') {
                        count--;
                        i++;
                    }
                    trash = trash + Math.abs(count);
                    start = false;
                    count = 0;
                }
            }
            }
            
            // System.out.println(trash/2);
            t--;
        }
    }
}
