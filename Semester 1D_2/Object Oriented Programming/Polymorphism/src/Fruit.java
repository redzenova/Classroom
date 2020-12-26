/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Fruit {
    public static void main(String[] args) {
        int fProp;
        
        Object fruit = new Fruit(); //Supertype
        Apple a1 = new Apple();
        Orange o1 = new Orange();
        Apple a2 = (Apple)fruit;
        
        Object f2 = new Apple();
        
    }
}

class Apple extends Fruit{
    int aProp1;
    int aProp2;
}

class Orange extends Fruit{
    
}