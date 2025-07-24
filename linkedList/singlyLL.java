public class singlyLL {

    static class Node {
        int val;
        Node next;

        Node(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Print the LinkedList
    public static void printLL(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.val + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    // Insert at a given position (1-based indexing)
    public static Node insert(Node head, int val, int pos) {
        Node nodeToBeInserted = new Node(val);
        if (pos == 1) {
            nodeToBeInserted.next = head;
            return nodeToBeInserted;
        }

        Node temp = head;
        for (int i = 1; i < pos - 1 && temp != null; i++) {
            temp = temp.next;
        }

        if (temp == null) return head;

        nodeToBeInserted.next = temp.next;
        temp.next = nodeToBeInserted;
        return head;
    }

    // Delete node at a given position (1-based indexing)
    public static Node deleteNode(Node head, int pos) {
        if (head == null || pos <= 0) return head;

        if (pos == 1) {
            return head.next;
        }

        Node temp = head;
        for (int i = 1; i < pos - 1 && temp != null; i++) {
            temp = temp.next;
        }

        if (temp == null || temp.next == null) return head;

        temp.next = temp.next.next;
        return head;
    }

    public static void main(String[] args) {
        Node x = new Node(10);
        Node y = new Node(20);
        Node z = new Node(30);
        Node p = new Node(40);

        x.next = y;
        y.next = z;
        z.next = p;

        Node head = x;

        System.out.println("Initial List:");
        printLL(head);

        System.out.println("\nInserting 35 at position 4:");
        head = insert(head, 35, 4);
        printLL(head);

        System.out.println("\nInserting 5 at head:");
        head = insert(head, 5, 1);
        printLL(head);

        System.out.println("\nDeleting node at position 3:");
        head = deleteNode(head, 3);
        printLL(head);

        System.out.println("\nDeleting head node:");
        head = deleteNode(head, 1);
        printLL(head);
    }
}
