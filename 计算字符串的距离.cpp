��Ŀ��
Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭������������ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ����༭������㷨�������ɶ����ѧ��Levenshtein����ģ����ֽ�Levenshtein Distance��
�ַ���A:abcdefg
�ַ���B: abcdef
ͨ�����ӻ���ɾ���ַ���g���ķ�ʽ�ﵽĿ�ġ������ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣
Ҫ�󣺸������������ַ�����д��һ���㷨�������ǵı༭���롣

������
��������Ǳ��˷����ģ�����˼·ͦ�����ģ����һ�£�
/* �ַ���֮��ľ��룬�༭���룬��strA�༭��strB�������С����
         * �༭������������һ���ַ���ɾ��һ���ַ����滻һ���ַ�
         * �ֱ��Ӧ�Ĵ�����ic��dc��rc
         * strA[x-1]����strA�ĵ�x���ַ���ע���±��Ǵ�0��ʼ��,strA[y-1]����strA�ĵ�y���ַ�
         * ����һ�����۾���Ϊ(N+1)*(M+1)��M N ��ʾstrA strB�ĳ���
         * dp[x][y]��ʾstrA��ǰx���ַ����༭�� strB��ǰy���ַ������ѵĴ���
         * dp[x][y]�����漸��ֵ����Сֵ��
             * 1��dp[x][y] = dp[x-1][y] + dc
             * dp[x-1][y]��strA��ǰx-1���ַ��༭��strB��ǰy���ַ��Ĵ�����֪��
             * ��ô����strA��ǰx���ַ��༭��strB��ǰy���ַ��Ĵ���dp[x][y]����dp[x-1][y] + dc
             * �൱��strA��ǰx-1���ַ��༭��strB��ǰy���ַ������ڱ����strA��ǰx���ַ���������һ���ַ���Ҫ����ɾ������
             * 2��dp[x][y] = dp[x][y-1] + ic
             * dp[x][y-1]��strA��ǰx���ַ��༭��strB��ǰy-1���ַ��Ĵ�����֪��
             * ���ڱ�ΪstrB��ǰy���ַ�����Ӧ����strAǰx���������۵Ļ����ϲ���һ���ַ�
             * 3��dp[x][y] = dp[x-1][y-1]
             * dp[x-1][y-1]��strA��ǰx-1���ַ��༭��strB��ǰy-1���ַ��Ĵ�����֪��
             * strA�ĵ�x���ַ���strB�ĵ�y���ַ���ͬ��strA[x-1] == strB[y-1]��û���������
             * 4��dp[x][y] = dp[x-1][y-1] + rc
             * strA�ĵ�x���ַ���strB�ĵ�y���ַ�����ͬ��strA[x-1] ��= strB[y-1]��
             * ��strA��ǰx-1���ַ��༭��strB��ǰy-1���ַ��Ĵ�����֪������£�
             * ������strA��ǰx�ַ��༭��strB��ǰy���ַ��Ĵ�����Ҫ�����滻һ���ַ��Ĵ���
         */

ʵ�ִ������£�

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//ʹ�ö�̬�滮˼��
// ��̬�滮���̣�dp(i,j) =min{dp(i-1,j��+1, dp(i,j-1) +1, dp(i-1,j-1) +(w1[i]==w2[j]?0:1)}

int minDistance(string str1,string str2)
{
    // �ַ�����մ�֮��ı༭����Ϊ���ַ����ĳ���
    if(str1.empty()||str2.empty())
        return max(str1.size(),str2.size());
   
    int len1=str1.size();
    int len2=str2.size();
  //��ʼ����ά����
    vector<vector<int> > dp(1+len1,vector<int>(1+len2,0));
    for(int i=0;i<=len1;i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<=len2;i++)
    {
        dp[0][i]=i;
    }
    
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])//�ж�str1�ĵ�i���ַ��Ƿ���str2�ĵ�j���ַ����
            {
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                // �ַ���ȣ�dp(i-1,j-1)�༭���벻��
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                // �ַ�����ȣ�dp(i-1,j-1)�༭����+1
                dp[i][j]=min(dp[i][j],1+dp[i-1][j-1]);
            }
        }
    }
    return dp[len1][len2];
}

int main()
{
   string s1,s2;
   while(cin>>s1>>s2)
   {
       cout<<minDistance(s1,s2)<<endl;
   }
   return 0;
}