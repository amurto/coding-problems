import java.io.*;

public class rps {
    public static int winner(String x, String y) {
        if (x.equals(y)) {
            return 0;
        } else {
            if (x.equals("rock")) {
                if (y.equals("scissors"))
                    return 1;
                else
                    return -1;
            } else if (x.equals("paper")) {
                if (y.equals("rock"))
                    return 1;
                else
                    return -1;
            } else {
                if (y.equals("paper"))
                    return 1;
                else
                    return -1;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] players = new String[3];
        char[] names = { 'F', 'M', 'S' };
        players[0] = br.readLine();
        players[1] = br.readLine();
        players[2] = br.readLine();
        int score = 0;
        for (int i = 0; i < 3; i++) {
            score = 0;
            score = score + winner(players[i], players[(i + 1) % 3]) + winner(players[i], players[(i + 2) % 3]);
            if (score == 2) {
                System.out.println(names[i]);
                break;
            }
        }
        if (score < 2)
            System.out.println("?");
    }
}