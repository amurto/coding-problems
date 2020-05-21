// String matching
import java.util.Scanner; 

public class fn {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String line = in.next();
        in.close();
        char[] heidi = {'h', 'e', 'i', 'd', 'i'};
        char[] sent = line.toCharArray();
        int c = 0;
        for (int i=0;i<sent.length;i++) {
            if (sent[i] == heidi[c])
                c++;
            if (c==5) 
                break;
        }
        if (c==5) 
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}