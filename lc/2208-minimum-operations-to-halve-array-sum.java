class Solution {
    public int halveArray(int[] nums) {
        PriorityQueue<Double> pq = new PriorityQueue<>(Comparator.reverseOrder());
        double origSum = 0;
        for (int i = 0; i < nums.length; i++) {
            pq.add((double) nums[i]);
            origSum += nums[i];
        }

        int steps = 0;
        double newSum = origSum;
        double curr = 0;
        while (newSum > origSum/2) {
            curr = pq.remove()/2;
            newSum -= curr;
            pq.add(curr);
            steps++;
        }

        return steps;
    }
}