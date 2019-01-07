import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int[] s;
            s = new int[n+1];
            for(int j = 0;j<n;j++){
                if(j == 0){
                s[j] = a + (int) (Math.pow(2.0, j) * b);
                }
                else if(j >= 1){
                    s[j] = (int) (Math.pow(2.0, j) * b);
                    s[j] += s[j-1];
                }
                System.out.print(s[j] + " ");
            }
            System.out.println(" ");
        }

        in.close();
    }
}
