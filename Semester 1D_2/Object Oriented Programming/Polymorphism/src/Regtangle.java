
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
public class Regtangle extends Geometric {
    double hight;
    double width;
    
    
    public Regtangle() {
    }

    public Regtangle(double hight, double width) {
        this.hight = hight;
        this.width = width;
    }

    public Regtangle(double hight, double width, String color, Date dateCreated) {
        super(color, dateCreated);
        this.hight = hight;
        this.width = width;
    }
 
    public void display(double w,double h){
        System.out.println("H = " + h +"W = " + w);
    }
    
    public double getPerieter(){
        return this.hight + this.hight + this.width + this.width ;
    }
}
