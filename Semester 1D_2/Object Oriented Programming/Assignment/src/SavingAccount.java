/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class SavingAccount extends Account{

    public SavingAccount() {
    }

    public SavingAccount(int id, String name, double balance) {
        super(id, name, balance);
    }

    @Override
    public void withdraw(double withdraw) {
        if(withdraw <= super.getBalance()){
            super.withdraw(withdraw);
        }
        else System.out.println("Withdraw limit, have not enough balance");
    }
    
    
}
