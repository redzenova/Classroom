
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
public class Faculty {
    private String name;
    private ArrayList<Course> courseList = new ArrayList<Course>() ;

    public Faculty() {
    }

    public Faculty(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public ArrayList getCourseList() {
        return courseList;
    }

    //Course Management Method
    public void addCourse(Course addCourse) {
        courseList.add(addCourse);
    }
    
    public void delCourse(Course delCourse) {
        courseList.add(delCourse);
    }
    
    public int numCourse(){
        return courseList.size();
    }
}
