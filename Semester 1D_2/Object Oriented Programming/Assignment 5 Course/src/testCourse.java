/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class testCourse {
    public static void main(String[] args) {
        //Test Consturtor
        Course course = new Course("calculus 1");
        Course course2 = new Course("calculus 2");
        
        //Test add student
        course.addStudent(new Student("A"));
        course.addStudent(new Student("B"));
        course.addStudent(new Student("C"));
        
        course2.addStudent(new Student("A"));
        
        //Test add faculty
        course.addFaculty(new Faculty("Somsak"));
        
        //Test Displayed
        System.out.println("Course name : " + course.getCourseName());
        System.out.println("In Course have a " + course.getFacultyList().size() + " Faculty");
        for (int i = 0; i < course.getFacultyList().size(); i++) {
            System.out.println(course.getFacultyList().get(i).getName());
        }
        
        System.out.println("In Course have a " + course.getStudentList().size() + " Student");
        for (int i = 0; i < course.getStudentList().size(); i++) {
            System.out.println(course.getStudentList().get(i).getName());
        }
        
        System.out.println("Student A have a " + course.getStudentList().get(0).getCourseList().size() + " Course");
        
        //Test drop student
        System.out.println("Drop student A");
        course.dropStudent("A");
        System.out.println("In Course have a " + course.getStudentList().size() + " Student");
        for (int i = 0; i < course.getStudentList().size(); i++) {
            System.out.println(course.getStudentList().get(i).getName());
        }
        
    }
}
