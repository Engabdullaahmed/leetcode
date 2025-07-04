class Solution {
public:
    int maxArea(vector<int>& height) {
       int ans = 0 ;
       int n = height.size();
       int width = 0 ;
       int height_ = 0 ;
        int r = n-1;
        int l = 0  ;
        if(n<=2)
        {
            height_ = min(height[r],height[l]);
            width = r-l;
            ans = width*height_;
        }
        else {
       for(int i = 0 ; i<n ;i++)
       {
        
        height_ = min(height[r],height[l]);
        width = r-l;
        ans= max(ans,width*height_);
        // if(height[l]<height[r])
        // {
        //     l++;     
        // }
        if(height[l]>height[r])
        {
            r--;
        }
        else{
            l++;
        }
       }
        }
       return ans ;
      
    }
};