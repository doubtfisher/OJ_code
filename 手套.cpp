题目：
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。



//这道题的思路是：找其中一个颜色能全覆盖的最小值，最后再加上落单的
class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        //要注意的是一个数组中的最小值不能初始化为0，这是一个坑，可以初始化的方式为：初始化为int的最大值
       int leftsum=0,l_min=INT_MAX;
       int rightsum=0,r_min=INT_MAX;
       int sum=0;
       for(int i=0;i<n;i++)
       {
           if(left[i]*right[i]==0)
           {
               sum+=left[i]+right[i];
           }
           else
           {
               leftsum+=left[i];
               rightsum+=right[i];
               l_min=min(l_min,left[i]);
               r_min=min(r_min,right[i]);
           }
       }
        //最后加1，是因为我们只选取了能全覆盖的一个数组中的所有数，另外一个数组至少要再取一个手套
        int ret=sum+min(leftsum-l_min+1,rightsum-r_min+1)+1;
        return ret;
    }
};