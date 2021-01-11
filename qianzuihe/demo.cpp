#include<iostream>
#include<string>
#include<string.h>
#include<limits.h>
#include<vector>
#include<stack>
using namespace std;

int myAtoi(string s) {
    long res = 0;
    int state = 0 ; // state == 0 为初始状态 ，1 为正整数状态 ，2为负整数
    for(char i : s)
    {
        if(state == 0 && i == ' ')continue;
        else if(state == 0 && i == '+')state = 1;
        else if(state == 0 && i == '-')state = 2;
        else if(i >= '0' && i <= '9')
        {
            if(state == 0)state = 1;
            int tmp = i - '0';
            res = res*10 + tmp;
            if(res > INT_MAX)break;
        }
        else break;
    }
    if(state == 1 && res > INT_MAX)res = INT_MAX;
    else if(state == 2)
    {
        res = -res;
        if(res < INT_MIN)res = INT_MIN;
    }
    return res;
}
vector<string> summaryRanges(vector<int>& nums) 
{
        vector<string> vec;
        int len = nums.size();
        int start = 0;
        int end = 0;
        for(int i=0;i<len;i++)
        {
            string str = "";
            start = i;
            while(start<len-1&&nums[start+1]-1==nums[start])
                start++;
            end=start;
            str.append(to_string(nums[i]));
            if(nums[i]==nums[end])
                goto next;
            str.append("->");
            str.append(to_string(nums[end]));
            next:
            vec.push_back(str);
            i=end;
        }
        return vec;
}
int longestValidParentheses(string s) {
    stack<char> stk;
    int len = s.size();
    int ans = 0;
    if(len==0) return ans;
    stk.push(s[0]);
    for(int i=1;i<len;i++)
    {  
        if(!stk.empty()&&stk.top()=='('&&s[i]==')'){
            stk.pop();
            ans+=2;
        }else{
            stk.push(s[i]);
        }
    }
    return ans;
}
int strStr(char * haystack, char * needle){
    if(!haystack||!needle) return 0;
    while(*haystack!='\0')
    {
        int ans = 0;
        char *tmp = needle;
        char *hayTmp = haystack;
        while(*hayTmp!='\0'&&*tmp!='\0'&&*hayTmp==*tmp)
        {
            hayTmp++;
            tmp++;
            ans++;
        }
        if(*tmp=='\0')
            return ans;
        haystack++;
    }
    return 0;
}
typedef struct List_head
{
    int val;
    struct List_head* next;
    List_head(int x):val(x),next(NULL){}
}List_head;
struct List_head* create_tail(int n)
{
    struct List_head* tmp = new struct List_head(0);
    tmp->val = 1;
    struct List_head* head = tmp;
    for(int i=2;i<=n;i++)
    {
        struct List_head* node = new struct List_head(0);
        node->val = i;
        node->next = NULL;
        head->next = node;
        head=head->next;
    }
    return tmp;
}
struct List_head* create_head(int n)
{
    struct List_head* tmp = new struct List_head(0);
    struct List_head* head = tmp;
    for(int i=1;i<=n;i++)
    {
        struct List_head* node = new struct List_head(0);
        node->val = i;
        node->next = NULL;
        struct List_head* pri = head->next;
        head->next = node;
        node->next = pri;     
    }
    return tmp->next;
}
struct List_head* reverseBetween(struct List_head* head, int m, int n) {
    struct List_head* h = new struct List_head(-1);
    h->next = head;
    struct List_head* cur;
    struct List_head* prev = h;
    for(int i=0;i<m-1;i++)
        prev = prev->next;
    cur = prev->next;
    for(int i=0;i<n-m;i++)
    {
        struct List_head* pri = cur->next;
        cur->next = pri->next;
        pri->next = prev->next;
        prev->next=pri; 
    }
    return h->next;
}
int main()
{
    // cout<<myAtoi("   -h123hhs12345h123")<<endl;
    // cout<<atoi("    -h23hhs12345h123")<<endl;
    vector<int> nums = {0,1,2,4,5,7};
    vector<string> str = summaryRanges(nums);
    vector<string>::iterator it = str.begin();
    for(;it!=str.end();it++)
    {
        cout<<*it<<endl;
    }
    string str1 = "()(()()(()";
    int ret = longestValidParentheses(str1);
    cout<<ret<<endl;

    char a[] = "hello";
    char b[] = "ellkkkkk";
    int len = strStr(a,b);
    cout<<len<<endl;

    struct List_head* head = create_tail(5);
    reverseBetween(head,2,4);
    while (head)
    {
        cout<<"val:"<<head->val<<endl;
        head=head->next;
    }
    
    return 0;
}