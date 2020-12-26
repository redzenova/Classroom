
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
public class TestProgram {
    public static void main(String[] args) {
        //Supertype          //Subtype
        Geometric obj1 = new Circle();  // polymorphism
        Geometric obj2 = new Regtangle();
        
//        Circle c1 = new Circle();
//        
//        //Check matching of method [display]
//        c1.display(5.3);
//        //c1.display(2.5, 6.3);
//        obj1.display(5.3);  //Invoke itself         | Dynamic binding
//        obj2.display(5.3);  //Invoke via superclass | Dynamic binding

        ArrayList<Geometric> geoList = new ArrayList<>();
        geoList.add(new Geometric());
        geoList.add(obj1);
        geoList.add(obj2);
        
        for (int i = 0; i < geoList.size(); i++) {
            if(geoList.get(i) instanceof Circle){
                System.out.println("Raius is "+((Circle)geoList.get(i)).getDiameter());
            }
            else if(geoList.get(i) instanceof Regtangle){
                System.out.println("Perimeter is "+ ((Regtangle)geoList.get(i)).getPerieter());
            }
            else{
                continue;
            }
            
        }
 
    }
}
