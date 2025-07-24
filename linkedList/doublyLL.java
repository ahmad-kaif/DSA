class DoublyLL {

    static class Node {
        int val;
        Node next;
        Node prev;

        Node(int val) {
            this.val = val;
            next = null;
            prev = null;
        }
    }

    // Insert at position (1-based index)
    public static Node insert(Node head, int val, int pos) {
        Node newNode = new Node(val);

        if (pos <= 0) return head;

        if (pos == 1) {
            newNode.next = head;
            if (head != null) head.prev = newNode;
            return newNode;
        }

        Node curr = head;
        for (int i = 1; i < pos - 1 && curr != null; i++) {
            curr = curr.next;
        }

        if (curr == null) return head; // position out of bounds

        newNode.next = curr.next;
        newNode.prev = curr;
        if (curr.next != null) curr.next.prev = newNode;
        curr.next = newNode;

        return head;
    }

    // Delete node at position (1-based index)
    public static Node deleteNode(Node head, int pos) {
        if (head == null || pos <= 0) return head;

        if (pos == 1) {
            Node nextNode = head.next;
            if (nextNode != null) nextNode.prev = null;
            return nextNode;
        }

        Node curr = head;
        for (int i = 1; i < pos && curr != null; i++) {
            curr = curr.next;
        }

        if (curr == null) return head; // position out of bounds

        if (curr.prev != null) curr.prev.next = curr.next;
        if (curr.next != null) curr.next.prev = curr.prev;

        return head;
    }

    // Print the linked list
    public static void printLL(Node head) {
        while (head != null) {
            System.out.print(head.val + " <-> ");
            head = head.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Node head = null;

        head = insert(head, 10, 1);
        head = insert(head, 20, 2);
        head = insert(head, 30, 3);
        printLL(head);

        head = insert(head, 15, 2); // insert 15 at position 2

        System.out.print("After insertions: ");
        printLL(head);

        head = deleteNode(head, 3); // delete node at position 3

        System.out.print("After deletion at pos 3: ");
        printLL(head);
    }
}
