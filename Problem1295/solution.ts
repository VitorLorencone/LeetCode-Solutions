/* 
Let n be the size of `nums`

Time Complexity: O(n)
Space Complexity: O(1)

*/

function findNumbers(nums: number[]): number {
    let count:number = 0;
    for(let i = 0; i <= nums.length; i++){
        if ((Math.floor(Math.log10(nums[i]))+1) % 2 == 0) {
            count += 1;
        }
    }
    return count;
};