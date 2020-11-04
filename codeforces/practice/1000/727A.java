import java.util.*;
import java.io.*;

public class transformation {
    public static long a, b;
    public static Deque<Long> stack = new LinkedList<Long>();

    public static void dfs(long n) {
        if (n > b)
            return;
        stack.push(n);
        if (n == b) 
            return;
        long x = 2 * n;
        long y = n * 10 + 1;
        dfs(x);
        if (!stack.isEmpty() && stack.peek() == b)
            return;
        dfs(y);
        if (!stack.isEmpty() && stack.peek() != b)
            stack.pop();
        return;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        a = in.nextLong();
        b = in.nextLong();
        in.close();
        dfs(a);
        if (stack.isEmpty()) 
            System.out.println("NO");
        else {
            System.out.println("YES");
            System.out.println(stack.size());
            Iterator<Long> itr = stack.descendingIterator();
            while (itr.hasNext()) {
                System.out.print(itr.next() + " ");
            }
        }
    }
}