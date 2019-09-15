class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size()+nums2.size();
        bool isodd = (n%2==1);

        int tar1, tar2;
        if(isodd) tar1 = int(n/2)+1;
        else {
            tar1= n/2;
            tar2= n/2+1;
        }
        
        int i=0;
        int j=0;       
        
        int out1=0;
        int out2=0;
        if(isodd){
            while(i+j<=tar1){
                if((i+j) == tar1) out1= nums1[i]<nums2[j]?nums1[i]:nums2[j];
                  
                if(nums1[i]<=nums2[j]) i++;
                else j++;
            }
            cout<<"is odd:"<<out1<<endl;       
            return out1;
        }
        else{
            while(i+j<=tar2){
               if((i+j) == tar1) out1= nums1[i]<nums2[j]?nums1[i]:nums2[j];  
               if((i+j) == tar2) out2= nums1[i]<nums2[j]?nums1[i]:nums2[j]; 
               if(nums1[i]<=nums2[j]) i++;
               else j++;
            }
            cout<<"is even:"<<out1<<" "<<out2<<endl;
            return double(out1+out2)/2;
        }
    }
};

int main(){

    vector<int> a={2,4,6,7,10,12,};
    vector<int> b={1,5,8,9,11,19};

    Solution s=Solution();
    double k = s.findMedianSortedArrays(a,b);
    cout<<k<<endl;
    return k;
}
