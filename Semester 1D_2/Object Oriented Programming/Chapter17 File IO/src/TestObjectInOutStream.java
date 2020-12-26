
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
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
public class TestObjectInOutStream {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
        ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("binary4.dat"));
        out.writeUTF("Rawee");
        out.writeChar('F');
        out.writeObject(new Date());
        out.close();
        System.out.println("Finish writing object");
        
        System.out.println("Start writing object");
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("binary4.dat"));
        System.out.println("Name  : " + in.readUTF());
        System.out.println("Gender : " + in.readChar());
        System.out.println("date  : " + in.readObject());
        System.out.println("Finish reading file");
        
    }
}
