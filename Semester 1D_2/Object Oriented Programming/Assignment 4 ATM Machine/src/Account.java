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
    private int    id = 62000;
    private String accountName;
    private double accountBalance;

    //Constructor
    public Account() {
        this.id ++;
    }

    public Account(String name, double balance) {
        this.accountName = name;
        this.accountBalance = balance;
        this.id ++;
    }

    //Accessor and mutator    
    public String getAccountName() {
        return accountName;
    }

    public void setAccountName(String accountName) {
        this.accountName = accountName;
    }

    public double getAccountBalance() {
        return accountBalance;
    }

    public void setAccountBalance(double accountBalance) {
        this.accountBalance = accountBalance;
    }
    
    //Custom method
    public void withdraw(double withdraw){
        this.accountBalance -= withdraw;
    }
    
    public void deposit(double deposit){
        this.accountBalance += deposit;
    }
}
