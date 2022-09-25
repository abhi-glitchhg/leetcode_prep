class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> ans;
        vector<vector<string>> a;
        for (auto i : paths){
            string root;
            string files_n_content;
            string file;
            string content;
            stringstream ss(i);
             getline(ss, root,' ');
             while(getline(ss, files_n_content, ' ' ))
             {    
                 stringstream ff(files_n_content);
                 getline(ff,file,'(');
                 getline(ff,content,')');
                 ans[content].push_back(root+"/" + file);            
             }
        }
        for (auto i:ans)
            if (i.second.size()>1)
                a.push_back(i.second);
        return a;
    }
};