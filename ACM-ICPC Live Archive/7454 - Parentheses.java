import java.util.Scanner;

public class Main {
    public static boolean isO(String s){
        for(int i=0;i<s.length();i++)
            if(s.charAt(i)!='(')
                return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tCase = sc.nextInt();
        for(int k=0;k<tCase;k++){
            int n = sc.nextInt();
            String s = sc.next();
            int count =0;
            s=f(s);
            while(true){
                if(isO(s)){
                    count+=s.length()/2;
                    break;
                }
                if(s.charAt(0)==')')
                {
                    String news ="(";
                    for(int i=1;i<s.length();i++){
                        news+=s.charAt(i);
                    }
                        s = f(news);
                        count++;
                }
                else{
                    count+=s.length();
                    break;
                }
            }
            System.out.println(count);
        }
        
    }
    public static String f(String s) {
        boolean[] ok = new boolean[101];
        for(int i=0;i<s.length()-1;i++){
            if(s.charAt(i)=='(' && !ok[i]){
                for(int j=i+1;j<s.length();j++){
                    if(s.charAt(j)==')' && !ok[j]){
                        ok[i] = true;
                        ok[j] = true;
                        break;
                    }
                }
            }
        }
        String news = "";
        for(int i=0;i<s.length();i++){
            if(ok[i]==false){
                news+=s.charAt(i);
            }
                
        }
        return news;
    }
    
}
