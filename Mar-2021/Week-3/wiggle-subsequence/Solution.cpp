class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int N, i = 1, len = 1;
        bool greater;

        N = nums.size();

        while (i < N && nums[i] == nums[i - 1])
        {
            i++;
        }
        if (i == N)
        {
            return 1;
        }
        greater = nums[i - 1] > nums[i];
        for (; i < N; i++)
        {
            if ((greater && nums[i] < nums[i - 1]) || (!greater && nums[i] > nums[i - 1]))
            {
                greater = !greater, len++;
            }
        }
        return len;
    }
};
