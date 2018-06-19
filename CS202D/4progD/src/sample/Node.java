package sample;

public class Node {
    protected String event;
    protected String event_type;
    protected int flag;
    protected Node next;

    //Constructor for the node class
    Node(){
        event = new String();
        event_type = new String();
        flag = 0;
        next = null;
    }

    //Constructor for the node class that takes a node object as an argument
    Node(Node temp){
        this.event = temp.event;
        this.event_type = temp.event_type;
        this.flag = temp.flag;
    }

    //This function is a getter for event
    public String getEvent() {
        return event;
    }

    //This function is a getter for event type
    public String getEvent_type() {
        return event_type;
    }

    //This function is a setter for event
    public void setEvent(String event) {
        this.event = event;
    }

    //This function is a setter for event type
    public void setEvent_type(String event_type) {
        this.event_type = event_type;
    }

    //This function is a getter for next
    public Node getNext() {
        return next;
    }

    //This function inserts a new node object at head
    public Node Insert(Node head, Node temp){
        if(head == null){
            head = temp;
            return head;
        }
        else {
            temp.next = head;
            head = temp;
            return head;
        }
    }

    //This function is a setter for flag
    public void setFlag(int flag) {
        this.flag = flag;
    }

    //This function displays everything in a linear linked list
    public void Display(Node head){
        if(head == null){
            return;
        }
        else{
            System.out.println("Event: " + head.event + "from the " + event_type);
            Display(head.next);
            return;
        }
    }
}
