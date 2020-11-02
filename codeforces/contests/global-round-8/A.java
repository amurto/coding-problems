import java.util.*;
import java.lang.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            String[] line = br.readLine().split(" ");
            long a = Long.parseLong(line[0]);
            long b = Long.parseLong(line[1]);
            long n = Long.parseLong(line[2]);
            long ans = 0L, temp = 0L;
            while (a<=n && b<=n) {
                if (a>b) {
                    temp = a;
                    a = b;
                    b = temp;
                }
                a+=b;
                ans++;
            }
            System.out.println(ans);
            t--; 
        }
    }

}
