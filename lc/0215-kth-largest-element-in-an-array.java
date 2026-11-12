class Solution {
    public int findKthLargest(int[] nums, int k) {
        //O(2n) + O(max - min + 1) + space O(max - min + 1)
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int el: nums) {
            max = Math.max(max, el);
            min = Math.min(min, el);
        }
        int check[] = new int[max-min+1];
        for (int el : nums) {
            check[el-min]++;
        }

        int count = 0;
        for (int i = check.length-1; i >= 0; i--) {
            count += check[i];//all duplicates also put in 
            if (count >= k) return i + min; 
        }

        return -1;
    }
}
// PriorityQueue<Integer> pq = new PriorityQueue<>();//min heap ok k size
// for (int el : nums) {//n . log k + space (k)
//     pq.add(el);
//     while (pq.size() > k) pq.remove();
// }
// return pq.peek();