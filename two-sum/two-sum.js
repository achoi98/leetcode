/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let map = {};
    
    for (let i = 0; i < nums.length; i++) {
        const n = nums[i];
        if (map[target - n] !== undefined) {
            return [map[target - n], i];
        }
        map[n] = i;
    }
    return [];
};