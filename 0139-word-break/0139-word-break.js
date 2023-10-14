/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    let wordSet = new Set(wordDict);

    let dp = Array(s.length + 1).fill(false);
    dp[0] = true;

    for(let i =1; i<s.length+1; i++){
        for(let j = i; j>=1; j--){
            if(dp[j-1]){
                let subString = s.substring(j-1,i);
                if (wordSet.has(subString)) dp[i] = true
            }

        }
    }

    return dp[s.length]
};