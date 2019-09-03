#include <vector>
#include <unordered_map>

using namespace std;
/*
 * 1. Two Sum
Easy

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
 */

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> record;
    for (int i = 0; i<nums.size(); ++i)
    {
        int anotherValue = target - nums[i];
        if(record.find(anotherValue) != record.end())
        {
            res = vector<int>({ record[anotherValue], i });
            return res;
        }
        record[nums[i]] = i;
    }
    return res;
}

int main()
{
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> res = twoSum(nums, target);
}

/*
 ******unordered_map在这里的使用的效率高于map
 *
 *
 *map和unordered_map
 *1. 内部实现机理
 *1.1. map:
 *map内部实现了一个红黑树（红黑树是非严格平衡二叉搜索树，而AVL是严格平衡二叉搜索树），红黑树具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素。
 *因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行的操作。map中的元素是按照二叉搜索树（又名二叉查找树、二叉排序树，特点就是左子树上所有节点的键值都小于根节点的键值，
 *右子树所有节点的键值都大于根节点的键值）存储的，使用中序遍历可将键值按照从小到大遍历出来。
 *1.2. unordered_map:
 *unordered_map内部实现了一个哈希表（也叫散列表，通过把关键码值映射到Hash表中一个位置来访问记录，查找的时间复杂度可达到O(1)，其在海量数据处理中有着广泛应用）。因此，其元素的排列顺序是无序的。
 *
 *2. 优缺点以及适用处
 *2.1 map:
 *优点：
 *有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作
 *红黑树，内部实现一个红黑书使得map的很多操作在lgn的时间复杂度下就可以实现，因此效率非常的高
 *缺点： 空间占用率高，因为map内部实现了红黑树，虽然提高了运行效率，但是因为每一个节点都需要额外保存父节点、孩子节点和红/黑性质，使得每一个节点都占用大量的空间

*适用处：对于那些有顺序要求的问题，用map会更高效一些
*
*2.2. unordered_map：
*优点： 因为内部实现了哈希表，因此其查找速度非常的快
*缺点： 哈希表的建立比较耗费时间
*适用处：对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map
*
*
*
 */