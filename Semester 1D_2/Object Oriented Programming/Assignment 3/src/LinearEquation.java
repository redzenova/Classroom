/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class LinearEquation {
    private double a;
    private double b;
    private double c;
    private double d;
    private double e;
    private double f;
    private double x;
    private double y;
    
    //Constructor

    public LinearEquation() {
    }

    public LinearEquation(double a, double b, double c, double d, double e, double f) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
    }
    
    //Accessor

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public double getC() {
        return c;
    }

    public double getD() {
        return d;
    }

    public double getE() {
        return e;
    }

    public double getF() {
        return f;
    }
    
    public void setA(double a) {
        this.a = a;
    }

    public void setB(double b) {
        this.b = b;
    }

    public void setC(double c) {
        this.c = c;
    }

    public void setD(double d) {
        this.d = d;
    }

    public void setE(double e) {
        this.e = e;
    }

    public void setF(double f) {
        this.f = f;
    }
    
    //Custom method
    
    public boolean isSolvable() {
        if((this.a*this.d - this.b*this.c) > 0 )
            return true;
        else {
            System.out.println("The equation has no solution.");
            return false;
        }
    }
    
    public double getX(){
        return ((this.e*this.d)-(this.b*this.f))/((this.a*this.d - this.b*this.c)) ;
    }
    
    public double getY(){
        return ((this.a*this.f)-(this.e*this.c))/((this.a*this.d - this.b*this.c)) ;
    }
}
