//brute force:
sort(intervals.begin(), intervals.end());

vector<vector<int>> ans;

for (int i = 0; i < intervals.size(); i++) {

    int start = intervals[i][0];
    int end = intervals[i][1];

    // Skip intervals that have already been merged
    if (!ans.empty() && end <= ans.back()[1])
        continue;

    for (int j = i + 1; j < intervals.size(); j++) {

        if (intervals[j][0] <= end) {
            end = max(end, intervals[j][1]);
        } else {
            break;
        }
    }

    ans.push_back({start, end});
}

return ans;

//optimal approach:

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0],intervals[0][1]});
        for (int i = 0; i < n; i++){
            if(ans.back()[1]>=intervals[i][0]){
                ans.back()={ans.back()[0],max(ans.back()[1],intervals[i][1])};
            }else{
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return ans;
    }
};