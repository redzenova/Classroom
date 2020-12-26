
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
public class TestCESmartPackage {
    public static void main(String[] args) {
    //I want more++ Time!!!!
    CESmartPackage plan = new CESmartPackage("Japan with seeing sakura");
    Scanner input = new Scanner(System.in);
     
    boolean exit = false;
    int state = 0 ;
    String acName = "name";
    
    while(!exit){
            switch(state){
                case 0:
                    System.out.println("Welcome to Smart Planner [Main Menu]");
                    System.out.print("Please enter you name : ");
                    acName = input.next();
                    state = 1;
                    break;
                case 1:
                    System.out.println("Welcome to Smart Planner [Main Menu]");
                    System.out.println("1 : Choose plane Ticket");
                    System.out.println("2 : Choose hotel");
                    System.out.println("3 : Choose meal");
                    System.out.println("3 : Choose SightseeingTour");
                    System.out.println("4 : Exit");
                    System.out.print("Please enter number of menu : ");
                    state = input.nextInt();
                    break;
                case 2:
                    System.out.println("===========| Plane Ticket|=============");
                    System.out.println("1 : First Class");
                    System.out.println("2 : Business Class");
                    System.out.println("3 : Economy Class");
                    System.out.println("4 : Exit to main menu");
                    System.out.print("Please enter number of menu : ");
                    state = input.nextInt();
                    if(state == 1){
                        plan.addTiket( new AirTicket(acName,"FirstClass"));
                    }
                    else if (state == 2){
                         plan.addTiket( new AirTicket(acName,"BusinessClass"));
                    }
                    else if (state == 3){
                         plan.addTiket( new AirTicket(acName,"Econraomy Class"));
                    }
                    state = 1;
                    break;
                case 4: exit = true;
                     break;
            }
    }
    } 
}
