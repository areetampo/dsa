# 1. SETUP BASE PATH
$basePath = "C:\Iris\dsa\templates"

# 2. COMPREHENSIVE TEMPLATE
$template = @"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <numeric>
#include <bitset>
#include <iomanip>

using namespace std;

/**
 * TOPIC: TOPIC_NAME
 * Complexity: Time O(), Space O()
 * Edge Cases: Empty/Null, Single Element, Duplicates, Overflow, Negatives
 */

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    // Your Code Logic Here
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
"@

# 3. DEFINE HIERARCHY (Add your remaining topics to this list in order)
# Using [ordered] hash table to ensure chronological order is preserved
$dsaStructure = [ordered]@{
  "Arrays and Strings" = @("Array Basics and Operations", "Dynamic Arrays", "2D Arrays", "String Manipulation", "String Matching Algorithms", "Prefix Sum Arrays", "Suffix Arrays", "Kadanes Algorithm", "Dutch National Flag Problem", "Array Rotation", "Spiral Matrix Traversal")
  "Searching Algorithms" = @("Linear Search", "Binary Search Iterative", "Binary Search Recursive", "Binary Search on Answer", "Lower Bound and Upper Bound", "Search in Rotated Sorted Array", "Find Peak Element", "Square Root Binary Search", "Median of Two Sorted Arrays", "Exponential Search", "Interpolation Search", "Jump Search")
  "Sorting Algorithms" = @("Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort", "Counting Sort", "Radix Sort", "Bucket Sort", "Shell Sort", "Tim Sort", "Custom Comparators")
  "Recursion and Backtracking" = @("Recursion Basics", "Tail Recursion", "Recursive Tree Method", "N-Queens Problem", "Sudoku Solver", "Permutations", "Combinations", "Subset Generation", "Letter Combinations of Phone Number", "Word Search", "Palindrome Partitioning", "Generate Parentheses", "Rat in a Maze", "Knights Tour Problem")
  "Divide and Conquer" = @("Divide and Conquer Strategy", "Merge Sort DAC", "Quick Sort DAC", "Binary Search DAC", "Closest Pair of Points", "Strassens Matrix Multiplication", "Karatsuba Algorithm")
  "Bit Manipulation" = @("Bitwise Operators", "Check if Power of Two", "Count Set Bits", "Single Number Problem", "Find Two Non-Repeating Elements", "Bit Masking", "Subset Generation Bits", "Gray Code", "Reverse Bits", "Bitwise AND Range")
  "Mathematical Algorithms" = @("Euclidean Algorithm", "Sieve of Eratosthenes", "Segmented Sieve", "Prime Factorization", "Modular Arithmetic", "Modular Exponentiation", "Binary Exponentiation", "Combinatorics nCr nPr", "Pascals Triangle", "Matrix Exponentiation", "Number Theory Basics")
  "String Algorithms" = @("KMP Algorithm", "Rabin-Karp Algorithm", "Z Algorithm", "Aho-Corasick Algorithm", "Manachers Algorithm", "String Hashing", "Longest Common Prefix", "Anagram Problems")
  "Linked Lists" = @("Singly Linked List", "Doubly Linked List", "Circular Linked List", "Fast and Slow Pointers", "Reverse Linked List", "Reverse Linked List in Groups", "Merge Two Sorted Lists", "Detect and Remove Loop", "Find Middle Element", "Palindrome Linked List")
  "Stacks and Queues" = @("Stack Implementation", "Queue Implementation", "Circular Queue", "Deque", "Priority Queue", "Monotonic Stack", "Next Greater Element", "Stock Span Problem", "Valid Parentheses", "Expression Evaluation", "Queue Using Stacks", "Stack Using Queues")
  "Greedy Algorithms" = @("Greedy Approach Basics", "Activity Selection Problem", "Fractional Knapsack", "Job Sequencing Problem", "Huffman Coding", "Minimum Platforms Required", "Jump Game", "Gas Station Problem", "Candy Distribution", "Meeting Rooms")
  "Hash Tables and Hashing" = @("Hash Table Basics", "Hash Functions", "Collision Resolution", "Hash Map Implementation", "Hash Set Implementation", "Count Frequency of Elements", "Two Sum Problem", "Subarray Sum Equals K", "Longest Consecutive Sequence", "Group Anagrams")
  "Trees General" = @("Tree Terminology and Basics", "Binary Tree", "Full Binary Tree", "Complete Binary Tree", "Balanced Tree", "Unbalanced Tree", "Tree Traversals", "Level Order Traversal", "Vertical Order Traversal", "Boundary Traversal", "Zigzag Traversal", "Tree Height and Depth", "Diameter of Tree", "Lowest Common Ancestor")
  "Binary Search Trees BST" = @("BST Basics and Properties", "BST Insertion", "BST Deletion", "BST Search", "Validate BST", "Kth Smallest Element in BST", "Inorder Successor and Predecessor", "Convert Sorted Array to BST", "BST to Greater Sum Tree")
  "Balanced Trees" = @("AVL Trees", "Red-Black Trees", "B-Trees", "B+ Trees", "2-3 Trees", "Splay Trees")
  "Heaps and Priority Queues" = @("Heap Basics", "Heap Implementation", "Heapify Operation", "Heap Sort", "Top K Elements", "Kth Largest Element", "Merge K Sorted Lists", "Median of Data Stream", "Task Scheduler")
  "Advanced Tree Structures" = @("Trie Prefix Tree", "Trie Insert Search Delete", "Autocomplete Using Trie", "Word Search in Trie", "Segment Trees", "Segment Tree Range Queries", "Lazy Propagation", "Fenwick Tree", "Suffix Trees", "Suffix Automaton")
  "Graphs Basics" = @("Graph Terminology", "Directed Graph", "Undirected Graph", "Weighted Graph", "Graph Representation Adjacency Matrix", "Graph Representation Adjacency List", "Edge List Representation")
  "Graph Traversal Algorithms" = @("Breadth-First Search BFS", "Depth-First Search DFS", "Iterative Deepening DFS", "Bidirectional Search", "Connected Components", "Flood Fill Algorithm", "Number of Islands")
  "Graph Algorithms Advanced" = @("Topological Sort", "Kahns Algorithm", "Cycle Detection Directed", "Cycle Detection Undirected", "Bipartite Graph Check", "Kosarajus Algorithm", "Tarjans Algorithm", "Articulation Points", "Bridges in Graph")
  "Shortest Path Algorithms" = @("Dijkstras Algorithm", "Bellman-Ford Algorithm", "Floyd-Warshall Algorithm", "A Star Search Algorithm", "0-1 BFS")
  "Minimum Spanning Tree" = @("Prims Algorithm", "Kruskals Algorithm", "Disjoint Set Union DSU", "Union by Rank", "Path Compression")
  "Dynamic Programming DP" = @("DP Introduction and Memoization", "Tabulation vs Memoization", "Fibonacci Sequence", "0-1 Knapsack Problem", "Unbounded Knapsack", "Subset Sum Problem", "Partition Equal Subset Sum", "LCS", "LIS", "Edit Distance", "Coin Change Problem", "Rod Cutting Problem", "Matrix Chain Multiplication", "Egg Dropping Problem", "Longest Palindromic Subsequence", "Longest Palindromic Substring", "Palindrome Partitioning DP", "Catalan Numbers", "DP on Trees", "DP on Grids", "Minimum Path Sum", "Triangle Minimum Path", "House Robber Problem", "Best Time to Buy and Sell Stock", "Word Break Problem", "Interleaving Strings")
  "DP Optimization Techniques" = @("Knuths Optimization", "Convex Hull Trick", "Divide and Conquer Optimization", "Bitmask DP", "Digit DP", "State Space Reduction")
  "Advanced Data Structures" = @("Skip List", "Bloom Filter", "Sparse Table", "ISAM", "Treap", "Rope Data Structure", "Persistent Data Structures")
  "Game Theory" = @("Nim Game", "Sprague-Grundy Theorem", "Minimax Algorithm", "Alpha-Beta Pruning")
  "Randomized Algorithms" = @("Randomized Quick Sort", "Reservoir Sampling", "Randomized Selection", "Monte Carlo Methods", "Las Vegas Algorithms")
  "PROBLEM-SOLVING PATTERNS\Two Pointers Pattern" = @("Two Pointers Basics", "Opposite Direction", "Same Direction", "Two Sum Sorted", "Three Sum", "Four Sum", "Container With Most Water", "Trapping Rain Water", "Remove Duplicates", "Move Zeroes", "Sort Colors")
  "PROBLEM-SOLVING PATTERNS\Fast and Slow Pointers" = @("Cycle Detection", "Find Cycle Start", "Happy Number", "Middle of Linked List", "Palindrome Linked List", "Reorder List")
  "PROBLEM-SOLVING PATTERNS\Sliding Window Pattern" = @("Fixed Window Size", "Variable Window Size", "Max Sum Subarray Size K", "Longest Substring No Repeating", "Minimum Window Substring", "Longest Substring K Distinct", "Fruits Into Baskets", "Permutation in String", "Find All Anagrams", "Minimum Size Subarray Sum")
  "PROBLEM-SOLVING PATTERNS\Merge Intervals Pattern" = @("Merge Overlapping Intervals", "Insert Interval", "Interval List Intersections", "Meeting Rooms I and II", "Employee Free Time", "Non-Overlapping Intervals")
  "PROBLEM-SOLVING PATTERNS\Cyclic Sort Pattern" = @("Cyclic Sort", "Find Missing Number", "Find All Missing Numbers", "Find Duplicate Number", "Find All Duplicates", "Find Corrupt Pair")
  "PROBLEM-SOLVING PATTERNS\In-Place Reversal Pattern" = @("Reverse Linked List", "Reverse Sublist", "Reverse K-Group", "Reverse Alternating K Elements", "Rotate List")
  "PROBLEM-SOLVING PATTERNS\Tree BFS Pattern" = @("Level Order Traversal", "Reverse Level Order", "Zigzag Level Order", "Average of Levels", "Minimum Depth", "Level Order Successor", "Connect Level Order Siblings")
  "PROBLEM-SOLVING PATTERNS\Tree DFS Pattern" = @("Path Sum", "All Paths for a Sum", "Sum of Path Numbers", "Path With Given Sequence", "Count Paths for Sum")
  "PROBLEM-SOLVING PATTERNS\Top K Elements Pattern" = @("Top K Frequent Elements", "Kth Smallest Number", "K Closest Points to Origin", "Connect Ropes", "Top K Frequent Words", "Frequency Sort")
  "PROBLEM-SOLVING PATTERNS\K-Way Merge Pattern" = @("Merge K Sorted Lists", "Kth Smallest in M Sorted Arrays", "Smallest Range Covering K Lists", "Find K Pairs Smallest Sums")
  "PROBLEM-SOLVING PATTERNS\Binary Search Pattern" = @("Order-Agnostic Binary Search", "Ceiling of Number", "Next Letter", "Number Range", "Search in Infinite Array", "Minimum Difference Element", "Bitonic Array Maximum", "Search Bitonic Array")
  "PROBLEM-SOLVING PATTERNS\Monotonic Stack Pattern" = @("Next Greater Element", "Next Smaller Element", "Daily Temperatures", "Largest Rectangle in Histogram", "Maximal Rectangle")
  "PROBLEM-SOLVING PATTERNS\Prefix Sum Pattern" = @("Range Sum Query Immutable", "Range Sum Query 2D", "Subarray Sum Equals K", "Continuous Subarray Sum", "Product of Array Except Self")
  "PROBLEM-SOLVING PATTERNS\Modified Binary Search" = @("Search in Rotated Sorted Array", "Search in Rotated Sorted Array II", "Find Minimum in Rotated Array", "Search in 2D Matrix")
  "PROBLEM-SOLVING PATTERNS\Backtracking Patterns" = @("Subsets Power Set", "Permutations", "Combinations", "Combination Sum", "Palindrome Partitioning", "Letter Case Permutation")
  "System Design" = @("LRU Cache", "LFU Cache", "Design HashMap", "Design HashSet", "Design Twitter Feed", "Design File System", "Design Search Autocomplete")
}

Write-Host "Building Ordered DSA Workspace..." -ForegroundColor Cyan

$folderIdx = 1
$createdParents = @{}

foreach ($folderKey in $dsaStructure.Keys) {
    # Check if this is a nested pattern folder
    if ($folderKey -like "*\*") {
        $parts = $folderKey -split "\\"
        $parentName = $parts[0]
        $subName = $parts[1]

        # 1. Handle the Parent Folder (PROBLEM-SOLVING PATTERNS)
        # We give the PARENT a number so it stays in chronological order
        if (-not $createdParents.ContainsKey($parentName)) {
            $parentPrefix = $folderIdx.ToString("D2")
            $parentPath = Join-Path $basePath ("$parentPrefix`_$parentName")
            if (-not (Test-Path $parentPath)) {
                New-Item -Path $parentPath -ItemType Directory -Force | Out-Null
            }
            $createdParents[$parentName] = $parentPath
            $folderIdx++ # Increment only when a new top-level folder is created
        }

        # 2. Handle the Sub-Folder
        # We do NOT give the sub-folder a 01_, 02_ prefix unless you want them numbered inside
        $subFolderPath = Join-Path $createdParents[$parentName] $subName
        if (-not (Test-Path $subFolderPath)) {
            New-Item -Path $subFolderPath -ItemType Directory -Force | Out-Null
        }
        $targetPath = $subFolderPath
    }
    else {
        # Standard Top-Level Folder Logic
        $folderPrefix = $folderIdx.ToString("D2")
        $folderPath = Join-Path $basePath ("$folderPrefix`_$folderKey")
        if (-not (Test-Path $folderPath)) {
            New-Item -Path $folderPath -ItemType Directory -Force | Out-Null
        }
        $targetPath = $folderPath
        $folderIdx++
    }

    # Create the .cpp files inside the determined $targetPath
    $fileIdx = 1
    foreach ($topic in $dsaStructure[$folderKey]) {
        $cleanFileName = "$fileIdx." + ($topic -replace '[/\\?%*:|"<> ]', '_') + ".cpp"
        $filePath = Join-Path $targetPath $cleanFileName

        $content = ""
        Set-Content -Path $filePath -Value $content -Encoding UTF8
        $fileIdx++
    }
}

Write-Host "`n🚀 Workspace Built! Patterns are now grouped correctly." -ForegroundColor Yellow
