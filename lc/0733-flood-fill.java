class Solution {
    static int nodeValToColor;
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        nodeValToColor = image[sr][sc];//nodes having this value are meant to be colored;
        dfs(image, sr, sc, color);
        return image;//commiting changes in the data itself 
    }
    public static void dfs(int[][] image, int sr, int sc, int color) {
        image[sr][sc] = color; 
        if (0 < sr && image[sr-1][sc] != color && image[sr-1][sc] == nodeValToColor) { 
            dfs(image, sr-1, sc, color);
        }
        if (sr < image.length-1 && image[sr+1][sc] != color && image[sr+1][sc] == nodeValToColor) {
            dfs(image, sr+1, sc, color);
        }
        if (0 < sc && image[sr][sc-1] != color && image[sr][sc-1] == nodeValToColor) {
            dfs(image, sr, sc-1, color);
        }
        if (sc < image[0].length-1 && image[sr][sc+1] != color && image[sr][sc+1] == nodeValToColor) {
            dfs(image, sr, sc+1, color);
        }
    }
}