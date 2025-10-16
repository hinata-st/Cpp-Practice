<h1 style="color:blue;">by Emilia-tan</h1>

❌❌✅✅

|题目序号|知识点|难度|记录|
|:----|:--------:|:-----:|:--------:|
|offer.03|哈希集合查找|easy|10/13✅|
|offer.04|二维二分查找|easy|10/13✅|
|offer.05|字符串替换|easy|10/13✅|
|offer.06|链表倒序输出|easy|10/14✅|
|offer.07|重建二叉树(分治+哈希)|middle|10/14❌,10/15✅|
|offer.08|两个栈实现一个队列|easy|10/15✅|
|offer.10-I|斐波那契数列|easy|10/15✅|
|offer.10-2|跳楼梯(dp)|easy|10/16✅|
|offer.11|选择数组最小数字(二分)|easy|10/16✅|

**编译** 
`g++ -o rebuildTree 07.cpp -std=c++14 -O2 -Wall -fexec-charset=GBK`

|选项|说明|
|:---|:----|
|`-o rebuildTree`|出可执行文件名为 `rebuildTree.exe`|
|`07.cpp`|源文件|
|`-std=c++14`|使用 C++14 标准（支持 lambda 捕获等特性）|
|`-O2`|优化级别 2（平衡编译速度和性能）|
|`-Wall`|显示所有警告信息|
|`-fexec-charset=GBK`|设置输出字符集为 GBK（Windows 控制台）|


**message**
```
<type>(<scope>): <subject>

<body>

<footer>
```
**模板**
```
git commit -m "feat(offer): 完成 offer.XX 题目

- 题目：题目名称
- 知识点：相关算法/数据结构
- 难度：easy/middle/hard
- 状态：✅ 通过 / ❌ 待优化"
```
|Type|使用场景|示例|
|:----|:-----|:-----|
|`feat`|完成新题目|`feat(offer): 完成 offer.10`|
|`fix`|修复题目错误|`fix(offer): 修复 offer.07 边界问题`|
|`refactor`|优化代码|`refactor(offer): 优化哈希表实现`|
|`docs`|更新笔记|`docs: 更新刷题进度`|
|`perf`|性能优化|`perf(offer): 优化时间复杂度`|
|`test`|添加测试|`test: 添加边界测试用例`|
|`chore`|工具配置|`chore: 更新编译选项`|
