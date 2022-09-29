class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        {
        if (k==arr.size()) return arr;
        map<int, vector<int>> mapping;
        vector<int> diff;
        
        for (auto i: arr)
            diff.push_back(abs(i-x));
        
        for (int i=0; i<arr.size(); i++)
            mapping[diff[i]].push_back(arr[i]);
        diff.clear();
        int pointer =0;
        bool break_flag = false;
        
        for (auto i: mapping){
            for (auto j :i.second){
                diff[pointer] = j;
                pointer++;
                if (pointer ==k)
                {break_flag=true; break;}
            }
            if(break_flag) break;
        }
        sort(diff.begin(), diff.begin()+k);
        return vector(diff.begin(), diff.begin()+k);
    }
    }
    };  