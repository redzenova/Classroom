/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class TestPolygon {
    public static void main(String[] args) {
        RegularPolygon sq1 = new RegularPolygon();
        RegularPolygon sq2 = new RegularPolygon(6, 4);
        RegularPolygon sq3 = new RegularPolygon(10, 74, 5.6, 7.8);
        
        System.out.println("Perimeter : " + sq2.getPerimeter());
        System.out.printf("Area : %.2f \n" , sq2.getArea());
    }
}
