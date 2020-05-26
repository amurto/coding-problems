import java.util.*;
import java.io.*;

public class pl {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        int n,m;
        while(t>0) {
            n = in.nextInt();
            m = in.nextInt();
            int ans = 0;
            ans = (n/2)*m + (n%2)*(m/2 + m%2);
            System.out.println(ans);
            t--;
        }
        in.close();
    }
}