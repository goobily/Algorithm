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
 ******unordered_map�������ʹ�õ�Ч�ʸ���map
 *
 *
 *map��unordered_map
 *1. �ڲ�ʵ�ֻ���
 *1.1. map:
 *map�ڲ�ʵ����һ���������������Ƿ��ϸ�ƽ���������������AVL���ϸ�ƽ�������������������������Զ�����Ĺ��ܣ����map�ڲ�������Ԫ�ض�������ģ��������ÿһ���ڵ㶼������map��һ��Ԫ�ء�
 *��ˣ�����map���еĲ��ң�ɾ������ӵ�һϵ�еĲ������൱���ǶԺ�������еĲ�����map�е�Ԫ���ǰ��ն���������������������������������������ص���������������нڵ�ļ�ֵ��С�ڸ��ڵ�ļ�ֵ��
 *���������нڵ�ļ�ֵ�����ڸ��ڵ�ļ�ֵ���洢�ģ�ʹ����������ɽ���ֵ���մ�С�������������
 *1.2. unordered_map:
 *unordered_map�ڲ�ʵ����һ����ϣ��Ҳ��ɢ�б�ͨ���ѹؼ���ֵӳ�䵽Hash����һ��λ�������ʼ�¼�����ҵ�ʱ�临�ӶȿɴﵽO(1)�����ں������ݴ��������Ź㷺Ӧ�ã�����ˣ���Ԫ�ص�����˳��������ġ�
 *
 *2. ��ȱ���Լ����ô�
 *2.1 map:
 *�ŵ㣺
 *�����ԣ�����map�ṹ�����ŵ㣬��Ԫ�ص��������ںܶ�Ӧ���ж���򻯺ܶ�Ĳ���
 *��������ڲ�ʵ��һ�������ʹ��map�ĺܶ������lgn��ʱ�临�Ӷ��¾Ϳ���ʵ�֣����Ч�ʷǳ��ĸ�
 *ȱ�㣺 �ռ�ռ���ʸߣ���Ϊmap�ڲ�ʵ���˺��������Ȼ���������Ч�ʣ�������Ϊÿһ���ڵ㶼��Ҫ���Ᵽ�游�ڵ㡢���ӽڵ�ͺ�/�����ʣ�ʹ��ÿһ���ڵ㶼ռ�ô����Ŀռ�

*���ô���������Щ��˳��Ҫ������⣬��map�����ЧһЩ
*
*2.2. unordered_map��
*�ŵ㣺 ��Ϊ�ڲ�ʵ���˹�ϣ�����������ٶȷǳ��Ŀ�
*ȱ�㣺 ��ϣ��Ľ����ȽϺķ�ʱ��
*���ô������ڲ������⣬unordered_map����Ӹ�ЧһЩ����������������⣬���ῼ��һ����unordered_map
*
*
*
 */