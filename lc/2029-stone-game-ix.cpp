class Solution {
public:
    bool stoneGameIX(vector<int>& v) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (int i : v) {
            c0 += i % 3 == 0;
            c1 += i % 3 == 1;
            c2 += i % 3 == 2;
        }

        // taken stones sum remainders
        // A - B - (A - B)s... - A
        // 1 - 1 - (2 - 1)s... - 2
        // 2 - 2 - (1 - 2)s... - 1
        // 1 and 2 can be used interchangeably depending only on count c1,c2
        // both optimal patterns for each player to not lose until the end makes it happen

        // even count of 0s does nothing: a player uses a 0 to skip turn, 
        // other player uses it too making the turn back to prev player
        // odd count: one 0 can be used as an advantage by any player to skip turn
        // also no player places 0 first thats auto loss
        int flip = c0 & 1, 
            mxc = max(c1, c2), mnc = min(c1, c2);

        // NOTE: if no stones left to place: bob wins
        cout << mnc << " " << mxc << " " << flip;

        // both 0: alice loses in first move and flip wont matter (choosing 0 makes sum remainder 0 only)
        if (mxc == 0) return 0;

        // 1/0 or 2/0
        // alice places 1 stone or alice places 1 and bob places 2nd
        // alice wont place a 0 since thats auto loss
        // and irrespective of flip (keeping game in stalemate) bob has no stone in end to place: bob wins
        if (mnc == 0 && mxc <= 2) return 0;

        // 3/0
        // alice places 1 stone or alice places 1 and bob places 2nd
        // whoever has to place the third same stone loses
        // which would be alice loses unless flip
        if (mnc == 0 && mxc >= 3) return 0 - flip;

        // 1/1
        // bob will lose placing the 2nd stone unless flip makes alice lose
        if (mnc == 1 && mxc == 1) return 1 - flip;

        // 2/1
        // alce places =1 occurence stone, bob will lose placing the 2nd stone unless flip makes alice lose
        // next case:
        // first turn alice place >=1 occurence stone so in 3rd turn 
        // she must use the =1 occurence stone and irrespective of c0
        // no stones left in end to place with stalemate: bob wins
        // result: alice wins only if no flip
        if (mnc == 1 && mxc == 2) return 1 - flip;

        // 3/1
        // bob will lose placing the 2nd stone unless flip makes alice lose
        // next case:
        // first turn alice place >=1 occurence stone so in 3rd turn 
        // she must use the =1 occurence stone then bob places 4th stone
        // if theres not more than 4 moves bob wins irrespective of c0
        // since skipping moves allows for bob to not have any stones to place in end
        // 1 - 0 - 1 - 2 - 1
        // 1 - 1 - 0 - 2 - 1
        // 1 - 1 - 2 - 0 - 1
        // 1 - 1 - 2 - 1 - 0
        if (mnc == 1 && mxc == 3) return 0;

        // >3/1
        // no flip: alice wins
        // first move place =1 c bob cant place the same
        // flip:
        // same case as prev alice wins
        if (mnc == 1 && mxc > 3) return 1;

        // >=2/2
        // 1 - 1 - 2 - 
        // c with 2 occurences used first to make 4th move lose (alice win) unless flip
        if (mnc == 2 && mxc >= 2) return 1 - flip;

        // >2/>2 optimal pattern creation: 1 - 1 - (2 - 1)s - 2
        // odd diff =1: say 3 1s 4 2s -----------
        // 1 - 1 - 1x(2 - 1) - 2 - bob lose (unless flip at 2nd)
        // 2 - 2 - 2x(1 - 2) - 1 - all stones used: alice lose (flip stalemate + no stones for bob to place)
        // alice loses if flip exists
        // odd diff >1: say 3 1s 6 2s -----------
        // 1 - 1 - 1x(2 - 1) - 2 - bob lose (unless flip at 2nd)
        // 2 - 2 - 3x(1 - 2) - alice lose (unless flip at 3rd and bob cant use at 2nd else he lose)
        // alice wins: no flip use pattern 1 else 2
        // even diff =0: say 3 both (1,2 swapable) -----------
        // 1 - 1 - 1x(2 - 1) - 2 - bob lose (unless flip at 2nd)
        // even diff =2: say 6 1s 4 2s -----------
        // 1 - 1 - 4x(2 - 1) - alice lose unless flip at 3rd - but bob will use at 2nd so no stones in end stalemate
        // 2 - 2 - 2x(1 - 2) - 1 - bob lose (unless flip at 2nd)
        // if theres flip bob win else alice uses 2nd pattern
        // even diff >2: say 8 1s 4 2s -----------
        // 1 - 1 - 4x(2 - 1) - alice lose unless flip at 3rd - bob cant use at 2nd since his turn in end will make him lose
        // 2 - 2 - 2x(1 - 2) - 1 - bob lose (unless flip at 2nd)
        // if theres flip alice uses 1st pattern else uses 2nd
        int d = mxc - mnc;
        return d & 1 ? 
                d == 1 ? !flip : 1 : 
                d <= 2 ? !flip : 1;
    }
};