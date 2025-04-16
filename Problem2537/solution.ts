/* 
Let n be the size of `nums`

Time Complexity: O(n)
Space Complexity: O(n)

Simple solution with sliding window
*/

function countGood(nums: number[], k: number): number {
    const n = nums.length;
    let count = 0,
        r = -1;
    const cnt = new Map<number, number>();
    let ans = 0;
    for (let l = 0; l < n; ++l) {
        while (count < k && r + 1 < n) {
            ++r;
            count += cnt.get(nums[r]) || 0;
            cnt.set(nums[r], (cnt.get(nums[r]) || 0) + 1);
        }
        if (count >= k) {
            ans += n - r;
        }
        cnt.set(nums[l], (cnt.get(nums[l]) || 0) - 1);
        count -= cnt.get(nums[l]) || 0;
    }
    return ans;
}

let problem = [3,1,4,3,2,2,4];
let k = 2;
console.log(countGood(problem, k)); // 4