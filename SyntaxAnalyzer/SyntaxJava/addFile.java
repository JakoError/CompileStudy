import java.io.*;

import static java.lang.Character.toLowerCase;
import static java.lang.Character.toUpperCase;

public class addFile {
    public static void main(String[] args) {
        File file = new File("D:\\rdcheck.java");
        String str = "";
        while (true){
            try {
                BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
                str = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                StringBuilder sb = new StringBuilder(str);
                sb.replace(0, 1, String.valueOf(toLowerCase(sb.charAt(0))));
                BufferedWriter writer = new BufferedWriter(new FileWriter(file, true));
                String out = "    public static Bean " + str + "() {\n" +
                        "        Bean " + sb.toString() + " = new Bean(\"" + str + "\");\n" +
                        "    }";
                writer.write(out);
                writer.newLine();
                writer.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }

    }
}
