
import java.util.*;
import java.util.Date;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Account {
    private int    id;
    private String name;
    private double balance;
    private double annualInterestRate;
    
    private ArrayList<Transaction> transaction = new ArrayList<Transaction>() ;
    
    private Date   dataCreated;

    /*==== Connsturctor ====*/
    public Account() {
        this.dataCreated = new Date();
    }

    public Account(int id, String name, double balance) {
        this.id = id;
        this.name = name;
        this.balance = balance;
        this.dataCreated = new Date();
    }
    
    /*==== Accessor And Mutator ====*/

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

        public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    
    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate / 100;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    public Date getDataCreated() {
        return dataCreated;
    }
    
    public ArrayList<Transaction> getTransaction() {
        return transaction;
    }

    public void setTransaction(ArrayList<Transaction> transaction) {
        this.transaction = transaction;
    }
    
    /*==== Custom Method ====*/
    
    public double getMonthlyInterestRate(){
        return this.annualInterestRate /12 /100 ;
    }
    
    public double getMounthkyInterest() {
        return this.balance * this.getMonthlyInterestRate() ;
    }
    
    public void withdraw(double withdraw) {      
            this.transaction.add(new Transaction('w',withdraw,this.balance -= withdraw));
            System.out.println("Withdraw " + withdraw + " Success!");            
    }
    
    public void deposit(double deposit) {
        this.transaction.add(new Transaction('d',deposit,this.balance += deposit));
        System.out.println("Deposit " + deposit + " Success!");
    }
    
    public void showTransaction(Account a){
        for (int i = 0; i < a.getTransaction().size(); i++) {
            System.out.println("["+ (i+1) + "] " + a.getTransaction().get(i).toString()); 
        }
    }
}
