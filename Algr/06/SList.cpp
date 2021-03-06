/*
Target:
    [x] 单链表反转
    [x] 链表中环的检测
    [x] 两个有序链表的合并
    [x] 删除链表倒数第n个节点
    [x] 求链表的中间节点
    [x] LRU算法
*/
#include <iostream>
using namespace std;

typedef int DateType;
struct ListNode {
    DateType date;
    ListNode * next;
    ListNode(DateType date) : date(date) ,next (NULL) {}
};

class SList {
  public:
    SList();
    ~SList();
    bool isFull();
    static ListNode * merge(ListNode *, ListNode *);
    void insertHead(DateType date);
    int insertHead_LRU(DateType date);
    ListNode * find(DateType date);
    void deleteDescOrder(int order);
    void deleteDescOrder_new(int order);
    void reversal();
    void reversal_new();
    void print();
    bool isHoop(bool);
    ListNode * findMid_before();
    ListNode * findMid_after();
    void deleteElem(ListNode * current);
    void deleteElements(DateType val);

    bool isPalindrome();
  private:
    int MaxSize;
    int length;
    ListNode * head;

};

SList::SList()
{
    this->MaxSize = 10;
    this->length = 0;
    this->head = NULL;
}

SList::~SList()
{
    this->MaxSize = 0;
    this->length = 0;
    ListNode * index = this->head;
    while (this->head != NULL){
        this->head = index->next;
        delete index;
        index = this->head;
    };
}

// 当前替换下一个节点, 传入节点不能为末尾节点
void SList::deleteElem(ListNode * current)
{
    ListNode *next = current->next;
    current->date = current->next->date;
    current->next = current->next->next;
    delete next;
    this->length -= 1;
}

ListNode * SList::find(DateType date)
{
    ListNode * tmp = this->head;
    while(tmp != NULL){
        if(tmp->date == date){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;

}

void SList::print()
{
    ListNode * tmp = this->head;
    while(tmp!=NULL){
        cout<< tmp->date<< "\t";
        tmp = tmp->next;
    }
    cout<<endl;
    cout<<"SList length :"<< this->length<<endl;
}

void SList::reversal()
{
    // ListNode * first,* next,* tmp;
    // if (length > 0) {
    //     first = this->head;
    //     next = this->head->next;
    //     while(next){
    //         tmp = this->head;
    //         this->head = next;
    //         next = next->next;
    //         this->head->next = tmp;
    //     }
    //     first->next = NULL;
    // }
    ListNode * next,* pre = NULL;
    while(this->head) {
        next = this->head->next;
        this->head->next = pre;
        pre = this->head;
        this->head = next;
    }
    this->head = pre;
}

void SList::reversal_new()
{
    ListNode * current = this->head;
    ListNode * pre = this->head;
    ListNode * next;
    while (current) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    if (this->head) {
        this->head->next = NULL;
        this->head = pre;
    }
}

bool SList::isHoop(bool type = false)
{
    if (type) {
        ListNode * slow = this->head;
        ListNode * fast = this->head;
        while (fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
            }
            if (slow == fast) {
                return true;
            }
        }
        return false;
    } else {
        //使用length 属性
        ListNode * current = this->head;
        ListNode * next = this->head;
        int count = 0;
        while (next){
            if (count > this->length){
                return true;
            }
            count += 1;
            next = next->next;
        }
        return false;

    }
}

//  如果是为偶数，返回的节点为后一个
ListNode * SList::findMid_after()
{
    ListNode * slow = this->head;
    ListNode * fast = this->head;
    while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

}
//  如果是为偶数，返回的节点为后一个
ListNode * SList::findMid_before()
{
    ListNode * slow = this->head;
    ListNode * fast = this->head;
    while (fast && fast->next){
        fast = fast->next;
        if (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;

}

void SList::deleteDescOrder(int order)
{
    ListNode * pre = this->head;
    int count = this->length - order;
    if (count <= 0) {
        this->head = this->head->next;
        delete pre;
        this->length-= 1;
        return ;
    }
    while (count > 1) {
        pre = pre->next;
        count -= 1;
    }

    ListNode * current =  pre->next;
    pre->next = pre->next->next;
    delete current;
    this->length -= 1;
}

//不知道长度的情况下
void SList::deleteDescOrder_new(int order){
    ListNode * slow = this->head;
    ListNode * fast = slow,*tmp;
    while(order-- > 0) {
        fast = fast->next;
    }
    if(!fast) {
        this->head = slow->next;
        delete slow;
        return ;
    }
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;
}
// LRU 算法
int SList::insertHead_LRU(DateType date)
{
    ListNode * pre = this->head;
    ListNode * tmp;
    int count = 0;
    if (pre) {
        if (pre->date == date)
            return 1;
        // 查找到要删除的节点
        while(pre->next) {
            if (pre->next->date == date) {
                //删除之前的节点
                tmp = pre->next;
                pre->next = tmp->next;
                delete tmp;
                this->length -= 1;
                break;
            }
            pre = pre->next;
            count += 1;
        }
    }
    // 插入首节点
    tmp = this->head;
    this->head = new ListNode(date);
    this->head->next = tmp;
    this->length += 1;
    return count;
}

void SList::insertHead(DateType date)
{
    ListNode * tmp = this->head;
    this->head = new ListNode(date);
    this->head->next = tmp;
    this->length += 1;
}

bool SList::isPalindrome() {
    ListNode * fast = this->head,*slow = this->head,*next,*pre = NULL;
    bool flag;
    //找到链表中点
    while(fast && fast->next){
        fast = fast->next;
        if(fast->next) {
            flag = false; // 奇数
            fast = fast->next;
            //反转慢指针
            next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;     //slow 指向下一个未反转节点
        }else {
            flag = true;
            break;
        }
    }
    fast = slow->next;
    if (!flag) { //奇数
        next = slow;
        slow = pre;
        pre = next; //pre 指向中点
    } else { //偶数
        slow->next = pre;
        pre = fast;
    }
    flag = true;
    while(slow) {//反转回去
        if(slow->date != fast->date) flag = false;
        fast = fast->next;
        next = slow->next;
        slow->next = pre;
        pre = slow;
        slow = next;
    }
    return flag;
}

void SList::deleteElements(DateType val) {
        ListNode * current = new ListNode(0);
        ListNode * tmp,*first = current;
        current->next = this->head;
        while(current->next) {
            if (current->next->date == val) {
                tmp = current->next;
                current->next= tmp->next;
                delete tmp;
            }else {
                current = current->next;
            }
        }
        this->head = first->next;
        this->length -= 1;
        delete first;
}
ListNode * SList::merge(ListNode * l1, ListNode * l2)
{
    ListNode * current1 = l1;
    ListNode * current2 = l2;
    ListNode * l3 = new ListNode(0);
    ListNode * current3 = l3;
    bool flag = true;
    while(current1 || current2) {
        if(current1) {
            flag = true;
            if(current2){
                if(current1->date > current2->date){
                    flag = false;
                }
            }
        }else{
            flag = false;
        }
        current3->next = new ListNode(flag? current1->date:current2->date);
        current3 = current3->next;
        if (flag) {
           current1 = current1->next;
        }else{
            current2=  current2->next;
        }
    }
    current3 = l3->next;
    delete l3;
    return current3;

}

int main(int argc, char const *argv[])
{
    SList list;
    DateType num = 0;
    // while(1){
    //     cout << "please enter a number,99999== exit" << endl;
    //     cin >> num;
    //     if(num == 99999) {
    //         break;
    //     }
    //     list.insertHead(num);
    // }
    int count;
    cin >> count;
    while(num < count) {
        list.insertHead(num++);
    }
    while(num > 0) {
        list.insertHead(--num);
    }

    cout<< "Current SList \n";
    list.print();
    // list.deleteElements(0);
    // list.print();
    //  测试逆序
    // cout << "After reversal" <<endl;
    // list.reversal_new();
    // list.print();

    // 测试回文
    if( list.isPalindrome()) {
        cout << "Is palindrome" <<endl;
    } else {
        cout << "Is not palindrome" <<endl;
    }
    list.print();
    // 测试逆序删除
    // cout<<"please insert delete postion"<<endl;
    // cin>>count;
    // list.deleteDescOrder(count);
    // // list.reversal();
    // cout<<"After Change\t";
    // list.print();

    // 测试查找中点
    // ListNode * mid = list.findMid_before();
    // if (mid ) {
    // cout<< "Middle Node Value :" << mid->date<<endl;
    // } else{
    //     cout << "SList is empty"<<endl;
    // }

    // 测试LRU算法
    // while(1) {
    //     cin>>count;
    //     list.insertHead(count);
    //     cout<<"After InserHead Change"<<endl;
    //     list.print();
    // }
    
    return 0;
}
