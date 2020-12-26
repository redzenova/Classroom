/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Assignment {
    private String name;
    private int mounth;
    private int day;
    private int hour;
    private int minute;
    private double score;
    private double totalPoints;
    private double totalWeight;

    public Assignment(String name, int mounth, int day, int hour, int minute) {
        this.name = name;
        this.mounth = mounth;
        this.day = day;
        this.hour = hour;
        this.minute = minute;
    }

    public String getName() {
        return name;
    }

    public int getMounth() {
        return mounth;
    }

    public int getDay() {
        return day;
    }

    public int getHour() {
        return hour;
    }

    public int getMinute() {
        return minute;
    }

    public double getScore() {
        return score;
    }

    public double getTotalPoints() {
        return totalPoints;
    }

    public double getTotalWeight() {
        return totalWeight;
    }

    public void setScore(double score) {
        this.score = score;
    }

    public void setTotalPoints(double totalPoints) {
        this.totalPoints = totalPoints;
    }

    public void setTotalWeight(double totalWeight) {
        this.totalWeight = totalWeight;
    }

    @Override
    public String toString() {
        return name + "(" + "date: " + mounth + "-" + day + " at " + hour + ":" + minute + ": score = " + score + "; totalPoints = " + totalPoints + "; totalWeight = " + totalWeight;
    }
    
    
}
