/*
bool presentElem(int a,vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a){
                return true;
            }
        }
        return false;
    }
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            int a=temp->val;
            if(presentElem(a,nums)){
                temp=temp->next;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
*/