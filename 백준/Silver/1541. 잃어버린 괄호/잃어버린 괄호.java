import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        String str = st.nextToken();

        String[] s = str.split("-");

        // char[] charArr = str.toCharArray(); // 문자열 한 문자씩 분리해서 char 배열로 빈환


        // 흠 55-50+40면 2개로 나뉜다는 건데
        // 55, 50+40
        // 여기서 일단 각각 더한다음에 -하면 될 것 같음

        int sum = plusSum(s[0]);

        for(int i = 1; i < s.length; i++){
            String temp = s[i];

            plusSum(temp);

            sum = sum - plusSum(temp);

        }
        System.out.println(sum);
    }

    static int plusSum(String s) {

        int sum = 0;
        String[] temp = s.split("[+]");

        for(int i = 0; i < temp.length; i++){
            sum = sum + Integer.parseInt(temp[i]);
        }
        
        return sum;

    }

}