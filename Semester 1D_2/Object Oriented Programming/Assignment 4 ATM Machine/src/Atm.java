
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Atm {
    private String atmName;
    private ArrayList<Account> accountList = new ArrayList<Account>() ;

    public Atm() {
    }

    public Atm(String atmName) {
        this.atmName = atmName;
    }

    //Custom Medthod
    public String getAtmName() {
        return atmName;
    }

    public ArrayList getAcoountList() {
        return accountList;
    }
    
    //Balance Mangement Method
    public double checkBalance(String accountName){
        //System.out.println(accountList.get(searchAccount(accountName)).getAccountBalance());
        return accountList.get(searchAccount(accountName)).getAccountBalance();
    }
    
    public String witdraw(String accountName, double withdraw){
        if(isAccount(accountName)){
            accountList.get(searchAccount(accountName)).withdraw(withdraw);
            return "Withdraw Success!" ;
        }
        return "Not found account";
    }
    
    public String deposit(String accountName, double deposit){
        if(isAccount(accountName)){
            accountList.get(searchAccount(accountName)).deposit(deposit);
            return "Deposit Success!" ;
        }
        return "Not found account";
    }
    
    
    //Account Management Method
    public int searchAccount(String accountName) {
        for (int i = 0; i < accountList.size(); i++) {
            if(accountList.get(i).getAccountName().equals(accountName)){
                return i;
            }
        }
        return 0;
    }
    
    public boolean isAccount(String accountName){
        for (int i = 0; i < accountList.size(); i++) {
            if(accountList.get(i).getAccountName().equals(accountName)){
                return true;
            }
        }
        return false;
    }
    
    public void creatAccount(String accountName, double balance){
        accountList.add(new Account(accountName,balance));
    }
    
    public void delelteAccount(String accountName) {
        accountList.remove(searchAccount(accountName));
    }
}
