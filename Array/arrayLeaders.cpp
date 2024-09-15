// GeekForGeeks: https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> v;
        v.push_back(arr[n-1]);
        int s = arr[n-1];    
        for(int i=n-2; i>=0; i--){
            if(arr[i]>=arr[i+1] && arr[i] >=s){
                v.push_back(arr[i]);
                s=arr[i];
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
