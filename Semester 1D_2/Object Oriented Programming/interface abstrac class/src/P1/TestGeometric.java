/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package P1;

import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 *
 * @author Redzer0
 */
public class TestGeometric {
    public static void main(String[] args){
        //Geometric g = new Geometric(); //Can not created object with Abstract class
        //Geometric g; //g is a variable on a type Geometric 
        Calendar c = new GregorianCalendar();
        
        Geometric circle1 = new Circle(2);
        Geometric circle2 = new Circle(5);
        Geometric regtangle1 = new Rectangle(5,6);
        Geometric regtangle2 = new Rectangle(5,6);
            
        System.out.println(Geometric.max(circle1, circle2));
        System.out.println(Geometric.max(regtangle1,regtangle2));
        System.out.println(Geometric.max(circle1,regtangle2));
        
        System.out.println(circle1.HowToColor());
        System.out.println(regtangle1.HowToColor());
        System.out.println();
    }
}
