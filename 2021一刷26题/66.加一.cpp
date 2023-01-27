/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

    // OverFlow
        // for(int i=0; i < digits.size(); i++) {
        //     if(i==digits.size()-1) {
        //         if(digits[i]!=9) {
        //             digits[i]++;
        //         }
        //         else {
        //             digits[i] = 0;
        //             while (digits[i-1]==9) {
        //                 digits[i-1] = 0;
        //                 i--;
        //             }
        //             digits[i-1]++;   
        //             digits[digits.size()-1]=0;                  
        //         }
        //     }
        // }
        
        for (int i = digits.size() - 1; i >= 0; i--) {
			if (digits[i] != 9) {
                digits[i]++;
				return digits;
			} 
			digits[i] = 0;
		}
        // 跳出循环，说明数字全部是9
		vector<int> newdigits(digits.size()+1);
		newdigits[0] = 1;
        return newdigits;
    }
};
// @lc code=end

