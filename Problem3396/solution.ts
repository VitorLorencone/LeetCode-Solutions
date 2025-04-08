/* 

Let n be the size of `nums`

Time Complexity: O(n^2)
Space Complexity: O(n)

*/

function minimumOperations(nums: number[]): number {
    const hashTable = new Map<number, number>();

    for(const num of nums){
        if(hashTable.has(num)){
            nums = nums.slice(3);
            return 1 + minimumOperations(nums);
        }else{
            hashTable.set(num, 0);
        }
    }
    return 0;
};

let problem = [1,2,3,4,2,3,3,5,7];
console.log(minimumOperations(problem)); // 2