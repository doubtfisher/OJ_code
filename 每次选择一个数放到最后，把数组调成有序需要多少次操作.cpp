题目：
度度熊有一个N个数的数组，他想将数组从小到大 排好序，但是萌萌的度度熊只会下面这个操作：任取数组中的一个数然后将它放置在数组的最后一个位置。问最少操作多少次可以使得数组从小到大有序？


思路分析：
因为给定的数组是无序的，如果直接有序的话，就不知道要移动几次才能变成有序，所以使用map让数组中的每个数和它对应的下标形成映射关系，然后再给数组进行排序，虽然排过序了，但是映射关系并没有变，所以就再次遍历排序后的数组，看map的val值即数的下标是否满足m[v[i]]<m[v[i+1]],如果不满足，调整次数就+1.

代码实现：

#include<map>
#include<vector>

#include<algorithm>

using namespace std;

int main()
  
{
     
	int n,temp;
   
	cin>>n;
  
	vector<int> v;
     
	map<int,int> m;
    
	for(int i=0;i<n;i++)
    
	 { 
		 cin>>temp;
         
		 v.push_back(temp);
         
		 m[temp]=i;
  
	  }
   
	  sort(v.begin(),v.end());
	  int t=n,count=0;
   
	  for(int i=0;i<n-1;i++)
 
	   {
      
		if (m[v[i]]>m[v[i+1]])
 
	               {
                 
			m[v[i+1]]=t++;
 
		                count++;
   
		}
   
	    }
    
	   cout<<count<<endl;

}
