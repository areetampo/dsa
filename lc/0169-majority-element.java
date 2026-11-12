class Solution {
    public int majorityElement(int[] nums) {//Boyer-Moore 1 pass
        int candidate = 0;//anything
        int count = 0;
        for (int el : nums) {
            if (candidate == el) {
                count++;
            }
            else {
                if (count == 0) {
                    candidate = el; count++;
                }
                else count--;
            }
        }
        return candidate;
    }
}   

// HashMap<Integer, Integer> hm = new HashMap<>();
// for (int i = 0; i < nums.length; i++) {
//     hm.put(nums[i], hm.getOrDefault(nums[i], 0) + 1);
// }
// for (Integer key : hm.keySet()) 
// if (hm.get(key) > nums.length/2)
// return key;
// return -1;//no need actually as question says key always exists

// Arrays.sort(nums);
// return nums[nums.length/2];

//TOO MUCH SPACE

// int max = 0;
// int min = 0;
// for (int i : nums) {
//     max = Math.max(max, i);
//     min = Math.min(min, i);
// }
// int count[] = new int[-min+max+1];
// Arrays.fill(count, 0);
// for (int i : nums) {
//     if (i < 0) count[-min+i]++; 
//     else if (i > 0) {
//         if (min == 0)
//         count[i]++;
//         else count[-min+i]++;
//     }
//     else count[-min]++;
// }
// for (int i = 0; i < count.length; i++) {
//     if (count[i] > nums.length/2) 
//     return i+min;
// }
// return -1;