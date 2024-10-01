import java.util.*;
public class TrappedRainWater
{
    public static int trappedWater (int heigth[] ){
        //calculate left max boundary-array
        int n = heigth.length;
        int LeftMax[]=new int[n];
        LeftMax[0] =heigth[0];
        for(int i=1; i<n ;i++){
            LeftMax[i] = Math.max(heigth[i], LeftMax[i-1]);
        }


        //calculate rigth max boundary - array auxilary
        int RightMax[]= new int[n];
        RightMax[n-1] =heigth[n-1];
        for(int i=n-2 ; i>=0;i--){
            RightMax[i]=Math.max(heigth[i],RightMax[i+1]);
            
        }

       

        int trappedWater= 0;
        //loop
        for (int i=0;i<n;i++){
            //waterLevel =min (leftMax bound, rigth bound)
            int waterLevel=Math.min(LeftMax[i],RightMax[i]);
            //Trapped water = water level - heigth[i] of bar
        trappedWater += waterLevel-heigth[i];
        }
        return trappedWater;
        
    }

    
	public static void main(String[] args) {
        int heigth[]={4,2,0,6,3,2,5};
        System.out.println(trappedWater(heigth));
    }

}