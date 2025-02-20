/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 定义哈希表节点结构
typedef struct Node {
    int key;    // 数组中的值
    int index;  // 数组下标
    struct Node* next;
} Node;

// 哈希函数
int hash(int key) {
    // 1. 处理负数
    unsigned int k = key;
    if(key < 0) {
        k = -key;
    }
    // 2. 选择一个合适的质数作为哈希表大小
    return k % 10007;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*)malloc(2 * sizeof(int));
    
    // 1. 创建哈希表
    Node** hashTable = (Node**)calloc(10007, sizeof(Node*));
    
    // 2. 遍历数组
    for(int i = 0; i < numsSize; i++) {
        // 计算需要查找的补数
        int complement = target - nums[i];
        
        // 3. 在哈希表中查找补数
        int index = hash(complement);
        Node* current = hashTable[index];
        while(current != NULL) {
            if(current->key == complement) {
                // 找到答案
                ans[0] = current->index;
                ans[1] = i;
                
                // 释放哈希表内存
                for(int j = 0; j < 10007; j++) {
                    Node* head = hashTable[j];
                    while(head != NULL) {
                        Node* temp = head;
                        head = head->next;
                        free(temp);
                    }
                }
                free(hashTable);
                
                return ans;
            }
            current = current->next;
        }
        
        // 4. 将当前数字加入哈希表
        index = hash(nums[i]);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = nums[i];
        newNode->index = i;
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
    
    // 释放哈希表内存（虽然按题目要求一定会在上面返回）
    for(int i = 0; i < 10007; i++) {
        Node* head = hashTable[i];
        while(head != NULL) {
            Node* temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(hashTable);
    
    return ans;
}
