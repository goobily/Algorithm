refer: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/

这个算法是解决这样一个问题：从一个数组中找出出现半数以上的元素。

算法思想：
    遍历数组的时候维护一个数值对【majority：conut】，初始化为【？：0】，当我们向前遍历到元素 e 的时候：
如果 count == 0， 重置majority=e，count=1；
如果 count != 0，判断当前 e 是否等于majority，相等则count++, 否则 count--;
当我们遍历完整个数组的时候，majority即是超过半数的元素（如果存在这样的元素的话）

例子：https://leetcode.com/problems/majority-element/

int majorityElement(vector<int>& nums) {
	int majority = nums[0];
	int cnt = 0;
	for(int i=0; i<nums.size(); ++i) {
		if(cnt == 0) {
			majority = nums[i];
			cnt++;
		}
		else {
			nums[i] == majority ? cnt++ : cnt--;
		}
	}
	return majority;
}

算法的时间复杂度为O(n)，因为只遍历了一次数组；空间复杂度为O(1)，因为只用到了两个变量。