/*Siralak    Teekha                 6213133
  Weerawich  Wongchatchalikun       6213166
  Korawit    Wisetsuwan 	    6213192*/
import java.util.concurrent.*;
public class BankingThread extends Thread implements Comparable<BankingThread>{
    private Account account;
      private int     totalWithdraw;
      private int round = 5;
      private   CyclicBarrier cfinish;
     
      public BankingThread(String n, Account ac)  { super(n); account = ac; }

      public void run()
      {      
          for(int i =0 ; i< round ;i++)
          {  
              int money = (int)(Math.random() * 10) + 1;
              
           
             
                totalWithdraw+= account.withdraw(money,i);
          
              
             
          }
         
         //try { cfinish.await(); } catch (Exception e) { }
         //System.out.println("Summary total withdraw" + Thread.currentThread().getName()+ " = "  + totalWithdraw);
      }

    public void setroubd(int n){
    
        round  = n;
    }
    public int  compareTo(BankingThread other) {
    if(this.totalWithdraw >other.gettotal())
        return 1;
    else 
        return -1;
    }
    public int gettotal(){
    
    return totalWithdraw;
    }
    public void setBarrier(CyclicBarrier c)
    {
    cfinish = c;
    
    }

    
}
