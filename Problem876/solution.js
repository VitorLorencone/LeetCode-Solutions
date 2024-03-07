/* 
Let n be s.length

Time Complexity: O(n)
Space Complexity: O(1)

A solution using two pointers algorithm.
*/

/**
 * @param {string} s
 * @return {number}
 */
var minimumLength = function(s) {
    let p = 0;
    let q = s.length-1;
    for(let i = 0; i < s.length; i++){
        if(s[p] == s[q] && q > p){
            let letter = s[p]
            p += 1;
            q -= 1;
            while((s[p] == letter || s[q] == letter) && q > p){
                if(s[p] == letter){p += 1;}
                if(s[q] == letter){q -= 1;}
                if(q == p && s[p] == letter){p += 1;}
            }
        }else{break;}
    }
    return q - p + 1;
};

let str = 'aabccabba'
console.log(minimumLength(str))