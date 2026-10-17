class Solution {
public:
int Hrowindex(vector<vector<int>>& mat,int n,int m ,int col){
    int index = -1;
    int maxi = -1;
    for(int i= 0;i<n;i++){
        if(mat[i][col]>maxi){
            maxi = mat[i][col];
            index = i;
        }
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int rowindex = Hrowindex(mat,n,m,mid);
            int left = mid-1>=0 ? mat[rowindex][mid-1]:-1;
            int right = mid+1<m ? mat[rowindex][mid+1]:-1;
            if(mat[rowindex][mid]>left && mat[rowindex][mid]>right){
                return {rowindex,mid};
            }
            else if(mat[rowindex][mid]<left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }


        }
        return {-1,-1};
        
    }
    
};