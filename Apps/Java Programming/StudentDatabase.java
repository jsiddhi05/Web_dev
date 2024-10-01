import java.util.*;
class StudentDatabase{
    
     int roll_no;
     String name;
     int sgpa;
public void Data (int roll_no,String name,int sgpa){
    this.roll_no=roll_no;
    this.name=name;
    this.sgpa=sgpa;

}       
public void Print(){
    System.out.println("Enter the roll_no:"+roll_no);
    System.out.println("Enter the Student name:"+name);
    System.out.println("Enter the Student sgpa:"+sgpa);

}
public static void main (String args[]){
    StudentDatabase S1=new StudentDatabase();
    S1.Data(1,"Siddhi",8);


    //StudentDatabase S1=new StudentDatabase();
    S1.Print();
}
    
}