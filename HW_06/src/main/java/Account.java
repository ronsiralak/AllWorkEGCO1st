/*Siralak    Teekha                 6213133
  Weerawich  Wongchatchalikun       6213166
  Korawit    Wisetsuwan 	    6213192*/
public class Account {
    private int balance;
    private String previous = "";
      public Account(int b)  { balance = b; }
      synchronized public int withdraw(int money,int round)
      {          String result = "";
      
             while(previous.equals(Thread.currentThread().getName()))
                try { wait(); } catch(Exception e) { }
              
              
          if(balance>money){
              balance-=money;
              result = "current balance = " + Integer.toString(balance);
              
          }else{
          result = "failed";
          money = 0;
          } 
          
        
          System.out.printf("%s  round(%d) %s\n", Thread.currentThread().getName(),round +1,result);
          previous = Thread.currentThread().getName();
          notifyAll();
         
          return money;
      }
      public void Setbalance(int b){
      
      balance = b;
      }

}
