import java.util.*;
import java.io.*;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        ArrayList<Long> a = new ArrayList<Long>();
        for (String s : line)
            a.add(Long.parseLong(s));
        long[] b = new long[n];
        for (int bit = 0; bit < 20; bit++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += ((a.get(i) >> bit) & 1);
            }
            for (int i = 0; i < cnt; i++) {
                b[i] |= 1 << bit;
            }
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += b[i] * b[i];
        }
        System.out.println(ans);
    }
}
