// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        vector<vector<string>> ans;
//        unordered_map<string,vector<string>> seen;
//        for(int i=0;i<strs.size();i++)
//        {
//            string s=strs[i];
//            sort(s.begin(),s.end());
//            seen[s].push_back(strs[i]);
//        }
//        for(auto it=seen.begin();it!=seen.end();++it)
//        {
//            ans.push_back(it->second);
//        }
//        return ans;
//     }
// };