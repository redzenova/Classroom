/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package P1;

import java.util.Date;

/**
 *
 * @author Redzer0
 */
public abstract class Geometric implements Comparable<Geometric>,colorable {
    double area;
    String color;
    Date dateCreated;

    //Chenge constructor form public to protected
    protected  Geometric() {
    }

    protected  Geometric(String color) {
        this.color = color;
    }
    
    //Abstract method defined
    abstract double getArea();
    abstract double getPerimeter();
    
    public static String max(Geometric x, Geometric y){
        if(x.compareTo(y)== +1) return "X > Y";
        else if (x.compareTo(y)==-1) return "X < Y";
        else return "X = Y";
    }

    @Override
    public int compareTo(Geometric o) {
        if(getArea() > o.getArea()) return +1;
        else if (getArea() < o.getArea()) return -1;
        else return 0;
    }

    @Override
    public String HowToColor() {
        return "===";
    }
    
    
}

//================= Sub-Class ====================
class Circle extends Geometric {
    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public Circle(double radius, String color) {
        super(color);
        this.radius = radius;
    }
    
    @Override
    double getArea() {
        return Math.PI * radius * radius ; 
    }

    @Override
    double getPerimeter() {
        return 2 * Math.PI * radius ;
    }

    @Override
    public String HowToColor() {
        return "Circle make color";
    }

    

}

class Rectangle extends Geometric {
    double width;
    double hight;

    public Rectangle(double width, double hight) {
        this.width = width;
        this.hight = hight;
    }

    public Rectangle(double width, double hight, String color) {
        super(color);
        this.width = width;
        this.hight = hight;
    }
        
    @Override
    double getArea() {
        return width * hight;
    }

    @Override
    double getPerimeter() {
        return 2 * (width + hight);    
    }
    
    @Override
    public String HowToColor() {
        return "Rectangle make color";
    }
}
