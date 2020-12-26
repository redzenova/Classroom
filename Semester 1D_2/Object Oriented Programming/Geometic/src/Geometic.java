
import java.util.Date;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Geometic {
    private String color;
    private boolean isFilled;
    private Date dateCreated;

    public Geometic() {
        dateCreated = new Date();
    }

    public Geometic(String color, boolean isFilled, Date dateCreated) {
        this.color = color;
        this.isFilled = isFilled;
        dateCreated = new Date();
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isIsFilled() {
        return isFilled;
    }

    public void setIsFilled(boolean isFilled) {
        this.isFilled = isFilled;
    }

    public Date getDateCreated() {
        return dateCreated;
    }

    public void setDateCreated(Date dateCreated) {
        this.dateCreated = dateCreated;
    }

    @Override
    public String toString() {
        return " Geometic{" + "color:" + color + ", isFilled:" + isFilled + ", dateCreated:" + dateCreated + '}';
    }
    
    
}
