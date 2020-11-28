import java.util.*;
import java.io.*;

public class E {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int n = in.nextInt();
        ArrayList<Long> arr = new ArrayList<Long>();
        arr.add(0L);
        for (int i = 1; i <= n; i++)
            arr.add(in.nextLong());
        in.close();
        long ans = 0;
        for (int i = 1; i <= n; i++) 
            for (int j = i; j <= n; j++)
                for (int k = j; k <= n; k++)
                    ans = Math.max(ans, (arr.get(i) | arr.get(j) | arr.get(k)));
        
        System.out.println(ans);

    }
}