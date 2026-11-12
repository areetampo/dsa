class Solution {
    public List<Integer> findLonely(int[] nums) {//O(sort + n)
        //appears once, x-1 / x+1 don't appear
        if (nums.length == 1) {
            ArrayList<Integer> ans = new ArrayList<>(); ans.add(nums[0]); return ans;
        } 

        Arrays.sort(nums);
        ArrayList<Integer> ans = new ArrayList<>();

        if (nums[0] != nums[1] && nums[0]+1 != nums[1])
        ans.add(nums[0]);

        for (int i = 1; i < nums.length-1; i++) {
            if ((nums[i-1] != nums[i]) && (nums[i] != nums[i+1]) && (nums[i-1] != nums[i]-1) && (nums[i+1] != nums[i]+1))
            ans.add(nums[i]);
        }

        if (nums[nums.length-2] != nums[nums.length-1] && nums[nums.length-2]+1 != nums[nums.length-1])
        ans.add(nums[nums.length-1]);
        
        return ans;
    }

    //M-2 More time, space

    // HashMap<Integer, Integer> hm = new HashMap<>();
    //     for (int el : nums)
    //     hm.put(el, hm.getOrDefault(el, 0) + 1);

    //     ArrayList<Integer> ans = new ArrayList<>();
    //     for (int i = 0; i < nums.length; i++) {
    //         if (hm.get(nums[i]) == 1 && !hm.containsKey(nums[i]-1) && !hm.containsKey(nums[i]+1))
    //         ans.add(nums[i]);
    //     }

    //     return ans;
}