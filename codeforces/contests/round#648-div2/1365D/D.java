import java.util.*;
import java.io.*;

public class D {
    final static int dx[] = { 0, 0, 1, -1 };
    final static int dy[] = { 1, -1, 0, 0 };
    public static ArrayList<List<Character>> maze = new ArrayList<List<Character>>();
    public static ArrayList<List<Integer>> vis = new ArrayList<List<Integer>>();
    public static Deque<List<Integer>> Bstack = new LinkedList<List<Integer>>();
    public static int n, m, count = 0;

    public static Boolean isValid(int i, int j) {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        else
            return false;
    }

    public static Boolean findBadNodes() {
        Boolean valid = true;
        outerloop: while (!Bstack.isEmpty()) {
            int p = Bstack.peek().get(0);
            int q = Bstack.peek().get(1);
            Bstack.pop();
            maze.get(p).set(q, '#');
            for (int i = 0; i < 4; i++) {
                int pi = p + dx[i];
                int qi = q + dy[i];
                if (isValid(pi, qi)) {
                    char tmp = maze.get(pi).get(qi);
                    if (tmp == 'G' || (pi == n - 1 && qi == m - 1)) {
                        valid = false;
                        break outerloop;
                    }
                    if (tmp == '.')
                        maze.get(pi).set(qi, '#');
                }
            }
        }
        return valid;
    }

    public static void dfs(int p, int q) {
        vis.get(p).set(q, 1);
        for (int i = 0; i < 4; i++) {
            int pi = p + dx[i];
            int qi = q + dy[i];
            if (isValid(pi, qi) && vis.get(pi).get(qi) < 1 && maze.get(pi).get(qi) != '#') {
                if (maze.get(pi).get(qi) == 'G')
                    count--;
                dfs(pi, qi);
            }
        }
        return;
    }

    public static Boolean dfsGoodNodes() {
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> zeros = new ArrayList<>(Arrays.asList(new Integer[m]));
            Collections.fill(zeros, 0);
            vis.add(zeros);
        }
        dfs(n - 1, m - 1);
        if (count > 0)
            return false;
        else
            return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        while (t > 0) {
            count = 0;
            n = in.nextInt();
            m = in.nextInt();
            for (int i = 0; i < n; i++) {
                ArrayList<Character> temp = new ArrayList<Character>();
                String line = in.next();
                char[] tokens = line.toCharArray();
                for (int j = 0; j < m; j++) {
                    if (tokens[j] == 'B')
                        Bstack.push(Arrays.asList(i, j));
                    else if (tokens[j] == 'G')
                        count++;
                    temp.add(tokens[j]);
                }
                maze.add(temp);
            }

            if (findBadNodes()) {
                if (dfsGoodNodes())
                    System.out.println("Yes");
                else
                    System.out.println("No");
            } else {
                if (count == 0)
                    System.out.println("Yes");
                else
                    System.out.println("No");
            }

            Bstack.clear();
            maze.clear();
            vis.clear();
            t--;
        }
        in.close();
    }
}