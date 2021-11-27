package chap20;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class CopyFileDemo {

    public static void main(String[] args) {
        String input = "C:\\Temp\\org.txt";
        String output = "C:\\Temp\\dup.txt";

        try (FileInputStream fis = new FileInputStream(input); 
                FileOutputStream fos = new FileOutputStream(output)) {
            int c;

            while ((c = fis.read()) != -1)
                fos.write(c);
        } catch (IOException e) {
        }

    }
}
