import java.util.*;
import java.io.*;

public class ip {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        Long m, num, t;
        t = in.nextLong();
        while (t > 0) {
            num = in.nextLong();
            Long evn = 0L, odd = 0L;
            for (Long i = 0L; i < num; i++) {
                m = in.nextLong();
                if (m % 2 == 1)
                    odd++;
                else
                    evn++;
            }
            num = in.nextLong();
            Long ans = 0L;
            for (Long i = 0L; i < num; i++) {
                m = in.nextLong();
                if (m % 2 == 1)
                    ans += odd;
                else
                    ans += evn;
            }
            t--;
            System.out.println(ans);
        }
        in.close();
    }
}