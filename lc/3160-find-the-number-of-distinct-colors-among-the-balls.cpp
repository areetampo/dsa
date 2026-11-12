class Solution {
public:
    vector<int> queryResults(int l, vector<vector<int>>& q) {
        unordered_map<int, int> ball_has_color;//balls 0 to 1e9
        unordered_map<int, int> color_has_balls;//colors 1 to 1e9
        vector<int> res;
        for (auto &i : q) {
            int ball = i[0], color = i[1];
            int prev_color = ball_has_color[ball];
            if (color_has_balls.count(prev_color) && --color_has_balls[prev_color] == 0) 
                color_has_balls.erase(prev_color);
            color_has_balls[color]++;
            ball_has_color[ball] = color;
            res.push_back(color_has_balls.size());
        }
        return res;

    }
};