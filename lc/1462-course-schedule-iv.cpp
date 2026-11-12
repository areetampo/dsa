class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {//m-1 floyd warshall
        vector<vector<bool>> g(n, vector<bool>(n, 0));
        for (auto &i : pre) g[i[0]][i[1]] = 1;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = g[i][j] || g[i][k] == 1 && g[k][j] == 1;
                }
            }
        }
        vector<bool> res;
        for (auto &i : q) res.push_back(g[i[0]][i[1]]);
        return res;
    }
};//m-2 khan algo_> in this approach, note:
//for(auto &it:graph[cur]){
//         table[cur][it]=true;
//         for(int i=0;i<n;i++) if(table[i][cur]==true) table[i][it] = true;
//         indegree[it]--;
//         if(indegree[it]==0) q.push(it);
//     }
//here using for(int i=0;i<n;i++) if(table[i][cur]==true) table[i][it] = true;
//instead of for(int i=0;i<n;i++) if(table[it][i]==true) table[cur][i] = true;
//cuz for imagine a graph like:
//1 -> 2 -> 3 -> 5 -> 7
//          |-> 4 -> 8        (3 has 2 neighbors)
//so with khan's algo, when 3 is removed from q and 3's (cur) neighbors 4, 5 (it)
//are true then the for loop would check if 4,5 (it) have any future neighbors (they have 7, 8) (i) so will assign 3 as prereq of 7, 8 but this eventually
//fails as we are looking at future neighbors of it, then if there is an edge
//join cur to that, THIS DOES NOT TAKE INTO ACCOUNT ANY NODES PREV OF CUR
//EG 1 IS PREV OF CUR (1->2->3) SO WITH 3 AS CUR AND ITS NEIGHBORS (WHICH ARE 
//DIRECTLY CONNECTED AND NOT AS A VERY BACK PREREQ (3 -> X -> Y) ONLY X WILL BE
//COUNTED HERE AS ONLY ITS MARKED IN TABLE RIGHT NOW AS DIRECT EDGE SINCE KHAN
//ALGO HASNT REACHED IT YET) SO NOW X BEING it, ITS FUTURE NEIGHBORS ARE LOOKED 
//AR [it][i] AND IF THEY EXISTS (AGAIN THIS ALSO CONSIDERS A DIRECT CONNECTED
//EDGE) THEN ONLY cur TO it IS MARKED WHICH IS INCORRECT CUZ LIKE THIS WE MISS
//OU TON PREVIOUS PRE-REQUISITES, LIKE 1 WIL NEVER GET MARKED AS PREREQ OF 5 HERE
//so correct approach is to take a look back: at the nodes i prereq of cur 
//then they are also marked prereq of cur's neighbors (it)

// vector<bool> ans;
// vector<vector<int>> graph(n);   
// vector<vector<bool>> table(n,vector<bool>(n,false));
// vector<int> indegree(n,0);
// for(int i=0;i<prerequisites.size();i++)
// {
//     graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
//     indegree[prerequisites[i][1]]++;
// }
// queue<int> q;
// for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
// while(!q.empty())
// {
//     int cur=q.front();
//     q.pop();
//     for(auto &it:graph[cur])
//     {
//         table[cur][it]=true;
//         for(int i=0;i<n;i++) if(table[i][cur]==true) table[i][it] = true;
//         indegree[it]--;
//         if(indegree[it]==0) q.push(it);
//     }
// }
// for(int i=0;i<queries.size();i++) ans.push_back(table[queries[i][0]][queries[i][1]]);
// return ans;