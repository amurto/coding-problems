import java.util.Scanner;

public class wtlw {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int len = 0;
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = in.next();
        }
        in.close();
        for (int i = 0; i < n; i++) {
            len = words[i].length();
            if (len > 10) {
                System.out.println(words[i].charAt(0) + "" + (len - 2) + "" + words[i].charAt(len - 1));
            } else {
                System.out.println(words[i]);
            }
        }
    }
}