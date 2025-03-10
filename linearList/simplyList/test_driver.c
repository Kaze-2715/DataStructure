#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

void printList(list *List) {
    node *current = List->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize the list
    //! 这里声明了野指针！
    //* list myList; //* 野指针 这里并非是声明了一个链表对象，而是声明了一个指向链表对象的指针
    list myList;
    initList(&myList);

    // Add some elements to the list
    myList.headInsert(10, &myList);
    myList.tailInsert(20, &myList);
    myList.tailInsert(30, &myList);

    // Print the list
    printf("List after adding elements: ");
    printList(&myList);

    // Remove an element from the list
    myList.indexRemove(2, &myList);

    // Print the list again
    printf("List after removing an element: ");
    printList(&myList);
    // Test removing from an empty list
    list emptyList;
    initList(&emptyList);
    emptyList.indexRemove(1, &emptyList);
    printf("Empty list after attempting to remove an element: ");
    printList(&emptyList);

    // Test inserting into an empty list
    emptyList.headInsert(5, &emptyList);
    printf("Empty list after inserting an element: ");
    printList(&emptyList);

    // Test removing the head element
    myList.indexRemove(1, &myList);
    printf("List after removing the head element: ");
    printList(&myList);

    // Test removing the tail element
    myList.indexRemove(2, &myList);
    printf("List after removing the tail element: ");
    printList(&myList);

    // Test inserting at the head
    myList.headInsert(40, &myList);
    printf("List after inserting at the head: ");
    printList(&myList);

    // Test inserting at the tail
    myList.tailInsert(50, &myList);
    printf("List after inserting at the tail: ");
    printList(&myList);

    // Test inserting at a specific index
    myList.indexInsert(2, 60, &myList);
    printf("List after inserting at index 2: ");
    printList(&myList);
    // Test removing a specific value
    myList.valueRemove(60, &myList);
    printf("List after removing value 20: ");
    printList(&myList);
    // Test removing from a specific index
    myList.indexRemove(2, &myList);
    printf("List after removing from index 2: ");
    printList(&myList);

    // Test removing all elements
    while (myList.head != NULL) {
        myList.indexRemove(1, &myList);
    }
    printf("List after removing all elements: ");
    printList(&myList);
    // Clean up
    myList.destroyList(&myList);

    return 0;
}