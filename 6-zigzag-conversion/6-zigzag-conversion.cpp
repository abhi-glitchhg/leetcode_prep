class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows == 1)
      return s;
      
    vector<string> res(numRows, "");
    res[0] = s[0];
      
    int i = 1;
    int j = 1;
      
    while (i < s.size())
    {
      for (j=1; j < numRows; j++)
      {
        if (i == s.size())
          break;
        res[j] += s[i];
        i++;
      }

      for (j = numRows - 2; j > -1; j--)
      {
        if (i == s.size())
          break;
          
        res[j] += s[i];
        i++;
      }
        
        if(i == s.size())
            break;
    }

      string a = "";
    for (string bug : res)
        a += bug;
      
      return a;
  }
};