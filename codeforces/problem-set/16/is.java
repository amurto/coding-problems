import java.util.Scanner;

public class is {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        String line;
        String[][] input = new String[n][2];
        for (int i = 0; i < n; i++) {
            line = in.nextLine();
            String[] s = line.split(" ");
            input[i][0] = s[0];
            input[i][1] = s[1];
        }
        in.close();
        int c, ans = 0;
        for (int i = 0; i < n; i++) {
            c = 0;
            for (int j = 0; j < i; j++) {
                if (input[i][0].equals(input[j][0]) && input[i][1].equals(input[j][1])) {
                    c++;
                    break;
                }
            }
            if (c==0) 
                ans++;
        }
        System.out.println(ans);
    }
}