#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1733


typedef struct HashNode
{
    int key;
    int value;
    struct HashNode *next;
} HashNode;

unsigned int hash(int key)
{
    int abs_key;

    if (key < 0)
        abs_key = -key;
    else
        abs_key = key;


    return abs_key % TABLE_SIZE;
}

void insert(HashNode **table, int key, int value)
{
    unsigned int index = hash(key);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

int find(HashNode **table, int key)
{
    unsigned int index = hash(key);
    HashNode *current = table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    HashNode **hashTable = (HashNode **)calloc(TABLE_SIZE, sizeof(HashNode *));

    int *result = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];

        int complement_index = find(hashTable, complement);

        if (complement_index != -1)
        {
            result[0] = complement_index;
            result[1] = i;
            *returnSize = 2;

            for (int j = 0; j < TABLE_SIZE; j++)
            {
                HashNode *curr = hashTable[j];
                while (curr != NULL)
                {
                    HashNode *temp = curr;
                    curr = curr->next;
                    free(temp);
                }
            }
            free(hashTable);
            return result;
        }

        insert(hashTable, nums[i], i);
    }

    *returnSize = 0;
    free(result);

    for (int j = 0; j < TABLE_SIZE; j++)
    {
        HashNode *curr = hashTable[j];
        while (curr != NULL)
        {
            HashNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashTable);
    return NULL;
}

int main()
{
    int nums[] = {1, 3, 7, 16, 2};
    int target = 10;
    int returnSize;

    int *result = twoSum(nums, 5, target, &returnSize);

    if (returnSize == 2)
    {
        printf("Pairs: %d[%d], %d[%d]\n", nums[result[0]], result[0], nums[result[1]], result[1]);
        free(result);
    }
    else
    {
        printf("No pairs\n");
    }

    return 0;
}
