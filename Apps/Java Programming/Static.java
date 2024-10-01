public class Static{
    public static void main (String args[]){
        Student s1= new Student();
        s1.Schoolname="JMV";
        
        Student s2= new Student();
        System.out.println(s2.Schoolname);
        

    }
}
class Student {
    String name;
    int roll ;

    static String Schoolname;

    void setName(String name ){
        this.name= name;
    }
    String getName(){
        return this.name;
    }
}