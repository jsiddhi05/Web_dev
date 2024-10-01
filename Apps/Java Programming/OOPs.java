public class OOPs {
    public static void main (String args[]){
        Pen p1= new Pen();
        p1.setColor("Blue");
        System.out.print(p1.color);
    }


}

class Pen{
    String color;
    int tip;

    void setColor(String newColor){
        color= newColor;
    }

    void setTip(int Tip){
        this.tip= Tip;
    }
}