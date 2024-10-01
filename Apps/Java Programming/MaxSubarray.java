import java.util.*;
public class MaxSubarray
{
    public static void maxSubarraySum(int numbers[]){
        int CurrSum=0;
        int maxSum= Integer.MIN_VALUE;



        for(int i=0; i<numbers.length;i++){
            int start=i;
            for (int j=i;j<numbers.length;j++){
                int end=j;
                CurrSum=0;
                for (int k=start; k<=end;k++){
                   //Subarrays sum
                   CurrSum += numbers[k];

                }
                System.out.println(CurrSum);
                if(maxSum<CurrSum){
                    maxSum=CurrSum;
                }
                System.out.println();
            }
        }
        System.out.print("MAXIMUM subarrays =" + maxSum);

    }
	public static void main(String[] args) {
        int numbers[]={1,-2,6,-1,3};
        maxSubarraySum(numbers);




    }

}