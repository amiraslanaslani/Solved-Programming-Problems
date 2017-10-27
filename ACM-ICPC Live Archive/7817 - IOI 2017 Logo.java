import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n;
        while(true){
            n = scn.nextInt();
            if(n == 0)
                break;
            
            HashMap<Integer, Integer> logos = new HashMap<>();
            int di;
            for(int i = 0;i < n;i ++){
                di = scn.nextInt();
                for(int j = 0;j < di;j ++){
                    int lid = scn.nextInt();
                    if(! logos.containsKey(lid))
                        logos.put(lid, 100000000);
                    Integer currentLogo = logos.get(lid);
                    switch(j){
                        case 0:
                            currentLogo += 3010000;
                            break;
                        case 1:
                            currentLogo += 2000100;
                            break;
                        case 2:
                            currentLogo += 1000001;
                            break;
                    }
                    logos.replace(lid, currentLogo);
                }
            }
            
            Integer maxi = -1;
            for(Integer v : logos.values())
                maxi = Math.max(maxi, v);
            
            ArrayList<Integer> keys = new ArrayList<>();
            for(Integer k : logos.keySet())
                if(logos.get(k).equals(maxi))
                    keys.add(k);
            
            Collections.sort(keys);
            int z = 0;
            for(Integer i : keys){
                if(z != 0)
                    System.out.print(" ");
                z ++;
                System.out.print(i);
            }
            System.out.println("");
        }
    }
}
