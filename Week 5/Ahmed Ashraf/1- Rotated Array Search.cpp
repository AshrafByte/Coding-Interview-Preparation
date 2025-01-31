class Solution
{
public:
    vector<int> nums;
    int target;

    int search(vector<int> &nums, int target)
    {
        this->nums = nums;
        this->target = target;
        return search(0, nums.size() - 1);
    }

    int search(int left, int right)
    {
        if (left > right)
            return -1;

        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
                return search(left, mid - 1);
            else
                return search(mid + 1, right);
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
                return search(mid + 1, right);
            else
                return search(left, mid - 1);
        }
    }
};
