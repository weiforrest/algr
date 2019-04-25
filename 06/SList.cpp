/*
Target:
    [x] 单链表反转
    [x] 链表中环的检测
    [ ] 两个有序链表的合并
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
    ListNode(DateType date) : date(date), next(NULL) {}
};

class SList {
  public:
    SList();
    ~SList();
    bool isFull();
    
    int insertHead(DateType date);
    ListNode * find(DateType date);
    void deleteDescOrder(int order);
    void reversal();
    void reversal_new();
    void print();
    bool isHoop(bool);
    ListNode * findMid();
    void deleteElem(ListNode * current);
    void deleteElements(DateType val);

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
    ListNode * first,* next,* tmp;
    if (length > 0) {
        first = this->head;
        next = this->head->next;
        while(next){
            tmp = this->head;
            this->head = next;
            next = next->next;
            this->head->next = tmp;
        }
        first->next = NULL;
    }
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

ListNode * SList::findMid()
{
    ListNode * slow = this->head;
    ListNode * fast = this->head;
    while (fast){
        fast = fast->next;
        if (fast) {
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
// LRU 算法
int SList::insertHead(DateType date)
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
    num = 0;
    while(num < count) {
        list.insertHead(num++);
    }

    cout<< "Current SList \n";
    list.print();
    list.deleteElements(0);
    list.print();
    //  测试逆序
    // cout << "After reversal" <<endl;
    // list.reversal_new();
    // list.print();
    // 测试逆序删除
    // cout<<"please insert delete postion"<<endl;
    // cin>>count;
    // list.deleteDescOrder(count);
    // // list.reversal();
    // cout<<"After Change\t";
    // list.print();

    // 测试查找中点
    // ListNode * mid = list.findMid();
    // cout<< "Middle Node Value :" << mid->date<<endl;

    // 测试LRU算法
    // while(1) {
    //     cin>>count;
    //     list.insertHead(count);
    //     cout<<"After InserHead Change"<<endl;
    //     list.print();
    // }
    
    return 0;
}
