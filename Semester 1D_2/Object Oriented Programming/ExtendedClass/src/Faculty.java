/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Faculty extends Employee{
//    public static void main(String[] args) {
//        new Faculty(); //anonymous object
//    }

    public Faculty() {
        super(); //hidden automatically invoke
        System.out.println("4. Faculty constructor invoked");
    }
        
}

class Employee extends Person {

    public Employee() {
        this("2. Employee constructor invoke");
        System.out.println("3. Employee no-arg constructor invoked");
    }
    
    public Employee(String s){
        super();
        System.out.println(s);
    } 
}

class Person extends Object { //Class Object is upperest of class
    public Person() {
        //super();
        System.out.println("1. Person constructor invoked!");
    }
    
}

