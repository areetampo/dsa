class MyLinkedList {

    private class ListNode {
        int val;
        ListNode next;
        ListNode(int _val) {
            val = _val; next = null;
        }
    }

    private ListNode head;
    private ListNode tail;
    private int size;

    public MyLinkedList() {
        head = tail = null;
        size = 0;
    }
    
    public int get(int index) {
        if (index >= size) return -1;
        ListNode curr = head;
        for (int i = 1; i <= index; i++) {
            curr = curr.next;
        }
        return curr.val;
    }
    
    public void addAtHead(int val) {
        ListNode node = new ListNode(val);
        size++;
        if (head == null) {//or tail
            head = tail = node;
            return;
        }
        node.next = head;
        head = node;
    }
                                    //0
    public void addAtTail(int val) {
        ListNode node = new ListNode(val);
        size++;
        if (head == null) {//or tail
            head = tail = node;
            return;
        }
        tail.next = node;
        tail = node;
    }
    
    public void addAtIndex(int index, int val) {
        if (index > size) return;
        ListNode node = new ListNode(val);
        if (index == 0) {
            addAtHead(val); 
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        ListNode curr = head;
        for (int i = 1; i < index; i++) {
            curr = curr.next;
        }
        node.next = curr.next;
        curr.next = node;
        size++;
    }
    
    public void deleteAtIndex(int index) {
        if (index >= size) return;
        if (size == 1) {
            head = tail = null;
            size = 0;
            return;
        }
        if (index == 0) {
            head = head.next;
            size--;
            return;
        }
        ListNode curr = head;
        for (int i = 1; i < index; i++) {
            curr = curr.next;
        }
        curr.next = curr.next.next;
        if (index == size-1) tail = curr;
        size--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */