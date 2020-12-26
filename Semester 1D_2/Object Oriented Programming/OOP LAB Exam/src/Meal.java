/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Meal {
    private String naeme;
    private String foodType;
    private String location;
    private double price;

    //Constructor
    public Meal() {
    }

    public Meal(String foodType, double price) {
        this.foodType = foodType;
        this.price = price;
    }

    //Accessor and Mutator
    public String getFoodType() {
        return foodType;
    }

    public void setFoodType(String foodType) {
        this.foodType = foodType;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }


    
    
}
