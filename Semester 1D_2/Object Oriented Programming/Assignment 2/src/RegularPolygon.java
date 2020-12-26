/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class RegularPolygon {
    private int    numberOfSide;
    private double length;
    private double area;
    private double xPos;
    private double yPos;
    
    //Constructor 
    public RegularPolygon() {
    }

    public RegularPolygon(int numberOfSide, double length) {
        this.numberOfSide = numberOfSide;
        this.length = length;
    }
    
    public RegularPolygon(int numberOfSide, double length, double xPos, double yPos) {
        this.numberOfSide = numberOfSide;
        this.length = length;
        this.xPos = xPos;
        this.yPos = yPos;
    }
    
    //Accessor and Mutator

    public int getNumberOfSide() {
        return numberOfSide;
    }

    public void setNumberOfSide(int numberOfSide) {
        this.numberOfSide = numberOfSide;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getxPos() {
        return xPos;
    }

    public void setxPos(double xPos) {
        this.xPos = xPos;
    }

    public double getyPos() {
        return yPos;
    }

    public void setyPos(double yPos) {
        this.yPos = yPos;
    }
    
    //Custom Method
    
    public double getPerimeter() {
        return this.numberOfSide * this.length ;
    }
    
    public double getArea() {
        return (this.length * this.numberOfSide * this.numberOfSide)/
                (4 * Math.tan(Math.PI/this.length));
    }
}
