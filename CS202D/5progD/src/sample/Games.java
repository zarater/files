package sample;
import java.util.Scanner;
import java.io.*;
public class Games extends Festival {
    protected Scanner input;

    //Constructor for the Games derived class
    Games(){
        root = null;
        Load();
    }
    //This overloads the base class' load function for Games
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

    //This function overloads the base class' Build function for Games
    @Override
    protected void Build(Node temp) {
        root = root.Insert(root, temp, null);
        return;
    }

    //This function overloads the base class' Display function for Games
    @Override
    public void Display() {
        root.Display(root,2);
        return;
    }

    //This function overloads the base class' Display all function for Games
    @Override
    void Display_all() {
        root.Display_all(root);
        return;
    }

    //This function overloads the base class' Remove all function for games
    @Override
    int Remove_all() {
        root = root.Remove_all(root);
        return 0;
    }
}
