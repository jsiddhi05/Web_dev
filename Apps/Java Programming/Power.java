class Power{
    public static int optimizedPower(int a,int n){
        if(n==0){
            return -1;
        }
        int halfPower= optimizedPower(a,n/2);
        int halfPowerSq= halfPower*halfPower;

        //n odd
        if(n%2!=0){
            halfPower=a *halfPowerSq;
        }
        return halfPower;

    public static void main(String arg[]){
        int a=2;
        int n=5;
        System.out.println(optimizedPower(a,n));
    }    
    }
}