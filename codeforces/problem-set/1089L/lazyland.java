import java.io.*;
import java.util.*;

public class lazyland {

    final static int MAX = 100000;

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        PrintStream out = System.out;
        int n = in.nextInt(), k = in.nextInt();
        HashSet<Integer> set = new HashSet<>();
        int[] a = new int[n], b = new int[n];
        int[] times = new int[MAX];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            set.add(a[i]);
            times[a[i]]++;
        }
        for (int i = 0; i < n; i++)
            b[i] = in.nextInt();
        int noChose = k - set.size();
        if (noChose == 0) {
            out.println(0);
            return;
        }
        Queue<Integer> pq = new PriorityQueue<>((o1, o2) -> o2 - o1);
        HashMap<Integer, Integer> maxMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (times[a[i]] <= 1)
                continue;
            if (maxMap.get(a[i]) == null) {
                maxMap.put(a[i], b[i]);
            } else {
                Integer pMax = maxMap.get(a[i]);
                if (pMax < b[i]) {
                    if (noChose == pq.size()) {
                        if (pMax < pq.peek()) {
                            pq.poll();
                            pq.add(pMax);
                        }
                    } else {
                        pq.add(pMax);
                    }
                    maxMap.put(a[i], b[i]);
                } else {
                    if (noChose == pq.size()) {
                        if (b[i] < pq.peek()) {
                            pq.poll();
                            pq.add(b[i]);
                        }
                    } else {
                        pq.add(b[i]);
                    }
                }
            }
        }
        long res = 0;
        while (!pq.isEmpty())
            res += pq.poll();
        out.println(res);
    }
}