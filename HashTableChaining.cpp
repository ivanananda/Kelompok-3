#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"

const int hashTableSize = 10;

struct hashNode {
	char key[100];
	int value;
	struct hashNode *next;
};

int convertStringToInt(char* theString){
	int len = strlen(theString);
	int theInt = 0;
	for (int i=0; i<len; i++){
		theInt+=theString[i];
	}
	return theInt;
}

int hashDivision(int val) {
	return val % hashTableSize;
}

void show(hashNode* hashTable[]) {
	struct hashNode *temp = NULL;

	for (int i = 0; i < hashTableSize; i++) {
		temp = hashTable[i];
		printf("[%d] ", i);
		while (temp != NULL) {
			printf("%s:%d -> ", temp->key, temp->value);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void insert(char* key, int value, hashNode* hashTable[]) {
	struct hashNode *new_node = (struct hashNode*) malloc(sizeof(struct hashNode));

	strcpy(new_node->key, key);
	new_node->value = value;
	new_node->next = NULL;

	int keyInt = convertStringToInt(key);
	int index = hashDivision(keyInt);
	
	struct hashNode *temp = NULL;
	temp = hashTable[index];

	if (temp == NULL) {
		hashTable[index] = new_node;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

int retrieve(char* key, hashNode* hashTable[]){	
	int keyInt = convertStringToInt(key);
	int index = hashDivision(keyInt);
		
	struct hashNode *temp = NULL;

	temp = hashTable[index];
	while (temp != NULL) {
		if (strcmp(temp->key, key)==0){
			printf("%s:%d\n", temp->key, temp->value);
			return temp->value;
		}		
		temp = temp->next;
	}
	printf("%s:not found\n", key);
	return 0;
}

int main() {
	struct hashNode* hashTable[hashTableSize];
	for (int i = 0; i < hashTableSize; i++) {
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