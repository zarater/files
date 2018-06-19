package sample;

public abstract class Festival {
    protected Tree root;

    //Load is suppose to read in from a text file and passes the data to Build
    abstract void Load();

    //Build takes a Node object and uses it to fill in the tree
    abstract void Build(Node to_copy);

    //Display is a wrapper function to Display a certain list type
    abstract void Display();

    //Display all displays everything in the tree
    abstract void Display_all();

    //Remove all destroys the entire tree
    abstract int Remove_all();
}
