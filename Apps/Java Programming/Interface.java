public class Interface{
    public static void main(String args[]){
        Queen q=new Queen();
        q.moves();  

    }
}
interface Chessplayers{  //blue print
    void moves();
}
class Queen{
    void moves(){
        System.out.println("up ,down,diagonal left -right");
    }
}
class Rook{
    void moves(){
        System.out.println("up ,down,left -right");

    }
}
class King{
    void moves(){
    System.out.println("up ,down,left ,right - 1 step");
    }
}