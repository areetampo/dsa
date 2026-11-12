class NumArray {
    private static int[] st;
    private static int[] copy;
    public NumArray(int[] nums) {
        copy = nums;
        st = new int[4*nums.length-1];
        buildUtil(nums, 0, 0, nums.length-1);
    }
    private static int buildUtil(int[] nums, int treeIdx, int s, int e) {
        if (s == e) return st[treeIdx] = nums[s];//or [e]
        return st[treeIdx] = buildUtil(nums, treeIdx*2 + 1, s, s+(e-s)/2) + buildUtil(nums, treeIdx*2 + 2, s+(e-s)/2 + 1, e);
    }
    
    public void update(int index, int val) {
        int s = 0; int e = copy.length - 1;
        int mid = -1; int treeIdx = 0; int sumDiff = -copy[index] + val;
        while (s != e) {
            st[treeIdx] += sumDiff;
            mid = s + (e-s)/2;
            if (index > mid) {
                treeIdx = treeIdx*2 + 2; s = mid + 1;
            }
            else {
                treeIdx = treeIdx*2 + 1; e = mid;
            }
        }
        st[treeIdx] = val;//s = e in end
        copy[index] = val;//update in arr also
    }
    
    public int sumRange(int left, int right) {
        return rangeUtil(0, 0, copy.length-1, left, right);
    }
    private static int rangeUtil(int treeIdx, int s, int e, int qi, int qj) {
        if (e < qi || qj < s) return 0;//no overlap
        if (qi <= s && e <= qj) return st[treeIdx];//complete overlap
        //partial overlap
        return rangeUtil(treeIdx*2 + 1, s, s+(e-s)/2, qi, qj) + rangeUtil(treeIdx*2 + 2, s+(e-s)/2 + 1, e, qi, qj);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */