/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Apple extends Fruit{
    public static void main(String[] args) {
        Apple apple = new Apple();
        
        Fruit[] fruit = {new Apple(), new Lemon()} ;
        
        for (int i = 0; i < fruit.length; i++) {
            System.out.println(fruit[i].howToEat());
        }
    }

    Apple(){
        super("Apple");
    }
    
    String howToEat(){
        return "666";
    }
    
}

class Lemon extends Fruit{
    String howToEat(){
        return "444";
    }
}


class Fruit {
    Fruit(){
        
    }
    
    Fruit(String s) {
        System.out.println(s);
    }
    
    String howToEat(){
        return "555";
    }
}