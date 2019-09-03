/*
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

    例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

    满足要求的三元组集合为：
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]

 */

/*
 * 排序思路：
 * 1.首先对nums数组从小到大排序。
 * 2.然后利用 i 对nums进行遍历，相当于暂时固定 i ,而 j , k 在 i+1 ~ nums.size()-1 中选择
 * 情况1：当nums[i] + nums[j] + nums[k] > 0 时，因为 nums[k-1] < num[k],所以 k--
 * 情况2：当nums[i] + nums[j] + nums[k] < 0 时，因为 nums[j+1] > num[j],所以 j++
 * 但这两情况都有前提 j < k
 * 3.优化, 如果在对 i 的遍历过程，nums[i]已经大于0，那么因为 j,k 必然大于i，且这是排序数组，肯定不符合题目要求, 直接返回
 * 如果nums[j] == nums[j+1] 和 nums[i] == nums[i+1]这 两种相邻元素重复情况，利用while循环跳过。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    if(nums.size() < 3)
    {
        return result;
    }

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for(int i = 0; i < n-2; i++)
    {
        // skip the duplication
        if(i>0 && nums[i] == nums[i-1])
        {
            continue;
        }

        int a = nums[i];
        int low = i + 1;
        int high = n - 1;

        while( low < high)
        {
            int b = nums[low];
            int c = nums[high];

            if(a + b + c == 0)
            {
                //got the solution
                result.push_back({ a, b, c });

                //skip the duplication
                while(low < n - 1 && nums[low] == nums[low + 1]) low++;
                while (high > 0 && nums[high] == nums[high - 1]) high--;

                low++;
                high--;
            }
            else if(a + b + c < 0)
            {
                //move low right
                //skip the duplication
                while (low < n - 1 && nums[low] == nums[low + 1]) low++;
                low++;
            }
            else if(a + b + c > 0)
            {
                //move high left
                //skip the duplication
                while (high > 0 && nums[high] == nums[high - 1]) high--;
                high--;
            }
        }
    }
    return result;
}

void printMatrix(vector<vector<int> > &matrix)
{
    for (int i = 0; i<matrix.size(); i++) {
        printf("[");
        for (int j = 0; j< matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("]\n");
    }
    cout << endl;
}

int main()
{
    //int a[] = {-1, 0, 1, 2, -1, 1, -4};
    int a[] = { -1, 1, 1, 1, -1, -1, 0,0,0 };
    vector<int> n(a, a + sizeof(a) / sizeof(int));
    vector< vector<int> > result = threeSum(n);
    printMatrix(result);

    system("pause");
    return 0;
}