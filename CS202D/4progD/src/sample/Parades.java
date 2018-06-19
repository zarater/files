package sample;
import java.util.Scanner;
import java.io.*;

public class Parades extends Festival {
        protected Scanner file;

        //Constructor for the Parades class
    Parades(){
        root = null;
        Load();
    }

    //This function overrides the base class' Load function for Parades
    @Override
    protected void Load() {
        try{
            file = new Scanner(new File("./festive.txt"));
        }
        catch (FileNotFoundException e) {
            System.out.println("Could not find" + file + ".Please try again later");
        }
        while(file.hasNext()){
            Node temp = new Node();
            temp.setEvent(new String(file.next()));
            temp.setEvent_type(new String(file.next()));
            temp.setFlag(Integer.parseInt(file.next()));
            Build(temp);
        }
        file.close();
    }

    //This function overrides the base class' Build function for Parades
    @Override
    protected void Build(Node temp) {
        root = root.Insert(root, temp, null);
        return;
    }

    //This function overrides the base class' Display function for Parades
    @Override
    public void Display() {
        root.Display(root,1);
        return;
    }

    //This function overrides the base class' Display all function for Parades
    @Override
    void Display_all() {
        if(root == null){
            return;
        }
        root.Display_all(root);
        return;
    }

    //This function overrides the base class' Remove all function for Parades
    @Override
    int Remove_all() {
        root = root.Remove_all(root);
        return 0;
    }
}
