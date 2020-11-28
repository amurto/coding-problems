import java.util.*;
import java.lang.*;
import java.io.*;

public class B {
    public static long getAns(long n) {
        long m=0L;
        while (n>1) {
            if (n%6 == 0)
                n=n/6;
            else
                n=n*2;
            m++;
        }
        if (n==1)
            return m;
        else
            return -1L;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            long n = Long.parseLong(br.readLine());
            if (n> 1 && n%3 > 0)
                System.out.println(-1);
            else {
                System.out.println(getAns(n));
            }
            t--; 
        }
    }

}
