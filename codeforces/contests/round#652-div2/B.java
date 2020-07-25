import java.util.*;
import java.io.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split("");
            ArrayList<Integer> arr = new ArrayList<Integer>();
            int ans =0,p=n-1, q=0;
            for (String s: line) 
                arr.add(Integer.parseInt(s));
            for (int i=0; i<n ;i++) {
                if (arr.get(i) == 1) {
                    while (i<n && arr.get(i) == 1 ) i++;
                    if (i==n)
                        break;
                    else 
                        ans=1;
                } 
            }
            while (q < n && arr.get(q) == 0) {
                System.out.print(0);
                q++;
            }
            if (ans>0)
                System.out.print(0);
            while (p>= 0 && arr.get(p) == 1) {
                System.out.print(1);
                p--;
            } 
            System.out.println();
            t--;
        }
    }
}
