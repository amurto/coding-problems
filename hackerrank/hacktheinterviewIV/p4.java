import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class p4 {
    
    final static int N = 100;
    public static int boolToInt(boolean b) {
        return Boolean.compare(b, false);
    }

    public static Boolean intToBool(int i) {
        return i > 0 ? true : false;
    }

    public static BigInteger k_nonzero_numbers(String s, int n, int k) {
        ArrayList<List<List<BigInteger>>> dp = new ArrayList<List<List<BigInteger>>>();
        for (int i = 0; i <= N; i++) {
            dp.add(new ArrayList<>());
            for (int j = 0; j <= N; j++) {
                dp.get(i).add(new ArrayList<>());
                for (int x = 0; x <= N; x++) {
                    dp.get(i).get(j).add(BigInteger.ZERO);
                }
            }
        }
        dp.get(0).get(0).set(0, BigInteger.ONE);
        for (int i = 0; i < n; ++i) {
            int sm = 0;
            while (sm < 2) {
                for (int j = 0; j < k + 1; ++j) {
                    int x = 0;
                    while (x <= (sm > 0 ? 9 : s.charAt(i) - '0')) {
                        int idx = boolToInt(intToBool(sm) || x < (s.charAt(i) - '0'));
                        int jdx = j + (x > 0 ? 1 : 0);
                        
                        BigInteger a = dp.get(i+1).get(idx).get(jdx);
                        BigInteger b = dp.get(i).get(sm).get(j);
                        a = a.add(b);
                        // System.out.print(b);
                        dp.get(i + 1).get(idx).set(jdx, a);
                        ++x;
                    }
                }
                ++sm;
            }
        }
        BigInteger first = dp.get(n).get(0).get(k);
        BigInteger second = dp.get(n).get(1).get(k);
        dp.clear();
        return first.add(second);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        String L = in.next();
        String R = in.next();
        int K = in.nextInt();
        int n = L.length();
        int m = R.length();
        
            
        BigInteger c1 = k_nonzero_numbers(L, n, K);
        BigInteger c2 = k_nonzero_numbers(R, m, K);
        System.out.println(c2.subtract(c1));
    }
}