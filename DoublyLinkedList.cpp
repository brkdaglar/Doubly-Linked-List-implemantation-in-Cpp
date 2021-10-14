
#include <iostream>
using namespace std;

struct doublyNode{
    int Id;
    string name;
    struct doublyNode *next;
    struct doublyNode *prev;

};


class DoublyLinkedList{
public:
    doublyNode *head = nullptr;
    doublyNode *last{} ;

    DoublyLinkedList()= default;

    void insert(int id,string name){   // function to insert items to linkedlist
        doublyNode *newnode = new doublyNode();
        newnode->Id = id;
        newnode->name = name;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        if (head==last&&head==nullptr){
            head = last = newnode;
            head->next = last->next = nullptr;
            head->prev = last->prev = nullptr;

        }else{
            last->next = newnode;
            newnode->prev = last;
            last = newnode;
            head->prev = last;
            last->next = head;
        }
    }

    void Delete(int id) {  // function to delete items from linkedlist
        struct doublyNode *temp, *ptr;
        if (last != nullptr) {
            ptr = last->next;
            if (ptr== last && last->Id == id) {
                temp = last;
                last = nullptr;
                head = nullptr;
                free(temp);
                cout << "User " << id<< " has been deleted" << endl;
                return;
            }
            if (ptr->Id == id){
                temp = ptr;
                last->next = ptr->next;
                head = ptr->next;
                ptr->next->prev = last;
                free(temp);
                cout << "User " << id << " has been deleted" << endl;
                return;
            }if (last->Id == id){
                temp = last;
                ptr = last->prev;
                ptr->next = temp->next;
                head->prev = ptr;
                last = ptr;
                free(temp);
                cout << "User " << id << " has been deleted" << endl;
                return;

            }

            while (ptr->next != last) {
                if (ptr->next->Id == id) {
                    temp = ptr->next;
                    ptr->next = temp->next;
                    temp->next->prev = ptr;
                    free(temp);
                    cout << "User " << id << " has been deleted" << endl;
                    return;
                }
                ptr = ptr->next;
            }


            cout << "User " << id << " does not exist" << endl;
        }else{
            cout << "User " << id << " does not exist" << endl;
            return;
        }
    }


    void listAll() {  // function to display all elements in linkedlist
        doublyNode *temp;
        temp = head;
        if (temp!=nullptr) {
            while (true) {
                cout << temp->Id << " " << temp->name << endl;
                temp = temp->next;
                if (temp==head){
                    break;
                }
            }
        }else{
            cout << "Empty List" << endl;
        }
    }


};





int main(){
    DoublyLinkedList dlinked = DoublyLinkedList();
    dlinked.insert(5,"Burak");
    dlinked.insert(9,"Kvothe");
    dlinked.insert(12,"Valencia");
    dlinked.insert(15,"Patrick");
    dlinked.insert(99,"Baby Yoda");
    dlinked.insert(88,"Mandalorian");
    dlinked.listAll();
    dlinked.Delete(99);
    dlinked.Delete(11);
    dlinked.Delete(12);
    dlinked.listAll();
    return 0;
};