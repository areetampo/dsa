class MyStack {
    private Queue<Integer> main;
    private Queue<Integer> auxi;

    public MyStack() {
        main = new LinkedList<>();
        auxi = new LinkedList<>();
    }
    
    public void push(int x) {
        while (!main.isEmpty()) {
            auxi.add(main.remove());
        }
        main.add(x);
        while (!auxi.isEmpty()) {
            main.add(auxi.remove());
        }
    }
    
    public int pop() {
        return main.remove();
    }
    
    public int top() {
        return main.peek();
    }
    
    public boolean empty() {
        return main.size() == 0;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */