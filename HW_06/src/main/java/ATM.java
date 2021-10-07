
/*Siralak    Teekha                 6213133
  Weerawich  Wongchatchalikun       6213166
  Korawit    Wisetsuwan 	    6213192*/
import java.io.*;
import java.util.*;
import java.util.concurrent.*;
public class ATM {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList<BankingThread> Bank = new ArrayList<BankingThread>();
        String  check = "";
        Scanner input = new Scanner(System.in);
        
        System.out.println("Number of Thread  ");  int numberThread=input.nextInt();  
        System.out.println("Initial balance "); int Initial_balance  = input.nextInt();
        Account Ac = new Account(Initial_balance);
        do
        {
        
        Create(Bank,numberThread ,Initial_balance,Ac); 
       
        Ac.Setbalance(Initial_balance);
        
        RUNThread(Bank,numberThread);
       
        try{
        for(int i = 0 ;i<numberThread;i++){
            
            Bank.get(i).join();
        }
        }catch(InterruptedException e){}
        
        
        Collections.sort(Bank);
        System.out.println("Summary");
        
        for(int i = 0 ;i<numberThread;i++){
          
          System.out.println(Bank.get(i).getName() + " total Withdraw  = "  + Bank.get(i).gettotal());  
        }
        
        System.out.println("Another Run ? (y/n) ? ");
        check=  input.next();
        Bank.clear();
        }while(check.equals("y"));
        /*System.out.println("Another Run ? (y/n) ? ");
        check =  input.nextLine();*/
        
        //System.out.println("KUy");
    }
    public static void Create(ArrayList<BankingThread> ct,int NT,int NB,Account Ac)
    {
        CyclicBarrier finish = new CyclicBarrier(NT);
     
        for(int i = 0 ;i<NT;i++){
            BankingThread  T = new BankingThread("T"+Integer.toString(i+1),Ac);
            ct.add(T);
            ct.get(i).setBarrier(finish);
        }
        
        
    
    }
    public static void RUNThread(ArrayList<BankingThread> Bank ,int NT)
    {
        for(int i = 0 ;i<NT;i++){
          
            Bank.get(i).start();
        }
    
    }
    
}
