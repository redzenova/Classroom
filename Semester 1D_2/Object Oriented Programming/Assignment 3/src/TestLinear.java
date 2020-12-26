/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class TestLinear {
    public static void main(String[] args) {
        LinearEquation eq1 = new LinearEquation(3.4, 50.2, 2.1, 0.55, 44.5, 5.9);
        
        System.out.println("X : " + eq1.getX());
        System.out.println("Y : " + eq1.getY());

    }
}
