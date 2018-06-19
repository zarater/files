package sample;
import java.util.Scanner;
import java.io.*;
public class Music extends Festival {
    protected Scanner input;

    //Constructor for the music class
    Music(){
        root = null;
        Load();
    }

    //This function overrides the base class' Load function for Music
    @Override
    protected void Load() {
        try{
            input = new Scanner(new File("festive.txt"));
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        while(input.hasNext()){
            Node temp = new Node();
            temp.setEvent(new String(input.next()));
            temp.setEvent_type(new String(input.next()));
            temp.setFlag(Integer.parseInt(new String(input.next())));
            Build(temp);
        }
    }

    //This function overrides the base class' Build function for Music
    @Override
    protected void Build(Node temp) {
        root = root.Insert(root, temp, null);
        return;
    }

    //This function overrides the base class' Display fucntion for Music
    @Override
    public void Display() {
        root.Display(root,3);
        return;
    }

    //This function overrides the base class' Display all function for Music
    @Override
    void Display_all() {
        root.Display_all(root);
        return;
    }

    //This function overrides the base class' Remove all function for Music
    @Override
    int Remove_all() {
        root = root.Remove_all(root);
        return 0;
    }
}
