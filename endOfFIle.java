import java.io.*;
import java.util.*;

public class Solution {

//Will return inputs until end of given input is reached

    public static void main(String[] args) {
        Scanner scan =  new Scanner(System.in);
        String s;
        int i = 1;
        while(scan.hasNext()){
            s = scan.nextLine();
            System.out.println(i + " " + s);
            i += 1;
        }
        scan.close();

    }
}
