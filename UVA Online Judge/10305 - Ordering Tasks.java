
import java.util.HashSet;
import java.util.Scanner;
import java.util.Stack;

/**
 *
 * @author Amir Aslan Aslani
 */
public class Main {

    public static int[] topologicalSort(boolean[][] mat){
        Stack<Integer> s = new Stack<>();
        HashSet<Integer> v = new HashSet<>();
        int n = mat.length;
        int[] out = new int[n];
        int op = 0;

        for(int i = 0;i < n;i ++){
            boolean find = true;
            for(int j = 0;j < n;j ++){
                if(mat[j][i]){
                    find = false;
                    break;
                }
            }
            if(find){
                s.push(i);
            }
        }

        while(! s.empty()){
            int p = s.pop();
            v.add(p);
            out[op ++] = p + 1;

            for(int i = 0;i < n;i ++){
                if(mat[p][i]){
                    boolean hasBroken = false;
                    for(int j = 0;j < n;j ++){
                        if(mat[j][i] && i != j && ! v.contains(j)){
                            hasBroken = true;
                            break;
                        }
                    }
                    if(! hasBroken && ! v.contains(i)){
                        s.push(i);
                    }
                }
            }
        }
        
        return out;
    }
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        
        while(true){
            int n = scn.nextInt();
            int m = scn.nextInt();
            
            if(n == 0 && m == 0)
                break;
            
            boolean mat[][] = new boolean[n][n];
            
            for(int i = 0;i < m;i ++){
                int t1 = scn.nextInt();
                int t2 = scn.nextInt();
                mat[t1-1][t2-1] = true;
            }
            
            int[] ts = topologicalSort(mat);
            for(int d : ts)
                System.out.print(d + " ");
            
            System.out.println();
        }
    }
    
}
