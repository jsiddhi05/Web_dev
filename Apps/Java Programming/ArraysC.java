import java.util.*;
public class ArraysC
{
    public static void update(int marks[]){
        for(int i=0; i<marks.length; i++){
            marks[i]= marks[i] +1;
        }
    }
    public static void main(String args[]){
       /* int marks[]={99,98,100};
        update(marks);

        //print our marks
        for(int i=0;i<marks.length;i++){
            System.out.print(marks[i]+" ");
        }
    
        System.out.println();
    }*/

    /* Inserting ,displaying and updating array elements   */
       Scanner sc= new Scanner (System.in);

       System.out.println("The size of an array is :");
       int size = sc.nextInt();

       int arr[]=new int[size];
    
       // Insering array elements
       System.out.println("Enter"+size+"Elements");
       for(int i=0;i<size;i++){
        arr[i]=sc.nextInt();
       } 

       //Displaying array elements
       System.out.println("The array elements are:");
       for(int i=0;i<size;i++){
         System.out.println(arr[i]+"");
       }

       System.out.println();

       //updating array elements 

       System.out.println("Enter the array element to update:");
       int index= sc.nextInt();

       if(index>=0 && index< size){
        System.out.println("Enter new elements are:");
        int newVal= sc. nextInt();
        arr[index]=newVal;
       }

        //Displaying the updated elements 

        System.out.println("The updated elements are :");
        for(int i=0; i<size ;i++){
            System.out.println(arr[i]+" ");

        }
        sc.close();
       


    }

}   