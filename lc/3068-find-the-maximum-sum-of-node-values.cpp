class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        //since each node connected to other node via some path, just need to maximize xor of 2 nodes at once
        //eg: x-y, x-a-y, x-a-b-y, x-a-b-c-y.... all these edges connecting x to y can be performed the operation upon
        //and in end we will have the values of x, y changed and a,b,c... (the nodes between x, y in path) remain same
        //since xor twice on them cancelled out -> also note that each node can have only 2 values ->
        //original or original ^ k cuz multiple times same operation on a node results in nodeVal XOR k^m === nodeVal or 
        //nodeVal^k
        //so find out which nodes give inc val after xor with k, pick pair of those nodes and 2 nodes share a path definitely
        //so abve parhraph prop applies
        //to do the above 2 lines work: have xorr[n] which has 0 if the ith node^k < node else has 1, sort this xorr[] arr
        //now it may be something like this: 0 0 0 0 0 1 1 1 1 1 1 (let)
        //now we only need to look at node pairs with 1 (inc val after xor with k) cuz no point of looking at lets suppose 
        //a pair with 0 and 1 cuz on doing xor on all the edges in that path between those nodes, in end only the the node
        //whose xor with k inc its val add to res and the one whose xor with k reduces its value reduces res so no use.
        //keep the node whose value inc after xor instead of picking the node with 0 in xorr[] pick the one with 1 val in xorr[]
        //so overall profit in res | fact: there is no use of edge vvi
        //res = sum of all 0 nodes + sum of all the 1 nodes xorred, now 2 cases:
        //case 1: even 1s -> pairs easily made so return res
        //case 2: odd 1s ->
        //res -= min of case((a), (b))
        //a) removing the 1 with min xorr diff (its diff) | explanation: as all 1s nodes xorred, min xor diff node 
        //   taken twice (to form pairs) so its eff sum = its original val instead of its val^k so res - diff
        //b) xor of all 1s taken and since odd ones, one node extra needed to form pairs -> use a 0 node which has 
        //   min diff since it being taken means after xor with k its val decreased and we want min dec for max res
        long long res = 0;
        int min1diff = INT_MAX, min0diff = INT_MAX, onesCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int v = nums[i];
            res += v;//all vals from nums added
            int xorrVal = v ^ k;
            int diff = xorrVal - v;
            if (diff > 0) {// 1
                onesCnt++;
                res += diff;//the xors of all 1s accounted here
                min1diff = min(min1diff, diff);
            } else {// 0
                min0diff = min(min0diff, -diff);//- for absolute value of diff
            }
        }
        min1diff == INT_MAX ? 0 : min1diff;
        min0diff == INT_MAX ? 0 : min0diff;
        return res - (onesCnt % 2 ? min(min1diff, min0diff) : 0);
    }
};