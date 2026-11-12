class Solution {
    public int minProcessingTime(List<Integer> processorTime, List<Integer> tasks) {
        Collections.sort(processorTime);
        Collections.sort(tasks);
        int ans = Integer.MIN_VALUE;
        int j = tasks.size()-1;
        for (int el : processorTime) {
            ans = Math.max(ans, el + tasks.get(j));
            j -= 4;
        }
        return ans;
    }
}