class Solution {
public:
    int minimizeArrayValue(vector<int>& v) {
        int mx = v[0];//res which is the max val of arr will always be >= v[0]
        //at each i: available is the total amount that can be added to vals at
        //0...i-1 indices so that all of them have a value of mx
        //since each [idx] can decrease and [idx - 1] increase,
        //at each i, arr must look like this: mx, a, b, c,...,[i]
        //where a,b,c... all are <= mx and available = i * mx - sum([0]...[i-1])
        //considering 0 based indexing
        for (long long i = 1, available = 0; i < v.size(); i++) {
            //smaller value than mx means it has mx - v[i] available space to
            //have elements from right (it will increase till mx)
            if (v[i] <= mx) available += mx - v[i];
            //v[i] > mx so v[i] is contender to become mx (max val in arr)
            //so we try to keep it at most mx
            else {
                //v[i] = mx now and the extra must be put in available space 
                //so those elements at left which are < mx can reach at most mx
                long long extra = v[i] - mx;
                //fill the < mx indices with extra
                if (extra > available) {
                    //extra transfered to left so all elements = mx until i
                    //now we have leftover extra which cannot move right
                    extra -= available;
                    //so spread across 0 to i
                    //mx increases by ceil of extra / (i + 1)
                    mx += (extra + i) / (i + 1);
                    //to all the indices that did not get assigned with mx val
                    //still have space for future extras to be put
                    if (extra % (i + 1) == 0) available = 0;//all taken
                    else available = i + 1 - (extra % (i + 1));//leftover
                } 
                //all extra assigned to left and available has some remaining val
                else available -= extra;
            }
            // cout << mx << " " << available << "\n";
        }
        return mx;
    }
};