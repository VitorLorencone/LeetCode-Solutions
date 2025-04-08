/* 
Let n be the size of `nums`

Time Complexity: O(n*sum(nums))
Space Complexity: O(sum(nums))
*/

function canPartition(nums: number[]): boolean {
    let sum:number = nums.reduce((s, cur) => s + cur, 0);

    if (sum % 2 !== 0)
        return false;

    let mid:number = sum / 2;

    let dp: boolean[] = new Array(mid + 1).fill(false);
    dp[0] = true;

    for (let num of nums){
        for (let i = mid; i >= num; i--){
            dp[i] = dp[i] || dp[i - num];
        }
        if (dp[mid])
            return true;
    }
    return dp[mid];
};

let problem = [1, 5, 11, 5];
console.log(canPartition(problem));