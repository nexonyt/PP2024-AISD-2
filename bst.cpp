#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Struktura węzła listy jednokierunkowej
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Wstawianie elementu do posortowanej listy
void insertIntoSortedList(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head || head->val >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }
    ListNode* curr = head;
    while (curr->next && curr->next->val < val) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

// Struktura węzła drzewa BST
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Wstawianie elementu do drzewa BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

// Pomiar czasu tworzenia struktury
double measureCreationTime(void (*createStructure)(vector<int>&), vector<int>& elements) {
    clock_t start = clock();
    createStructure(elements);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

// Pomiar czasu wyszukiwania elementów
double measureSearchTime(ListNode* head, vector<int>& elements) {
    clock_t start = clock();
    for (int el : elements) {
        // Przeszukiwanie listy jednokierunkowej
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

// Pomiar czasu usuwania struktury
double measureDeletionTime(void (*deleteStructure)(ListNode*&), ListNode*& head) {
    clock_t start = clock();
    deleteStructure(head);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

// Tworzenie listy jednokierunkowej
void createSortedList(vector<int>& elements) {
    ListNode* head = nullptr;
    for (int el : elements) {
        insertIntoSortedList(head, el);
    }
}

// Usuwanie listy jednokierunkowej
void deleteList(ListNode*& head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Tworzenie drzewa BST
void createBST(vector<int>& elements) {
    TreeNode* root = nullptr;
    for (int el : elements) {
        root = insertIntoBST(root, el);
    }
}

// Usuwanie drzewa BST
void deleteBST(TreeNode* root) {
    if (!root) return;
    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
}

int main() {
    // Parametry pomiaru czasu
    int elementsCount = 1000;
    int minValue = 1;
    int maxValue = 10000;

    // Generowanie losowego ciągu liczb
    vector<int> randomArray;
    for (int i = 0; i < elementsCount; ++i) {
        randomArray.push_back(rand() % (maxValue - minValue + 1) + minValue);
    }

    // Pomiar czasu tworzenia listy jednokierunkowej
    double listCreationTime = measureCreationTime(createSortedList, randomArray);

    // Pomiar czasu tworzenia drzewa BST
    double bstCreationTime = measureCreationTime(createBST, randomArray);

    // Pomiar czasu wyszukiwania elementów w liście jednokierunkowej
    double listSearchTime = measureSearchTime(head, randomArray);

    // Pomiar czasu usuwania listy jednokierunkowej
    double listDeletionTime = measureDeletionTime(deleteList, head);

    // Pomiar czasu usuwania drzewa BST
    double bstDeletionTime = measureDeletionTime(deleteBST, root);

    return 0;
}