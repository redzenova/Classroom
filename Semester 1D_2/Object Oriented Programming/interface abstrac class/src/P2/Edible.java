/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package P2;

/**
 *
 * @author Redzer0
 */
public interface Edible {
    String HowToEat();
}
abstract class Fruit implements Edible {
    
}

class Orange extends Fruit {

    @Override
    public String HowToEat() {
        return "make orange juice";
    }
    
}

class Apple extends Fruit {

    @Override
    public String HowToEat() {
        return "eat now";
    }
}

class Chicken extends Fruit{

    @Override
    public String HowToEat() {
        return "go to KFC" ; 
    }
}

abstract class Animal {
    abstract String sound();
}

class Tiger extends Animal {

    @Override
    String sound() {
        return "Hho Cho Hho" ;
    }
    
}