
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class TestAtm {
    public static void main(String[] args) {
        Atm atm = new Atm();
        Scanner input = new Scanner(System.in);
        
        boolean exit = false;
        double newBalance = 0;
        double withdraw =0;
        double deposit =0;
        int state = 0;
        String acName = "name";
        
        while(!exit){
            switch(state){
                case 0:
                    System.out.println("Welcome");
                    System.out.println("1 : Have an account");
                    System.out.println("2 : Create account");
                    System.out.println("3 : Exit");
                    System.out.print("Please enter number of menu : ");
                    state = input.nextInt();
                    break;
                case 1:
                    System.out.print("Enter account name : ");
                    acName = input.next();
                    System.out.println(acName);
                    if(atm.isAccount(acName))
                        state = 4;
                    else {
                        System.out.println("Not found account");
                        state = 0;
                    }
                    break;
                case 2:
                    System.out.print("Enter new account name : ");
                    acName = input.next();
                    System.out.print("Enter new balance : ");
                    newBalance = input.nextDouble();
                    if(!atm.isAccount(acName)){
                        atm.creatAccount(acName, newBalance);
                        state =0;
                    }
                    break;
                case 3:
                    exit = true;
                    break;
                case 4:
                    System.out.println("1 : check balance");
                    System.out.println("2 : withdraw");
                    System.out.println("3 : deposit");
                    System.out.println("4 : exit to main menu");
                    System.out.print("Enter number of menu : ");
                    state = input.nextInt();
                    if(state == 4){
                        state = 0;
                    }
                    else{
                        state += 5;
                    }
                    break;
                case 6:
                    System.out.println(acName + " balance is : " + atm.checkBalance(acName));
                    state = 4;
                    break;
                case 7:
                    System.out.print("Enter money you want to withdraw : ");
                    withdraw = input.nextInt();
                    atm.witdraw(acName, withdraw);
                    state = 4;
                    break;        
                case 8:
                    System.out.print("Enter money you want to deposit : ");
                    deposit = input.nextInt();
                    atm.deposit(acName, deposit);
                    state = 4;
                    break;               
            }
        }
    }
}
