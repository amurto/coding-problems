import java.util.*;

public class bn {
    public static Vector<Vector<Integer>> a = new Vector<Vector<Integer>>();
    public static Vector<Boolean> visited = new Vector<Boolean>();
    public static Vector<Integer> store = new Vector<Integer>();

    public static void dfs(int u) {
        visited.set(u, true);
        store.add(u);
        for (int i = 0; i < a.get(u).size(); i++) {
            if (!visited.get(i)) {
                dfs(a.get(u).get(i));
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        a.add(0, new Vector<Integer>());
        a.add(1, new Vector<Integer>());
        visited.add(0, false);
        visited.add(1, false);
        for (int i = 2; i <= n; i++) {
            a.add(i, new Vector<Integer>());
            a.get(i).add(in.nextInt());
            visited.add(false);
        }
        in.close();
        dfs(n);
        for (int i = store.size() - 1; i >= 0; i--)
            System.out.print(store.get(i) + " ");
    }
}