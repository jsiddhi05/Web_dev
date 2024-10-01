import java.util.*;
class Complex{
    int real;
    int img;
public Complex(int r,int i){
        real =r; 
        img=i;
    }
public static Complex add(Complex a,Complex b){
    return new Complex((a.real+b.real),(a.img+b.img));
}   
public static Complex diff(Complex a,Complex b){
    return new Complex ((a.real-b.real),(a.img-b.img));
} 
public static Complex product(Complex a,Complex b){
    return new Complex(((a.real*b.real)-(a.img*b.img)),((a.real*b.real)+(a.real*b.real)));
}
public void printComplex(){
    if(real==0 && img!=0){
        System.out.println(img+"i");
    }
    else{
        System.out.println(real+"+"+img+"i");

    }
}

}
class Solution{
    public static void main(String arg[]){
        Complex c=new Complex(4,5);
        Complex d=new Complex(9,4);

        Complex e=Complex.add(c,d);
        Complex f=Complex.diff(c,d);
        Complex g=Complex.product(c,d);

        e.printComplex();
        f.printComplex();
        g.printComplex();
    }
}