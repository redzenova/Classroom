/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class CheckingAccount extends Account {
    private double fee;

    public CheckingAccount() {
    }

    
    public CheckingAccount(double fee) {
        this.fee = fee;
    }

    public CheckingAccount(int id, String name, double balance) {
        super(id, name, balance);
    }

    public double getFee() {
        return fee;
    }

    public void setFee(double fee) {
        this.fee = fee;
    }
    
    @Override
    public void withdraw(double withdraw) {
        if(withdraw <= super.getBalance()){
            super.withdraw(withdraw + this.fee);
        }
        else System.out.println("Withdraw limit, have not enough balance");
    }    
    
}

