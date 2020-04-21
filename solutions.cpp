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

class Solution9 {
public:
    int romanToInt(string s){
        int size = s.size() + 1;
        char numeral[size];
        strcpy(numeral, s.c_str());

        int sum = 0;

        for(int i = 0; i < size - 1; i++){
            sum += handleSubtractions(numeral, i);
        }

        return sum;
    }

    int getNumeralValue(char value){
        switch(value) {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                return 0;

        }
    }

    int handleSubtractions(char * numeral, int i){
        if(numeral[i + 1] == NULL) return getNumeralValue(numeral[i]);
        if(numeral[i] == 'I' && (numeral[i + 1] == 'V' || numeral[i + 1] == 'X')){
            return -1;
        }
        if(numeral[i] == 'X' && (numeral[i + 1] == 'L' || numeral[i + 1] == 'C')){
            return -10;
        }
        if(numeral[i] == 'C' && (numeral[i + 1] == 'D' || numeral[i + 1] == 'M')){
            return -100;
        }
        else return getNumeralValue(numeral[i]);
    }

};

class Solution10 {
public:
    bool isValid(string s) {
        vector<char> v;
        int length = s.length();

        for(int i = 0; i < length; i++){

            if(isOpen(s[i])){
                v.push_back(s[i]);
            }
            else{
                if(v.empty()) return false;
                else if(getInverse(v.back()) != s[i]) return false;
                else v.pop_back();
            }
        }

        return v.empty();
    }

    bool isOpen(char i){
        if(i == '[' || i == '{' || i == '(') return true;
        else return false;
    }

    char getInverse(char i){
        if(i == '[') return ']';
        else if(i == '{') return '}';
        else if(i == '(') return ')';
        else return NULL;
    }
};

class Solution11 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i != nums.size(); ++i) {
            cout << '['<< nums[i] << '] ';
            for(int i2 = 0; i2 != nums.size(); ++i2) {
                if ((i != i2) && (nums[i] + nums[i2] == target)){
                    vector<int> vect{ nums[i], nums[i2]};
                    return vect;
                }
            }
        }
        vector<int> vect{ 0, 0};
        return vect;
    }
};

class Solution12 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l2 || (l1 && l1->val < l2->val)){
            ListNode * node = new ListNode(l1->val);
            node->next = mergeTwoLists(l1->next, l2);
            return node;
        } else {
            ListNode * node = new ListNode(l2->val);
            node->next = mergeTwoLists(l1, l2->next);
            return node;
        }
    }
};

class Solution13 {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(i < (nums.size() - 1)){
                if(nums[i] == nums[i + 1]){
                    nums.erase(nums.begin() + i);
                    i--;
                }
            }
        }
        return nums.size();
    }
};

class Solution14 {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        for(int i = 0; i < length; ++i){
            if(nums[i] == val){
                auto it = nums.begin() + i;
                *it = std::move(nums.back());
                nums.pop_back();
                --length;
                --i;
            }
        }
        return length;
    }
};