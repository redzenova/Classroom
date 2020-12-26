/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class TestAccount {
    public static void main(String[] args) {
        Account a1 = new Account(1122, "George", 1000);
       
        
        a1.setAnnualInterestRate(1.5);
        a1.deposit(30);
        a1.deposit(40);
        a1.deposit(50);
        a1.withdraw(5);
        a1.withdraw(4);
        a1.withdraw(2);        
        System.out.println("============ Account Summery ===============");
        System.out.println("Account name : " + a1.getName());
        System.out.println("Account balance : " + a1.getBalance() );
        System.out.println("Annual interest rate per mounth : " + a1.getMounthkyInterest());
        System.out.println("Created : " + a1.getDataCreated());
        System.out.println("=============== Transaction ================");
        a1.showTransaction(a1);
        
        PriviledgedAccount pA = new PriviledgedAccount(200,1122, "George", 0);
        pA.deposit(200);
        pA.withdraw(100);
        pA.withdraw(500);
        System.out.println("pA balance : " + pA.getBalance());
        pA.showTransaction(pA);
        
        CheckingAccount cA = new CheckingAccount(1122, "George", 1000);
        cA.setFee(20);
        cA.withdraw(100);
        cA.withdraw(500);
        cA.withdraw(500);
        System.out.println("cA balance : " + cA.getBalance());
        cA.showTransaction(cA);
        
        
        SavingAccount sA = new SavingAccount(1122, "George", 1000);
        sA.withdraw(600);
        sA.withdraw(600);
        System.out.println("cA balance : " + sA.getBalance());
        cA.showTransaction(sA);
    }
}
