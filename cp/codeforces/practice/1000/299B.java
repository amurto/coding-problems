import java.util.Scanner;

public class kts {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        String s = in.next();
        in.close();
        char[] input = s.toCharArray();
        int c = 0;
        int j = k, temp = 0;
        while (c < n - 1) {
            j = k;
            temp = c;
            while (j > 0) {
                if (c + j < n && input[c + j] == '.') {
                    c = c + j;
                    break;
                }
                c--;
            }
            if (c == temp)
                break;
        }
        if (c == n - 1)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}