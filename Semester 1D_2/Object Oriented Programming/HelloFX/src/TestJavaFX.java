
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Redzer0
 */
public class TestJavaFX extends Application {

    @Override
    public void start(Stage stage) throws Exception {
       Button btOK = new Button("OK");
       Scene scene = new Scene(btOK, 250, 200);
       stage.setTitle("MyJavaFX");
       stage.setScene(scene);
       stage.show();
    }
    
    public static void main(String[] args) {
        launch(args);
    }
}
