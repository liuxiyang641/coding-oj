#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

// 快速排序
// 与合并排序相比，由于通过寻找合适的p，左边区间都比p小，右边区间都比p大，因此没有合并过程。
void quick_sort(int *nums, int l, int r)
{
    // 如果只剩两个数，说明已经排好序，那么返回
    if (l+1>=r) return;
    // 随机挑选一个值，并且与最左边的值互换，避免最糟糕的情况
    srand(0);
    int rand_init_pos = rand() % (r - l) + l;
    int tmp = nums[l];
    nums[l] = nums[rand_init_pos];
    nums[rand_init_pos] = tmp;
    // 从左右两边开始搜索，寻找适合p的位置
    // 初始化的时候，i就位于p的位置上，i总是满足划分规则的，j从最右边开始
    int i = l, j = r - 1;
    int p = nums[l];

    while(i<j)
    {
        // 由于快速排序的轴pivot是从最左边开始寻找的，那么把这个值挖出来，之后要填充的数字应该是小于p的，所有从右边开始寻找小于p的值
        while(nums[j]>=p && i<j) 
        {
            --j;
        }
        // 把小于p的值填到左边
        nums[i] = nums[j];
        while(nums[i]<=p && i<j)
        {
            ++i;
        }
        // 把大于p的值填到右边
        nums[j] = nums[i]; 
    }
    // 把p填回去
    nums[i] = p;
    quick_sort(nums, l, i);
    quick_sort(nums, i+1, r);
}

// 归并排序
// 将nums数组从中间分成两部分，将两部分分别排好序，然后合并
void merg_sort(int * nums, int l, int r, int * tmp)
{
    if(l==r) 
        return;
    int mid = l + (r-l)/2;
    merg_sort(nums, l, mid, tmp);
    merg_sort(nums, mid+1, r, tmp);
    // 开始合并，nums数组的l-mid和mid+1-r已经排好序。
    int i = l, j = mid+1, k = l;
    while(i<=mid || j<=r)
    {
        // 当右边区间都取完值，或者左边区间数值比右边区间数值小的时候，取左边数值
        if ( (j>r) || (i<=mid && nums[i]<=nums[j]) )
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }
    // tmp数组暂时保存排好序的序列，这时返回给nums数组
    for(int i = l;i<=r;++i)
    {
        nums[i] = tmp[i];
    }
}

// 插入排序
// 插入的意思就是把新数字插入到一个已经排好序的数组，每次来新的数字后，从大到小的寻找合适的位置插入，在寻找合适位置的时候，如果是比新数字大的，就可以往后移动
void insert_sort(int * nums, int r)
{
    for(int i = 1;i<r;++i)
    {
        // 取出新的位置的数字
        int current_value = nums[i];
        int position = i;
        while(position > 0 && current_value<nums[position-1])
        {
            nums[position] = nums[position-1];
            position--;
        }
        nums[position] = current_value;
    }
}

// 选择排序
// 选择当前没有排好序的数组中最大或者最小的值
void selection_sort(int *nums, int r)
{
    for (int i = 0; i < r; ++i )
    {
        int min_pos = i, min_value = nums[i];
        for (int j = i+1; j<r; ++j)
        {
            if (nums[j]<min_value)
            {
                min_value = nums[j];
                min_pos = j;
            }
        }
        nums[min_pos] = nums[i];
        nums[i] = min_value;
    }
}

// 冒泡排序
void buble_sort(int* nums, int r)
{
    int tmp_val;
    // 对冒泡排序的一个改进
    bool swap_flag = false;
    while(r>1)
    {
        for(int i = 1; i<r; ++i)
        {
            tmp_val = nums[i];
            if(nums[i]<nums[i-1])
            {
                nums[i] = nums[i-1];
                nums[i-1] = tmp_val;
                swap_flag = true;
            }
        }
        r--;
        if (swap_flag==false)
        {
            // 没有互换元素，说明此时的数组都已经排好序了
            return;
        }
        swap_flag = false;
    }
}

int main(int argc, char** argv)
{
    while(true)
    {
        int n;
        scanf("%d", &n);
        int * nums = (int *)malloc(n*sizeof(int));
        for(int i = 0;i<n;++i)
        {
            scanf("%d", &nums[i]);
        }
        // 1. 快速排序
        // quick_sort(nums, 0, n);
        // 2. 归并排序
        // int * tmp = (int *)malloc(n*sizeof(int));
        // merg_sort(nums, 0, n-1, tmp);
        // free(tmp);
        // 3. 插入排序
        // insert_sort(nums, n);
        // 4. 选择排序
        // selection_sort(nums, n);
        // 5. 冒泡排序
        // buble_sort(nums, n);
        // 6. 使用c++中的sort函数，
        // sort函数头文件是<algorithm>，输入参数有三个，起始地址，数组尾地址，以及如何判断哪个元素排在前面，默认是小的元素排在前面
        sort(nums, nums+n);
        for(int i = 0;i<n;++i)
        {
            printf("%d\t", nums[i]);
        }
        printf("\n");
        free(nums);
    }
    return 0;
}