package sample;

public class Node {
    protected String event[];
    protected String event_type;
    protected int flag;
    protected int size;
    protected int highest;
    protected Node next;

    //Constructor for the node class
    Node(){
        event_type = new String();
        flag = 0;
        size = 0;
        next = null;
    }

    //Constructor for the node class that takes a node object as an argument
    Node(Node temp){
        this.event = temp.event;
        this.event_type = temp.event_type;
        this.flag = temp.flag;
    }

    //This function is a setter for event type
    public void setEvent_type(String event_type) {
        this.event_type = event_type;
    }

    public void setEvent(String event) {
        this.event[0] = event;
    }

    public void Make_Event_Size(int x){
        this.size += x;
        this.event = new String[this.size];
        return;
    }

    //This function inserts a new node object at head
    public Node Insert(Node head, Node temp){
        if(head == null){
            head = temp;
            return head;
        }
        else {
            if(head.highest >= head.size){
                return head;
            }
            else{
                head.event[head.highest + 1] = temp.event[0];
                head.highest += 1;
                return head;
            }
        }
    }

    //This function is a setter for flag
    public void setFlag(int flag) {
        this.flag = flag;
    }

    //This function displays everything in a linear linked list
    public void Display(Node head, int x){
        if(head == null){
            return;
        }
        else{
            System.out.println("Event: " + head.event[x] + "from the " + event_type);
            Display(head.next, ++x);
            return;
        }
    }
}
