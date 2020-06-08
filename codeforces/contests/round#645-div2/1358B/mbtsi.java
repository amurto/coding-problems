import java.util.*;
import java.io.*;

public class mbtsi {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        int n;
        while (t > 0) {
            n = in.nextInt();
            PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> o1 - o2);
            for (int i = 0; i < n; i++)
                pq.add(in.nextInt());
            int temp, current = 1;
            for (int i = 0; i < n; i++) {
                temp = pq.poll();
                if (temp <= i + 1) {
                    current = i + 2;
                }
            }
            System.out.println(current);

            t--;
        }
        in.close();
    }
}