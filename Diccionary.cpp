#include "Diccionary.h"
#include <iostream>
#include <string>

using std::string;

struct NodeList {
	NodeList* next;
	string key;
	Commit* value;
};

struct List {
	NodeList* first;
};

struct UDiccionary::Diccionary {
	List* list;
};

NodeList* CreateNode(string key, Commit* value, NodeList* next) {
	NodeList* newNode = new NodeList;
	newNode->key = key;
	newNode->value = value;
	newNode->next = next;
	return newNode;
}

void UDiccionary::Insert(Diccionary* diccionary, string key, Commit* value) {
	NodeList* iterator = diccionary->list->first;
	bool found = false;
	while (iterator != NULL && !found) {
		if (key == iterator->key) {
			iterator->value = value;
			found = true;
		}
		iterator = iterator->next;
	}
	if (!found) {
		diccionary->list->first = CreateNode(key, value, diccionary->list->first);
	}
}

UGit::Commit* UDiccionary::Get(Diccionary* diccionary, string key) {
	NodeList* actualNode = diccionary->list->first;
	while (actualNode != NULL) {
		if (key == actualNode->key) {
			return actualNode->value;
		}
		actualNode = actualNode->next;
	}
	return NULL;
}

bool UDiccionary::Contains(Diccionary* diccionary, string key) {
	Commit* value = Get(diccionary, key);
	return value != NULL;
}

UDiccionary::Diccionary* UDiccionary::Create() {
	Diccionary* newDiccionary = new Diccionary;
	newDiccionary->list = new List;
	newDiccionary->list->first = NULL;

	return newDiccionary;
}

void UDiccionary::Destroy(Diccionary* diccionary) {
	NodeList* actualNode = diccionary->list->first;
	while (actualNode != NULL) {
		NodeList* nextNode = actualNode->next;
		delete actualNode;
		actualNode = nextNode;
	}
	delete diccionary->list;
	delete diccionary;
}