/*
Target:
    [x] 单链表反转
    [ ] 链表中环的检测
    [ ] 两个有序链表的合并
    [x] 删除链表倒数第n个节点
    [ ] 求链表的中间节点
    [ ] LRU算法
*/
#include <iostream>
using namespace std;

typedef int DateType;
struct ListNode {
    DateType date;
    ListNode * next;
};

class SList {
  public:
    SList();
    ~SList();
    bool isFull();
    
    void insertHead(DateType date);
    ListNode * find(DateType date);
    void deleteDescOrder(int order);
    void reversal();
    void print();
  private:
    void deleteElem(ListNode ** current);
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

void SList::deleteElem(ListNode ** current)
{
    ListNode *index = *current;
    *current = index->next;
    delete index;
    this->length -= 1;
}

void SList::insertHead(DateType date)
{
    ListNode * tmp = this->head;
    this->head = new ListNode;
    this->head->date = date;
    this->head->next = tmp;
    this->length += 1;
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

//TODO: hava a bug
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

    cout<< "Current SList \t";
    list.print();
    cout<<"please insert delete postion"<<endl;
    cin>>count;
    list.deleteDescOrder(count);
    // list.reversal();
    cout<<"After Change\t";
    list.print();
    return 0;
}
