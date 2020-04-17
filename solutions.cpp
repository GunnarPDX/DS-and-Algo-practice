class Solution {
public:
    bool isHappy(int n) {
        if (n == 0) return false;
        int value = n;
        while(
                value != 1
                && value != 4
                && value != 16
                && value != 37
                && value != 58
                && value != 89
                && value != 145
                && value != 42
                && value != 20
                ){
            value = applySquares(value);
        }
        return value == 1;
    }
    int applySquares(int num) {
        int res = 0;
        while(num > 0){
            res += pow(num % 10, 2);
            num = num / 10;
        }
        return res;
    }
};

class Solution2 {
public:
    int reverse(int x) {
        long long int reverse = 0, rem;
        while(x != 0)
        {
            rem = x % 10;
            reverse = reverse * 10 + rem;
            x /= 10;
        }
        if(reverse > 2147483647 || reverse < -2147483648) return 0;
        return (int)reverse;
    }
};

class Solution3 {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int len = num.length();
        int tail = len - 1;
        bool isPalindrome = true;
        for(int i = 0; i < len; ++i){
            if (num[i] != num[tail]) isPalindrome = false;
            --tail;
        }
        return isPalindrome;
    }
};

class Solution4 {
public:
    bool isPalindrome(ListNode* head) {
        queue <int> q;
        return traverseList(head, q);
    }
    bool traverseList(ListNode * head, queue<int> & q){
        if(!head) return true;
        q.push(head->val);
        if(!traverseList(head->next, q)) return false;
        if(head->val == q.front()){
            q.pop();
            return true;
        } else return false;
    }
};

class Solution5 {
    function longestCommonPrefix($strs) {
        $result = str_split($strs[0]); // set common prefix to first word
        $max = count($strs); // set max num of words
        for($i = 1; $i < $max; $i++){ // loop through each word, starting w/second
            $comparison = str_split($strs[$i]); // split each word
            $tempRes = []; // create empty temp array
            $len = min(count($result), count($comparison)); // find min length for both words
            for($x = 0; $x < $len; $x++){ // loop through each car
                if($result[$x] === $comparison[$x]){ //if a match then push to array
                    array_push($tempRes, $result[$x]);
                } else break;
            }
            $result = $tempRes; // update result
        }
        return join($result); //return result as string
    }
}

class Solution6 {
public:
    bool isValidBST(TreeNode* root, long min = -2147483649, long max = 2147483648) {
        if(!root) return true;
        if(min >= root->val || max <= root->val) return false;
        if((root->left && (root->val <= root->left->val)) || (root->right && (root->val >= root->right->val))) return false;
        return (isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max));
    }
};

class Solution7 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int first = 0, int last = 2147483647) {
        if (first > last) return NULL;
        if (nums.empty()) return NULL;
        if(last == 2147483647) last = nums.size() - 1;
        int i = (first + last)/2;
        TreeNode* root = new TreeNode(nums[i]);
        root->left = sortedArrayToBST(nums, first, i - 1);
        root->right = sortedArrayToBST(nums, i + 1, last);
        return root;
    }
};

class Solution8 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        if(head->val == val) {
            head = head->next;
            if(head) head = removeElements(head, val);
        }else if(head && head->next) head->next = removeElements(head->next, val);
        return head;
    }
};