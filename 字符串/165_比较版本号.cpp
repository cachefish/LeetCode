/*
165. 比较版本号
比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。
你可以假设版本字符串非空，并且只包含数字和 . 字符。
 . 字符不代表小数点，而是用于分隔数字序列。
例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。
你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）
和第二级（小版本）修订号分别为 3 和 4。其第三级和第四级修订号均为 0。
*/
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> get_num(string version)
    {
        vector<int> res;
        for(int i =0;i<version.size();i++)
        {
            int j =i,s =0;
            while(j<version.size()&&version[j]!='.')
            {             
                
                s =s*10+version[j]-'0';
                j++;
            }
            i =j;
            res.push_back(s);
        }
        while(res.size()&&res.back()==0) res.pop_back();
        return res;
    }

    int compareVersion(string version1, string version2) {
        auto n1 = get_num(version1);
        auto n2 = get_num(version2);
        if(n1<n2) return -1;
        if(n1==n2) return 0;
        return 1;
    }
};