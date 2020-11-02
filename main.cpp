#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
using namespace std;

struct listrec
{
    int value;
    struct listrec *next;
};

void deepcopy(listrec *old_linked_list, listrec *&new_linked_list)
{

    new_linked_list = new listrec;

    new_linked_list->value = old_linked_list->value;
    new_linked_list->next = new listrec;

    new_linked_list->next->value = old_linked_list->next->value;
    new_linked_list->next->next = new listrec;

    new_linked_list->next->next->value = old_linked_list->next->next->value;
    new_linked_list->next->next->next = nullptr;
}

int main()
{
    listrec *head_old = new listrec;
    listrec *head_new = new listrec;

    head_old->value = 4;
    head_old->next = new listrec;

    head_old->next->value = 5;
    head_old->next->next = new listrec;

    head_old->next->next->value = 3;
    head_old->next->next->next = nullptr;

    deepcopy(head_old, head_new);
    cout << "Old linked list: " << head_old->value << ",";
    cout << head_old->next->value << ",";
    cout << head_old->next->next->value;
    cout << "\n";

    cout << "New linked list after deep copy: " << head_new->value << ",";
    cout << head_new->next->value << ",";
    cout << head_new->next->next->value;

    return 0;
}
