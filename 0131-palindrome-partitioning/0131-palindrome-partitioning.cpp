class Solution {
public:
    bool isPalindrome(string s)
    {
        int st = 0;
        int ed = s.size()-1;

        while(st <= ed)
        {
            if(s[st] != s[ed])
            {
                return false;
            }
            st++; ed--;
        }
        return true;
    }

    void getAllParts(string s, vector<vector<string>>& ans, vector<string>& temp)
    {
        if(s.size() == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < s.size(); i++)
        {
            string part = s.substr(0, i+1);
            if(isPalindrome(part))
            {
                temp.push_back(part);
                getAllParts(s.substr(i+1), ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        getAllParts(s, ans, temp);

        return ans;
    }
};