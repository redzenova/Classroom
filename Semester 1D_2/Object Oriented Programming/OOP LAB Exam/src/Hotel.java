/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Hotel {
    private String name;
    private String passengerName;
    private String roomNumber;
    private String roomClass;
    private double price;

    //Constructor
    public Hotel() {
    }

    public Hotel(String name) {
        this.name = name;
    }

    public Hotel(String name, String passengerName, String roomNumber, String roomClass) {
        this.name = name;
        this.passengerName = passengerName;
        this.roomNumber = roomNumber;
        this.roomClass = roomClass;
    }

    
    //Accessor and Mutator
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassengerName() {
        return passengerName;
    }

    public void setPassengerName(String passengerName) {
        this.passengerName = passengerName;
    }

    public String getRoomNumber() {
        return roomNumber;
    }

    public void setRoomNumber(String roomNumber) {
        this.roomNumber = roomNumber;
    }

    public String getRoomClass() {
        return roomClass;
    }

    public void setRoomClass(String roomClass) {
        this.roomClass = roomClass;
    }
    
    
    //Custom Method

    public void setPrice(double price) {
        this.price = price;
    }
    
}
