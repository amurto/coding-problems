import java.util.*;
import java.io.*;
import java.math.*;

public class eoeo {
    public static long solve(long b) {
        String bin = Long.toBinaryString(b);
        char[] arr = bin.toCharArray();
        int i = arr.length - 1;
        while (arr[i] == '0')
            i--;
        if (i == 0)
            return 0L;
        char[] num = new char[i];
        for (int j = 0; j < i; j++)
            num[j] = arr[j];
        String ans = new String(num);
        return new BigInteger(ans, 2).longValue();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            long a = Long.parseLong(br.readLine());
            if (a % 2L > 0) {
                System.out.println(a / 2);
            } else {
                long res = solve(a);
                System.out.println(res);
            }
            t--;
        }
    }
}
