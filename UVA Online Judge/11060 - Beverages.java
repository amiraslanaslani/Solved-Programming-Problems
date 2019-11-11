

import java.util.HashMap;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;

/**
 *
 * @author Amir Aslan Aslani
 */
public class Main {

    public static int[] topologicalSort(boolean[][] mat){
//        Stack<Integer> s = new Stack<>();
        PriorityQueue<Integer> s = new PriorityQueue<>();
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
                s.add(i);
            }
        }

        while(! s.isEmpty()){
            int p = s.poll();
            v.add(p);
            out[op ++] = p;

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
                        s.add(i);
                    }
                }
            }
        }
        
        return out;
    }
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        
        int ic = 0;
        while(scn.hasNextInt()){
            ic ++;
            int n = scn.nextInt();
            String names[] = new String[n];
            HashMap<String, Integer> indices = new HashMap<>();
            for(int i = 0;i < n;i ++){
                names[i] = scn.next();
                indices.put(names[i], i);
            }
            
            int m = scn.nextInt();
            boolean mat[][] = new boolean[n][n];
            for(int i = 0;i < m;i ++){
                String  b1 = scn.next(),
                        b2 = scn.next();
                
                mat[indices.get(b1)][indices.get(b2)] = true;
            }
            
            int ts[] = topologicalSort(mat);
            System.out.print("Case #" + ic + ": Dilbert should drink beverages in this order:");
            for(int d : ts){
                System.out.print(" " + names[d]);
            }
            
            System.out.println(".\n");
        }
    }
    
}
