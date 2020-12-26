
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
public class AssignmentList {
    private ArrayList<Assignment> assignmentList = new ArrayList<>();

    public AssignmentList() {
    }
    
    public void addItem(Assignment a){
        assignmentList.add(a);
    }
    
    public double computeCourseGrade(){
        double totalWeight = 0;
        double totalPoints = 0;
        double grade = 0;
        
        for (int i = 0; i < assignmentList.size(); i++) {
            totalPoints += (assignmentList.get(i).getTotalWeight() * (assignmentList.get(i).getScore()/assignmentList.get(i).getTotalPoints()));
            totalWeight +=  assignmentList.get(i).getTotalWeight();
        }
        return totalPoints/totalWeight;
    }
    
    
    
    public void showList(){
        for (int i = 0; i < assignmentList.size(); i++) {
            System.out.println(assignmentList.get(i).toString());
        }
    }

    public ArrayList<Assignment> getAssignmentList() {
        return assignmentList;
    }
}
