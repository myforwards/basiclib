# Longest-Increasing-Subsequence
also called LIS for short.

## 2018/10/25 12:10 (UTC+8) China
**最长连续子序列 O(nlogn)**

*define*

```cpp
const int seqSize;
int s[seqSize];                 //原序列。
    lis[seqSize]                //长度为i的子序列的最小尾值。
    {
        memset(lis,0x77,sizeof(lis);
        lis[0]=0x00000000;      //长度至少为1，因此lis[0]无意义。
    };     
```

根据定义，我们可以得知：lis一定是一个递增(increasing)的序列。可用反证法证明：设逆命题i<j，lis[i]>lis[j]。则一定存在一个长度为j尾值为lis[j]的子序列。这个序列的后i个元素构成一个长度为i的子序列，因此lis[i]必定不大于lis[j]，与逆命题矛盾，正命题得证。

*process*

接下来的操作是从序列头到序列尾部的动态规划。对于每一个元素i，我们在lis中找到最后一个不大于i的元素lis[j]，j+1就是一个以i结尾的最长连续子序列的长度。于是我们得到了一个新的答案lis[j+1]=i，根据性质（lis一定是一个递增(increasing)的序列。），[&lis[0],&lis[j]]区间内的所有元素都应该更新为它本身和lis[j-1]的较小值。如此，我们就完成了对lis动态地维护。

```cpp
#include<algorithm>
void function1(int *_B,int *_E)
{
    using std::min;
    using std::upper_bound;
    for(int *i=_B;i<_E;i++)
    {
        int *_U=upper_bound(lis,lis+seqSize,*i);
        *_U=min(*_U,*i);
        for(int *j=lis;j<_U;j++) {*j=min(*j,*_U);}
    }
    return;
}
```

当我们完成对序列所有元素的动态规划后，答案是显而易见的。

```cpp
int function2()
{
    for(int i=1;i<seqsize;i++)
    {
        if(lis[i]==0x77777777) {return i-1;}
    }
}
```

时间复杂度为O(nlogn)。
