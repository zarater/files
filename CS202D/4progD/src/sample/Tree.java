package sample;

public class Tree {
    protected Node head[];
    protected Tree left;
    protected Tree middle;
    protected Tree right;

    //Constructor for the tree class
    Tree(){
        head = new Node[2];
        head[1] = null;
        head[0] = null;
        left = null;
        middle = null;
        right = null;
    }

    //This function recursively inserts a 2-3 tree. I know. Its a lot.
    public Tree Insert(Tree root, Node to_copy, Tree parent){
        if(root == null){
            root = new Tree();
        }
        //This checks if left and right don't exist. Thus the start of the list
        if(root.left == null && root.right == null) {
            if (root.head[0] == null) {
                root.head[0].Insert(root.head[0], to_copy);
                return root;
            }
            if (root.head[0] != null && root.head[1] == null) {
                root.head[1].Insert(root.head[1], to_copy);
                return root;
            }
        }
        //This checks if left and right already exist then sends the data down the correct path to be inserted
        if(root.left != null && root.right != null){
            if(root.head[0].flag == to_copy.flag){
                root.head[0].Insert(root.head[0], to_copy);
                return root;
            }
            if(root.head[0].flag < to_copy.flag){
                root.right = Insert(root.right, to_copy, root);
                return root;
            }
            if(root.head[0].flag > to_copy.flag){
                root.left = Insert(root.left, to_copy, root);
                return root;
            }
        }
        //From here on its checking every possible condition to find the middle value if a node is full
        if(root.head[0] != null && root.head[1] != null){
            if (root.head[0].flag < to_copy.flag && to_copy.flag < root.head[1].flag) {
                if(parent == null){
                    Tree temp = new Tree();
                    temp = Insert(temp, to_copy, null);
                    temp.left = Insert(temp.left, root.head[0], null);
                    temp.right = Insert(temp.right, root.head[1], null);
                }
                if(parent != null){
                    Break(parent, root, root.head[0], root.head[1]);
                    parent.head[1].Insert(parent.head[1], to_copy);
                    return parent;
                }
            }
            if (to_copy.flag < root.head[0].flag && root.head[0].flag < root.head[1].flag) {
                if(parent == null){
                    Tree temp = new Tree();
                    temp = Insert(temp, root.head[0], null);
                    temp.left = Insert(temp.left, to_copy, null);
                    temp.right = Insert(temp.right, root.head[1], null);
                }
                if(parent != null){
                    Break(parent, root, to_copy, root.head[1]);
                    parent.head[1].Insert(parent.head[1], root.head[0]);
                    return parent;
                }
            }
            if (root.head[0].flag < root.head[1].flag && root.head[1].flag < to_copy.flag) {
                if(parent == null){
                    Tree temp = new Tree();
                    temp = Insert(temp, root.head[1], null);
                    temp.left = Insert(temp.left, root.head[0], null);
                    temp.right = Insert(temp.right, to_copy, null);
                }
                if(parent != null){
                    Break(parent, root, root.head[0], to_copy);
                    parent.head[1].Insert(parent.head[1], root.head[1]);
                    return parent;
                }
                }
            if (root.head[1].flag < to_copy.flag && to_copy.flag < root.head[0].flag) {
                if(parent == null){
                    Tree temp = new Tree();
                    temp = Insert(temp, to_copy, null);
                    temp.left = Insert(temp.left, root.head[1], null);
                    temp.right = Insert(temp.right, root.head[0], null);
                }
                if(parent != null){
                    Break(parent, root, root.head[1], root.head[0]);
                    parent.head[1].Insert(parent.head[1], to_copy);
                    return parent;
                }
                }
            if (root.head[1].flag < root.head[0].flag && root.head[0].flag < to_copy.flag) {
                if(parent == null){
                    Tree temp = new Tree();
                    temp = Insert(temp, root.head[0], null);
                    temp.left = Insert(temp.left, root.head[1], null);
                    temp.right = Insert(temp.right, root.head[1], null);
                }
                if(parent != null){
                    Break(parent, root, root.head[1], to_copy);
                    parent.head[1].Insert(parent.head[1], root.head[0]);
                    return parent;
                }
                }
            if (to_copy.flag < root.head[1].flag && root.head[1].flag < root.head[0].flag) {
                if(parent == null){
                    Tree temp = new Tree();
                    temp = Insert(temp, root.head[1], null);
                    temp.left = Insert(temp.left, to_copy, null);
                    temp.right = Insert(temp.right, root.head[0], null);
                }
                if(parent != null){
                    Break(parent, root, to_copy, root.head[0]);
                    parent.head[1].Insert(parent.head[1], root.head[1]);
                    return parent;
                }
                }
        }
        return root;
    }

    //This function is a getter for left
    public Tree getLeft() {
        return left;
    }

    //This function is a getter for right
    public Tree getRight() {
        return right;
    }

    //This function breaks a full node into the correct branchs of parent
    protected Tree Break(Tree parent, Tree root, Node small, Node big){
        if(parent.left == root){
            parent.left = Insert(parent.left, small, null);
            parent.middle = Insert(parent.middle, big, null);
        }
        if(parent.right == root){
            parent.right = Insert(parent.right, big, null);
            parent.middle = Insert(parent.middle, small, null);
        }
        return parent;
    }

    //This function displays everything in a linear linked list based on the flag condition
    public void Display(Tree root, int flag){
        if(root == null){
            return;
        }
        if(root.head[0].flag == flag){
            root.head[0].Display(head[0]);
            return;
        }
        if(root.head[1].flag == flag){
            root.head[1].Display(head[1]);
            return;
        }
        else{
            if(root.head[0].flag < flag){
                Display(root.left, flag);
                return;
            }
            if(root.head[0].flag > flag){
                Display(root.right, flag);
                return;
            }
        }
    }

    //This function displays an entire tree
    public void Display_all(Tree root){
        if(root == null){
            return;
        }
        Display_all(root.left);
        root.head[0].Display(root.head[0]);
        root.head[1].Display(root.head[1]);
        Display_all(root.right);
        return;
    }

    //This function destroys the entire tree
    public Tree Remove_all(Tree root){
        if(root == null){
            return root;
        }
        root.left = Remove_all(root.left);
        root.left = Remove_all(root.right);
        root = null;
        return root;
    }
}