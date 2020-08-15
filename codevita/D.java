import java.util.*;
import java.io.*;

public class D {
    public static final String[] tensNames = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
            "eighty", "ninety" };

    public static final String[] numNames = { "", "one", "two", "three", "four", "five", "six", "seven", "eight",
            "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
            "nineteen" };

    public static String toWord(int v) {
        if (v == 100)
            return "hundred";
        else if (v < 20)
            return numNames[v];
        else
            return tensNames[v / 10] + numNames[v % 10];
    }

    public static int countVowels(String word) {
        int v = 0;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                v++;
            }
        }
        return v;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        String[] line = br.readLine().split(" ");
        int v=0;
        int[] count = new int[101];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(line[i]);
            count[a[i]]++;
            v+=countVowels(toWord(a[i]));
        }
        int pairs=0;
        for (int i=0;i<n;i++) {
            if (a[i] < v) {
                if (count[v-a[i]]>0)
                    pairs+=count[v-a[i]];
                if (a[i] == v-a[i])
                    pairs--;
            }
        }
        pairs/=2;
        if (pairs == 0)
            System.out.print("zero");
        else if (pairs>100)
            System.out.print("greater 100");
        else 
            System.out.print(toWord(pairs));
    }
}