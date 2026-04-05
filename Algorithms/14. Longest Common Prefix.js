var longestCommonPrefix = function(strs) {

    let minLen = Math.min(...strs.map(s => s.length));

    let prefix = "";

    for(let pos = 0; pos < minLen; pos++){

        let current = strs[0][pos];

        for(let i = 1; i < strs.length; i++){
            if(strs[i][pos] !== current){
                return prefix;
            }
        }

        prefix += current;
    }

    return prefix;
};
