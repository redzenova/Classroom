/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class Driver {
    public static void main(String[] args) {
       AssignmentList a = new AssignmentList(); 
        
       Assignment assign1 = new Assignment("Polymorphism Unit",12,1,23,0);
       Assignment lab1 = new Lab(" ","Lab-Polymorilism",12,1,23,0);
       Assignment project1 = new Project(" ","poly","Project-Polymorilism",12,1,23,0);
       
       assign1.setScore(0.78);
       assign1.setTotalPoints(0.99);
       assign1.setTotalWeight(0.30);
       
       lab1.setScore(0.78);
       lab1.setTotalPoints(0.99);
       lab1.setTotalWeight(0.30);
       
       project1.setScore(0.78);
       project1.setTotalPoints(0.99);
       project1.setTotalWeight(0.30);
       
       a.addItem(assign1);
       a.addItem(lab1);
       a.addItem(project1);
       
       System.out.println("Grade = " + a.computeCourseGrade());
       a.showList();
    }
}
