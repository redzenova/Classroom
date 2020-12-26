
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
public class Course {
    private String courseName;
    private ArrayList<Student> studentList = new ArrayList<Student>();
    private ArrayList<Faculty> facultyList = new ArrayList<Faculty>();

    
    public Course(String courseName) {
        this.courseName = courseName;
    }

    public String getCourseName() {
        return courseName;
    }

    public ArrayList<Student> getStudentList() {
        return studentList;
    }

    public ArrayList<Faculty> getFacultyList() {
        return facultyList;
    }

    //Student Management Method
    public void addStudent(Student student){
        studentList.add(student);
        student.addCourse(this);
    }
    
    public int searchStudent(String name){
        for (int i = 0; i < studentList.size(); i++) {
            if(studentList.get(i).getName().equals(name)){
                return i;
            }
        }
        return 0;
    }
    
    public void dropStudent(String name){
        studentList.get(searchStudent(name)).delCourse(this);
        studentList.remove(searchStudent(name));
    }
    
    public int numberOfStudent(){
        return studentList.size();
    }
    
    //Faculty Management Method
    
    public void addFaculty(Faculty faculty){
        facultyList.add(faculty);
    }
    
    public int searchFaculty(String name){
        for (int i = 0; i < facultyList.size(); i++) {
            if(facultyList.get(i).getName().equals(name)){
                return i;
            }
        }
        return 0;
    }
    
    public void delFaculty(String name){
        facultyList.remove(searchFaculty(name));
    }
}
