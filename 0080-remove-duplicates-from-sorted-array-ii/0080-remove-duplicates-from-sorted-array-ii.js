/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let n = nums.length;
    let element = nums[0];
    let itr= 1
    let allowedDupes = 2;
    let dupes = 1;
    for(let i=1; i<n; i++){
        if(nums[i] !== element){
            dupes = 1;
            element = nums[i];
            nums[itr++] = element;
        }
        else {
            if(dupes<allowedDupes){
                dupes++;
                nums[itr++] = element;
            }
        }
    }

    return itr;
};