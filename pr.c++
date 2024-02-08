// class Solution {
// public:
//     static bool cmp(pair<int,int> a,pair<int,int> b)
//     {
//         if(a.second==b.second)
//         {
//             return a.first<b.first;
//         }
//         return a.second<b.second;
//     }
//     int maxEvents(vector<vector<int>>& events)
//     {
//         vector<pair<int,int>> ans;
//         for(int i=0;i<events.size();i++)
//         {
//             pair<int,int> p=make_pair(events[i][0],events[i][1]);
//             ans.push_back(p);
//         }
//         sort(ans.begin(),ans.end(),cmp);
//         int count=0;
//         unordered_map<int,bool> seen;
//         for(int i=0;i<ans.size();i++)
//         {
//             if(!seen[ans[i].first])
//             {
//                 count++;
//                 seen[ans[i].first]=true;
//             }
//             if(!seen[ans[i].second])
//             {
//                 count++;
//                 seen[ans[i].second]=true;
//             }
//         }
//         if(count>ans.size())
//         {
//             return count-1;
//         }

//         return count;
//     }
// };