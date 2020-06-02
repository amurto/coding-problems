import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class p3 {
    final static int N = 300;
    final static int dx[] = { 0, 0, 1, -1 };
    final static int dy[] = { 1, -1, 0, 0 };
    public static List<List<Integer>> arr = new ArrayList<>();
    public static List<List<Integer>> vis = new ArrayList<>();
    public static List<List<Integer>> d = new ArrayList<>();
    public static Deque<List<Integer>> q = new LinkedList<List<Integer>>();
    public static ArrayList<List<List<Integer>>> prev = new ArrayList<List<List<Integer>>>();
    public static int n;
    public static int m;

    public static Boolean isValid(int g, int h) {
        if (g < 0 || g >= n || h < 0 || h >= m || vis.get(g).get(h) == 1)
            return false;
        else
            return true;
    }

    public static Boolean inQueue(int e, int f) {
        if (!q.isEmpty() && q.peekLast().get(0) == e && q.peekLast().get(1) == f)
            return true;
        else
            return false;
    }

    public static int distance(int e, int f, int g, int h) {
        int prevDis = d.get(e).get(f);
        int distance = Math.abs(arr.get(e).get(f) - arr.get(g).get(h));
        if (prevDis == -1)
            return distance;
        else
            return prevDis > distance ? prevDis : distance;
    }

    public static void bfs(int rem) {
        int pop = 0;

        while (rem > 0) {
            List<Integer> temp = q.poll();
            int e = temp.get(0);
            int f = temp.get(1);
            vis.get(e).set(f, 1);
            for (int i = 0; i < 4; i++) {
                if (isValid(e + dx[i], f + dy[i])) {
                    int dis = distance(e, f, e + dx[i], f + dy[i]);
                    if (d.get(e + dx[i]).get(f + dy[i]) == -1 || dis < d.get(e + dx[i]).get(f + dy[i])) {
                        d.get(e + dx[i]).set(f + dy[i], dis);
                        prev.get(e + dx[i]).set(f + dy[i], Arrays.asList(e, f));
                    }
                    if (!inQueue(e + dx[i], f + dy[i])) {
                        q.add(Arrays.asList(e + dx[i], f + dy[i]));
                        pop++;
                    }
                } else if (e + dx[i] >= 0 && e + dx[i] < n && f + dy[i] >= 0 && f + dy[i] < m
                        && vis.get(e + dx[i]).get(f + dy[i]) > 0) {
                    int x = prev.get(e + dx[i]).get(f + dy[i]).get(0);
                    int y = prev.get(e + dx[i]).get(f + dy[i]).get(1);
                    if (x != -1 && y != -1 && x != e && y != f) {
                        int dis = distance(e, f, e + dx[i], f + dy[i]);
                        if (d.get(e + dx[i]).get(f + dy[i]) == -1 || dis < d.get(e + dx[i]).get(f + dy[i])) {
                            d.get(e + dx[i]).set(f + dy[i], dis);
                            prev.get(e + dx[i]).set(f + dy[i], Arrays.asList(e, f));
                        }
                    }
                }
            }
            rem--;
        }
        if (pop > 0)
            bfs(pop);
        else
            return;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");
        n = Integer.parseInt(firstMultipleInput[0]);
        m = Integer.parseInt(firstMultipleInput[1]);

        IntStream.range(0, n).forEach(i -> {
            try {
                arr.add(Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" ")).map(Integer::parseInt)
                        .collect(toList()));
                List<List<Integer>> t = new ArrayList<List<Integer>>();
                for (int j = 0; j < m; j++)
                    t.add(Arrays.asList(-1, -1));
                prev.add(t);
                ArrayList<Integer> zeros = new ArrayList<>(Arrays.asList(new Integer[m]));
                Collections.fill(zeros, 0);
                vis.add(zeros);
                ArrayList<Integer> negs = new ArrayList<>(Arrays.asList(new Integer[m]));
                Collections.fill(negs, -1);
                d.add(negs);
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });
        q.add(Arrays.asList(0, 0));
        bfs(1);
        System.out.println(d.get(n - 1).get(m - 1));
        bufferedReader.close();
    }
}