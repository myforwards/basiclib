# Longest-Increasing-Subsequence
also called LIS for short.

## 2018/10/25 12:10 (UTC+8) China
**最长连续子序列 O(nlogn)**

*define*
```cpp
const int seqSize;
int s[seqSize];     //原序列
    lis[seqSize]        //长度为i的子序列的最小尾值
    {
        memset(lis,0,sizeof(lis);
    };     
```

根据定义，我们可以得知：lis一定是一个递增(increasing)的序列。可用反证法证明：设逆命题i<j，lis[i]>lis[j]。则一定存在一个长度为j尾值为lis[j]的子序列。这个序列的后i个元素构成一个长度为i的子序列，因此lis[i]必定不大于lis[j]，与逆命题矛盾，正命题得证。
