#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// 打印栈中的所有元素
void printStack(stack *Stack) {
    node *current = Stack->top;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    stack myStack;
    initStack(&myStack);

    // 测试将元素压入栈中
    myStack.push(10, &myStack);
    myStack.push(20, &myStack);
    myStack.push(30, &myStack);
    printf("压入元素后的栈: ");
    printStack(&myStack);

    // 测试从栈中弹出一个元素
    item popped;
    myStack.pop(&popped, &myStack);
    printf("弹出的元素: %d\n", popped);
    printf("弹出元素后的栈: ");
    printStack(&myStack);

    // 测试在不弹出元素的情况下获取栈顶元素
    item top;
    myStack.get(&top, &myStack);
    printf("栈顶元素: %d\n", top);

    // 测试清空栈
    myStack.clear(&myStack);
    printf("清空后的栈: ");
    printStack(&myStack);

    // 测试从空栈中弹出元素
    if (!myStack.pop(&popped, &myStack)) {
        printf("弹出操作失败: 栈为空\n");
    }

    // 测试将元素压入栈直到栈满
    for (int i = 0; i < myStack.MAXCOUNT; i++) {
        myStack.push(i, &myStack);
    }
    printf("压入MAXCOUNT元素后的栈: ");
    printStack(&myStack);

    // 测试向满栈中压入元素
    if (!myStack.push(100, &myStack)) {
        printf("压入操作失败: 栈已满\n");
    }

    return 0;
}