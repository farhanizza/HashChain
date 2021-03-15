#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

const int hashTableSize = 10;

struct hashNode
{
    char key[100];
    int value;
    struct hashNode *next;
};
int convertStringToInt(char *theString)
{
    //convert text menjadi angka menggunakan ascii
    int len = strlen(theString); //panjang dari string
    int theInt = NULL;
    for (int i = 0; i < len; i++)
    {
        theInt += theString[i]; //akan berubah menjadi kode ascii
    }
    return theInt;
    //contoh Arif menjadi 386
}
int hashDivision(int value)
{
    return value % hashTableSize; //mengubah 386 mod 10 menjadi 6
}

void show(hashNode *hashTable[])
{
    struct hashNode *temp = NULL;
    for (int i = 0; i < hashTableSize; i++)
    {
        temp = hashTable[i];
        printf("[%d] ", i);
        while (temp != NULL)
        {
            printf("%s:%d -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void insert(char *key, int value, hashNode *hashTable[])
{
    struct hashNode *newNode = (struct hashNode *)malloc(sizeof(struct hashNode));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;
    int keyInt = convertStringToInt(key); //string di convert
    int index = hashDivision(keyInt);     //masuk ke index
    struct hashNode *temp = NULL;
    temp = hashTable[index]; //disimpan di temp
    if (temp == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int retrieve(char *key, hashNode *hashTable[])
{
    int keyInt = convertStringToInt(key);
    int index = hashDivision(keyInt);
    struct hashNode *temp = NULL;
    temp = hashTable[index];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0) //apakah temp mulai dari index pertama dari node tersebut jika kedua sama
        {
            printf("%s:%d\n", temp->key, temp->value);
            return temp->value;
        }
        temp = temp->next;
    }
    printf("%s : Not Found!\n", key); //jika tidak ketemu
    return 0;
}
int main()
{
    struct hashNode *hashTable[hashTableSize];
    for (int i = 0; i < hashTableSize; i++)
    {
        hashTable[i] = NULL;
    }
    insert("Arif", 18, hashTable);
    insert("Budi", 19, hashTable);
    insert("Citra", 20, hashTable);
    insert("Dwi", 21, hashTable);
    insert("Eka", 22, hashTable);
    insert("Fajar", 21, hashTable);
    insert("Hidayat", 20, hashTable);
    insert("Indah", 19, hashTable);
    insert("Kurniawan", 18, hashTable);
    show(hashTable);
    printf("\n");
    int value = retrieve("Dwi", hashTable);
    value = retrieve("Kurniawan", hashTable);
    value = retrieve("Dian", hashTable);
    return 0;
}
// [0] NULL
// [1] NULL
// [2] Dwi:21 -> NULL
// [3] Eka:22 -> NULL
// [4] Fajar:21 -> Indah:19 -> Kurniawan:18 -> NULL (jika -> ada maka hitungan ascii nya sama dan index nya juga sama)
// [5] NULL
// [6] Arif:18 -> NULL
// [7] NULL
// [8] Budi:19 -> Hidayat:20 -> NULL
// [9] Citra:20 -> NULL

// Dwi:21
// Kurniawan:18
// Dian : Not Found!