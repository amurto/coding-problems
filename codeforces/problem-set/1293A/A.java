import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] line = br.readLine().split(" ");
            long n = Long.parseLong(line[0]);
            long s = Long.parseLong(line[1]);
            long k = Long.parseLong(line[2]);
            String[] kline = br.readLine().split(" ");
            ArrayList<Long> arr = new ArrayList<>();
            for (String kl : kline)
                arr.add(Long.parseLong(kl));
            for (int i = 0; i <= k; i++) {
                if (s - i > 0 && !arr.contains(s - i)) {
                    System.out.println(i);
                    break;
                }
                if (s + i <= n && !arr.contains(s + i)) {
                    System.out.println(i);
                    break;
                }
            }
        }
    }
}