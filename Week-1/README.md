# 集训#1 
#### 2017-10-21

## 本周讲解主题
DFS, BFS

## 本周练习题目
- Lake Counting (POJ-2386 / p32)
- Shortest Path (p34)
- Noise Level (CF-847-I)
- Cities Excursions (CF-864-F)

## 题解
### Lake Counting
*File: lc.cpp*
简单搜索，DFS与BFS皆可（只实现了DFS），不多叙述

### Shortest Path
*File: maze.cpp*
经典迷宫最短路，BFS，不多叙述

### Noise Level
*File: 847i.cpp*
感觉比较有意思的一道题。通过对题意的理解可以看出来此题本质上依然是用 BFS 来解，对于每个噪音源遍历全图添加噪音值（步数相关）即可；另外需注意剪枝条件。

### Cities Excursions
*WIP*
图类问题苦手，还是要学习一个，待后日补充
