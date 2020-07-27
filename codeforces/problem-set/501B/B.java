import java.util.*;
import java.io.*;
import java.util.Map.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());
        HashMap<String, String> map = new HashMap<String, String>();
        while (q-- > 0) {
            String[] line = br.readLine().split(" ");
            String oldname = line[0];
            String newname = line[1];
            if (map.containsValue(oldname)) {
                for (Entry<String, String> entry : map.entrySet()) {
                    if (entry.getValue().equals(oldname)) {
                        String key = entry.getKey();
                        map.replace(key, newname);
                        break;
                    }
                }
            } else {
                map.put(oldname, newname);
            }
        }
        System.out.println(map.size());
        for (Entry<String, String> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
}