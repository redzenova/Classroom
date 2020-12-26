
import java.util.ArrayList;



/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class CESmartPackage {
    private String packageName;
    private ArrayList<AirTicket> airTicketList = new ArrayList<>();
    private ArrayList<Hotel> hotelList = new ArrayList<Hotel>();
    private ArrayList<Meal> mealList = new ArrayList<Meal>();
    private ArrayList<SightseeingTour> tourList = new ArrayList<SightseeingTour>();

    //Constructor
    public CESmartPackage(String packageName) {
        this.packageName = packageName;
    }

    //Getter
    public String getPackageName() {
        return packageName;
    }

    public ArrayList<AirTicket> getAirTicketList() {
        return airTicketList;
    }

    public ArrayList<Hotel> getHotelList() {
        return hotelList;
    }

    public ArrayList<Meal> getMealList() {
        return mealList;
    }

    public ArrayList<SightseeingTour> getTourList() {
        return tourList;
    }
    
    //Method
    public void addTiket(AirTicket airTicket){
        airTicketList.add(airTicket);
    }
    
    public void addMeal(Meal meal){
        mealList.add(meal);
    }
    
    public void addHotel(Hotel hotel){
        hotelList.add(hotel);
    }
    
    public void addTour(SightseeingTour tour){
        tourList.add(tour);
    }
    
}
