
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
public class Rectangle extends Geometic {
    private double hight;
    private double width;

    public Rectangle() {
    }

    public Rectangle(double hight, double width) {
        this.hight = hight;
        this.width = width;
    }

    public Rectangle(double hight, double width, String color, boolean isFilled, Date dateCreated) {
        super(color, isFilled, dateCreated);
        this.hight = hight;
        this.width = width;
    }

    public double getHight() {
        return hight;
    }

    public void setHight(double hight) {
        this.hight = hight;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }
    
    
    public String printRectangle(){
        String s = " ";
        s += "Width = " + getWidth() + "Hight = " + getHight() + super.toString() ;
        return s;
    }
}
