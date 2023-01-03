class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        int negativeCount = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] < 0)
                negativeCount++;
            else
                break;

        if(negativeCount == 0) {
            if(k % 2 != 0) 
                nums[0] *= -1;
            return vectorSum(nums);
        }
        else if(negativeCount >= k) {
            for(int i = 0; i < k; i++)
                nums[i] *= -1;
            return vectorSum(nums);
        }
        else if(negativeCount < k) {
            for(int i = 0; i < negativeCount; i++)
                nums[i] *= -1;

            k -= negativeCount;

            int min=nums[0], minIndex = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] < min) {
                    min = nums[i];
                    minIndex = i;
                }
            }
            
            if(k % 2 != 0) 
                nums[minIndex] *= -1;
        }
        return vectorSum(nums);
    }

    int vectorSum(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        return sum;
    }

};