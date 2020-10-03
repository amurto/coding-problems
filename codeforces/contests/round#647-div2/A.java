import java.util.*;
import java.io.*;

public class A {
    public static long getSmall(long n) {
        while(n%2 == 0)
            n/=2;
        return n;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        while (t>0) {
            long a = in.nextLong();
            long b = in.nextLong();
            if (a>b) {
                long temp = a;
                a = b;
                b = temp;
            }
            long aSmall = getSmall(a);
            if (getSmall(b) != aSmall) 
                System.out.println(-1);
            else {
                int ans = 0;
                b/=a;
                while(b>=8) {
                    ans++;
                    b/=8;
                }
                if (b>1) 
                    ans++;
                System.out.println(ans);
            }
            t--;
        }
        
    }
}