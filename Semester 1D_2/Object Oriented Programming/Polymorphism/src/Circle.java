
import java.util.Date;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Circle extends Geometric {
    double radius ;

    public Circle() {
    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public Circle(double radius, String color, Date dateCreated) {
        super(color, dateCreated);
        this.radius = radius;
    }
    
    public void display(double radius){
        System.out.println("Radius = " + radius);
    }
    
    public double getDiameter(){
        return this.radius + this.radius;
    }
}
