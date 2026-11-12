class MyQueue {
    private Stack<Integer> main;
    private Stack<Integer> auxi ;

    public MyQueue() {
        main = new Stack<>();
        auxi = new Stack<>();
    }
    
    public void push(int x) {
        main.push(x);
    }
    
    public int pop() {
        while (!main.isEmpty()) {
            auxi.push(main.pop());
        }
        int val = auxi.pop();
        while (!auxi.isEmpty()) {
            main.push(auxi.pop());
        }
        return val;
    }
    
    public int peek() {
        while (!main.isEmpty()) {
            auxi.push(main.pop());
        }
        int val = auxi.peek();
        while (!auxi.isEmpty()) {
            main.push(auxi.pop());
        }
        return val;
    }
    
    public boolean empty() {
        return main.size() == 0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */