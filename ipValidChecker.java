import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

class IPCheck{

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("Please input a IP address to check for validity. Enter Done is you are done.");
        while(in.hasNext()){
            String IP = in.next();
            //Added in way to end upon entering string Done in interaction panel
            if(IP.equals("Done") == true){
              break;
            }
            System.out.println(IP.matches(new MyRegex().pattern));
        }
        in.close();
    }
}

class MyRegex extends IPCheck{
    /**
    Pattern is ###.###.###.### where the (#) can be any amount between 1-3
    String may ONLY contain periods(three ".") and Digits
    May not include alphabetic characters or non numeric characters(other than period)
    All subsets of numbers may NOT exceed 255. so A, B, C, and D may be between 0 - 255
    */

    public String pattern = "(([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.){3}([01]?\\d\\d?|2[0-4]\\d|25[0-5])";

    /**
    String pattern has a regular ip pattern where any given input in correct format
    may not have any subsection above 255. includes 255 as a valid input
    */


}
