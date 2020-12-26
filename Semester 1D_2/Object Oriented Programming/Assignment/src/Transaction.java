
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
public class Transaction {
    private char type;
    private double amount;
    private double balance;
    private String description;
    private Date date;

    public Transaction() {
        this.date = new Date();
    }

    public Transaction(char type, double amount, double balance) {
        this.type = type;
        this.amount = amount;
        this.balance = balance;
        this.date = new Date();
    }

    public char getType() {
        return type;
    }

    public void setType(char type) {
        this.type = type;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    @Override
    public String toString() {
        return "type=" + type + ", amount= " + amount + ", balance= " + balance + ", description= " + description + ", date:" + date + '}';
    }
    
    
    
}
