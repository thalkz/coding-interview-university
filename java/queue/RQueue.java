public class RQueue {

    private class Node {
        private Node next;
        private int value;

        public Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }

        int getValue() {
        return value;
        }

        Node getNext() {
        return next;
        }

        void setNext(Node next) {
        this.next= next;
        }
    }

    Node root;
    int size;

    public RQueue() {
        root = null;
        size = 0;
    }

    public void enqueue(int value) {
        Node newRoot = new Node(value, root);
        root = newRoot;
        size++;
    }

    public int dequeue() {

        System.out.println("Size : " + size);

        if (empty()) {
            throw new RuntimeException("Can't dequeue empty RQueue");
        }

        if (size == 1) {
            int val = root.getValue();
            root = null;
            size--;
            return val;
        } else {
            Node node = root;
            while (node.getNext().getNext() != null) {
                node = node.getNext();
            }
            int val = node.getNext().getValue();
            node.setNext(null);

            size--;
            return val;
        }
    }

    public String toString() {
        String result = "[ ";

        for (Node n = root; n != null; n = n.getNext()) {
            result += n.getValue() + " -> ";
        }
        result += "null ]";
        return result;
    }

    public boolean empty() {
        return root == null;
    }

    public static void main(String[] args) {
        System.out.println("RQueue tests :");

        RQueue rq = new RQueue();
        rq.enqueue(1);
        rq.enqueue(2);
        rq.enqueue(3);
        rq.enqueue(4);

        System.out.println(rq.toString());

        System.out.println("Dequeued : " + rq.dequeue());

        System.out.println(rq.toString());

        System.out.println("Is empty ? "+ rq.empty());

        System.out.println("Dequeued : " + rq.dequeue());
        System.out.println(rq.toString());
        System.out.println("Dequeued : " + rq.dequeue());
        System.out.println(rq.toString());

        rq.enqueue(5);

        System.out.println("Dequeued : " + rq.dequeue());
        System.out.println(rq.toString());
        System.out.println("Dequeued : " + rq.dequeue());      
        System.out.println(rq.toString());
    }
}