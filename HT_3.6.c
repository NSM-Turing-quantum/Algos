#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1733

typedef struct
{
    char **words;
    int count;
} Group;

typedef struct HashNode
{
    char *key;
    int group_index;
    struct HashNode *next;
} HashNode;

unsigned long hashString(char *str)
{
    unsigned long hash = 5381;
    int c;
    while ((c = (unsigned char)*str++))
    {
        hash = hash * 33 + c;
    }
    return hash;
}

void insertHash(HashNode **table, char *key, int group_index)
{
    unsigned long hash = hashString(key);
    int index = hash % TABLE_SIZE;

    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = (char *)malloc(strlen(key) + 1);
    strcpy(newNode->key, key);
    newNode->group_index = group_index;
    newNode->next = table[index];
    table[index] = newNode;
}

int findHash(HashNode **table, char *key)
{
    unsigned long hash = hashString(key);
    int index = hash % TABLE_SIZE;

    HashNode *cur = table[index];
    while (cur != NULL)
    {
        if (strcmp(cur->key, key) == 0) return cur->group_index;
        cur = cur->next;
    }
    return -1;
}

void freeHashTable(HashNode **table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashNode *cur = table[i];
        while (cur != NULL)
        {
            HashNode* temp = cur;
            cur = cur->next;
            free(temp->key);
            free(temp);
        }
    }
    free(table);
}

Group *groupAnagrams(char **strs, int strsSize, int *returnSize)
{
    Group *result = (Group *)malloc(strsSize * sizeof(Group));
    *returnSize = 0;

    HashNode **hashTable = (HashNode **)calloc(TABLE_SIZE, sizeof(HashNode *));
    char keyBuffer[1024];

    for (int i = 0; i < strsSize; i++)
    {
        int counts[256] = {0};
        for (int j = 0; strs[i][j] != '\0'; j++)
        {
            counts[(unsigned char)strs[i][j]]++;
        }

        int pos = 0;
        for (int k = 0; k < 256; k++)
        {
            if (counts[k] > 0)
            {
                pos += sprintf(keyBuffer + pos, "%d#%d#", k, counts[k]);
            }
        }

        int groupIndex = findHash(hashTable, keyBuffer);

        if (groupIndex == -1)
        {
            groupIndex = *returnSize;
            insertHash(hashTable, keyBuffer, groupIndex);

            result[groupIndex].words = (char **)malloc(strsSize * sizeof(char *));
            result[groupIndex].count = 0;
            (*returnSize)++;
        }

        int currentSize = result[groupIndex].count;

        result[groupIndex].words[currentSize] = (char*)malloc(strlen(strs[i]) + 1);
        strcpy(result[groupIndex].words[currentSize], strs[i]);

        result[groupIndex].count++;
    }

    freeHashTable(hashTable);
    return result;
}

int main()
{
    char *input[] = {"eat", "tea", "tan", "ate", "nat", "bat", "chunga", "changa", "achung"};
    int strsSize = 9;

    int returnSize;

    Group *result = groupAnagrams(input, strsSize, &returnSize);

    printf("Result:\n");
    for (int i = 0; i < returnSize; i++)
    {
        printf("[ ");
        for (int j = 0; j < result[i].count; j++)
        {
            printf("%s ", result[i].words[j]);
        }
        printf("]\n");
    }

    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < result[i].count; j++)
        {
            free(result[i].words[j]);
        }
        free(result[i].words);
    }
    free(result);

    return 0;
}
