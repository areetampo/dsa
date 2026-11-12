class MyHashMap {
    private int n;
    private int N;

    private class Node {
        int key;
        int val;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    }

    private LinkedList<Node>[] bucket;
    
    public MyHashMap() {
        N = 4;
        bucket = new LinkedList[4];
        for (int i = 0; i < 4; i++) {
            bucket[i] = new LinkedList<>();
        }
    }
    
    private int bucketIdx(int key) {
        return Math.abs(Integer.hashCode(key)) % N;
    }

    private int searchLL(int key, int bucketIdx) {
        LinkedList<Node> ll = bucket[bucketIdx];
        for (int i = 0; i < ll.size(); i++) {
            if (ll.get(i).key == key) return i;
        }
        return -1;
    }

    private void rehash() {
        LinkedList<Node>[] temp = bucket;
        N = N * 2;
        bucket = new LinkedList[N];
        for (int i = 0; i < N; i++) {
            bucket[i] = new LinkedList<>();
        }
        for (LinkedList<Node> list : temp) {
            for (Node n : list) {
                put(n.key, n.val);
            }
        }
    }
    
    public void put(int key, int value) {
        int bucketIdx = bucketIdx(key);
        int listIdx = searchLL(key, bucketIdx);
        if (listIdx == -1) {
            bucket[bucketIdx].add(new Node(key, value));
            n++;
            if ((double) (n / N) > 2.0) {
                rehash();
            }
        }
        else bucket[bucketIdx].get(listIdx).val = value;
    }

    public int get(int key) {
        int bucketIdx = bucketIdx(key);
        int listIdx = searchLL(key, bucketIdx);
        if (listIdx == -1) {
            return -1;
        }
        return bucket[bucketIdx].get(listIdx).val;
    }
    
    public void remove(int key) {
        int bucketIdx = bucketIdx(key);
        int listIdx = searchLL(key, bucketIdx);
        if (listIdx != -1) {
            bucket[bucketIdx].remove(listIdx);
            n--;
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */