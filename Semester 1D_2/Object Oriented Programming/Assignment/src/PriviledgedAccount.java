/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class PriviledgedAccount extends Account {
    private double drawLimit ;

    public PriviledgedAccount() {
    }

    public PriviledgedAccount(double drawLimit) {
        this.drawLimit = drawLimit;
    }

    public PriviledgedAccount(double drawLimit, int id, String name, double balance) {
        super(id, name, balance);
        this.drawLimit = drawLimit;
    }

    @Override
    public void withdraw(double withdraw) {
        if(withdraw <= super.getBalance() + this.drawLimit){
            super.withdraw(withdraw);
        }
        else if (withdraw > super.getBalance() + this.drawLimit) {
            System.out.println("Withdraw limit, have not enough balance"); 
        };
    }
   
    
    
}
