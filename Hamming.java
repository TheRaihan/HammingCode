
package hamming2;

import java.util.Scanner;

public class Hamming2 {


    public static void main(String[] args) {
        // TODO code application logic here
    }
    
}

class Sender{
    String msg;
    int size;
    char parity;
    
    public int getCodeWordSize()
    {
//        Sender x = new Sender();

        
        return size;
    }
    
    public void setMsg()
    {
        Scanner myObj = new Scanner(Systen.in);
        System.out.print("Enter Message: ");

        msg = myObj.nextInt();
        System.out.println("Username is: " + msg);

    }
    
    public void setParity(char parity)
    {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Parity Type (E/O): ");

        parity = myObj.nextByte();
        System.out.println("Parity type : "+ parity);
    }


    public String CodeWord(){
        String x = "dsad";
        return x;
    }
    
}

class Receiver{
    int size;
    char parity;
    
    public int setCodeWordSize()
    {
//        Sender x = new Sender();
        
        return size;
    }
    
}
