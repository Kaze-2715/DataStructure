// It's the inplementation of ADT linearlist, made by static storage and fixed memory.
// Made by Zhao Fangming

#ifndef LINEARLIST_ARRAY_H_
#define LINEARLIST_ARRAY_H_

#define MAXSIZE 100
typedef int item;

typedef struct linearList linearList;
struct linearList
{
    //The base pointer to the linear list
    item *array;
    //The number of element stored in the linear list
    int size;
    // @brief To clear all the elements in the linear list
    // @param list A pointer to the list you want to clear
    // @retval Status code of linear list
    int (*clear)(linearList *list);
    // @brief Destroy a list, free the memory
    // @param list A pointer to the linear list to be destroyed
    // @retval Status code of linear list
    int (*destroy)(linearList *list);

    // @brief To identify if the list is empty
    // @param list A pointer to the linear list to be identified
    // @retval Status code of linear list
    int (*isEmpty)(linearList *list);

    // @brief To identify if the list is full
    // @param list A pointer to the linear list to be identified
    // @retval Status code of linear list
    int (*isFull)(linearList *list);
    // @brief To get the current length of a linear list
    // @param list A pointer to the list to get length
    // @retval Status code of linear list
    int (*length)(linearList *list);
    // @brief To locate an item in the linear list
    // @param ptr The pointer to the item to be located
    // @param list The list to be located
    // @retval The number of the item
    int (*locate)(item *ptr, linearList *list);
    // @brief To get the item located at the specific index.
    // @param index The location of the item
    // @param list The list to be queried
    // @retval An item object
    int (*get)(int index, linearList *list);
    // @brief To insert an element into a specific location in the linear list
    // @param index The location you want to insert
    // @param element A pointer to the element you want to insert
    // @param list The list you want to insert into
    // @retval Status code of linear list
    int (*insert)(int index, item *element, linearList *list);
    // @brief To remove one item from the linear list
    // @param index The location you want to remove from
    // @param element A pointer to the item where you want to store the element to be removed
    // @param list The lineat list you wanted to remve from
    // @retval Status code of linear list
    int (*remove)(int index, item *element, linearList *list);
};

// @brief Status of linearlist
typedef enum
{
    LIST_OK,
    LIST_ERROR,
    LIST_OVERFLOW,
    LIST_NO_ELEMENT
} status;

// @brief Initialize a linearlist object
// @retval Status code of linear list
// @param list apointer to the linearlist to be initialzed.
int initList(linearList *list);

int clearList(linearList *list);

int destroyList(linearList *list);

int listIsEmpty(linearList *list);

int getLengthOfList(linearList *list);

int locateItem(item *ptr, linearList *list);

int getItem(int index, linearList *list);

int insertItem(int index, item *element, linearList *list);

int removeItem(int index, item *element, linearList *list);
#endif