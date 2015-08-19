#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* Node;
static void join(Node a, Node b) {
    a->right = b;
    b->left = a;
}
static Node append(Node a, Node b) {
    Node aLast, bLast;
    if (a==NULL) return(b);
    if (b==NULL) return(a);
    aLast = a->left;
    bLast = b->left;
    join(aLast, b);
    join(bLast, a);
    return(a);
}
static Node treeToList(Node root) {
    Node aList, bList;
    
    if (root==NULL) return(NULL);
    aList = treeToList(root->left);
    bList = treeToList(root->right);
    root->left = root;
    root->right = root;
    aList = append(aList, root);
    aList = append(aList, bList);
    return(aList);
}
static Node newNode(int data) {
        Node node = (Node) malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return(node);
    }
static void treeInsert(Node* rootRef, int data) {
        Node root = *rootRef;
        if (root == NULL) *rootRef = newNode(data);
        else {
            if (data <= root->data) treeInsert(&(root->left), data);
            else treeInsert(&(root->right), data);
        }
    }
static void printList(Node head) {
        Node current = head;
        while(current != NULL) {
            printf("%d ", current->data);
            current = current->right;
            if (current == head) break;
        }
        printf("\n");
    }

void inOrder(Node node)
{
    if (node == NULL)
        return;
    
    inOrder(node->left);
    printf("%d ", node->data);
    
    inOrder(node->right);
}
    int main() {
        Node root = NULL;
        Node head;
        treeInsert(&root, 1);
        treeInsert(&root, 2);
        treeInsert(&root, 3);
        treeInsert(&root, 4);
        treeInsert(&root, 5);
        treeInsert(&root, 6);
        treeInsert(&root, 7);
        inOrder(root);
        printf("\n");
        head = treeToList(root);
        printList(head);    /* prints: 1 2 3 4 5  */
        return(0);
    }
