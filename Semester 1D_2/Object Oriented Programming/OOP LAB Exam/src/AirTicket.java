
import java.util.Date;
import java.util.Random;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class AirTicket {
    private String name;
    private String passengerName;
    private String seatClass;
    private Date dateCreated;
    private Random rand =  new Random();

    //Constructor
    public AirTicket() {
        this.dateCreated = new Date();
    }

    public AirTicket(String name) {
        this.name = name;
        this.dateCreated = new Date();
    }

    public AirTicket(String passengerName, String seatClass) {
        this.passengerName = passengerName;
        this.seatClass = seatClass;
        this.dateCreated = new Date();
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

    public String getSeatClass() {
        return seatClass;
    }

    public void setSeatClass(String seatClass) {
        this.seatClass = seatClass;
    }

    
    //Custom Method
    public double getPrice(double ratio){
        return ratio * 3000.0 + (rand.nextDouble()*1000);
    }
    
}
