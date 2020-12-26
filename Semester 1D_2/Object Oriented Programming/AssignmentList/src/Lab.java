/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Lab extends Assignment{
    private String specification;

    public Lab(String specification, String name, int mounth, int day, int hour, int minute) {
        super(name, mounth, day, hour, minute);
        this.specification = specification;
    }

    @Override
    public String toString() {
        return   super.getName() + "(" + "date: " + super.getMounth() + "-" + super.getDay() + " at " + super.getHour() + ":" + super.getMinute() 
                + ": score = " + super.getScore() + "; totalPoints = " + super.getTotalPoints() + "; totalWeight = " + super.getTotalWeight()
                + "specification = " + super.getName() +".pdf";
    }
    
    
}
