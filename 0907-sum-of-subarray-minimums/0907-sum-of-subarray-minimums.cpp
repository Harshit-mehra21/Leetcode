class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> pse(n);
        vector<int> nse(n);

        stack<int> st;

       
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            if(st.empty())
                pse[i]=-1;
            else
                pse[i]=st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if(st.empty())
                nse[i]=n;
            else
                nse[i]=st.top();

            st.push(i);
        }

        long long ans=0;

        for(int i=0;i<n;i++)
        {
            long long left=i-pse[i];
            long long right=nse[i]-i;

            ans=(ans+(long long)arr[i]*left*right)%MOD;
        }

        return ans;
    }
};
