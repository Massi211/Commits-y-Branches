#include "Commit.h"
#include "User.h"
#include "DateTime.h"
#include "Context.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;

struct UGit::Commit {

	Commit* parent;
	string message;
	string hashCode;
	UDateTime::DateTime* creationDateTime;
	UUser::User* author;

};

string GenerateRandomHashCode();

UGit::Commit* UGit::CreateCommit(Commit* parent, string message) {
	Commit* newCommit = new Commit;

	newCommit->parent = parent;
	newCommit->message = message;
	newCommit->hashCode = GenerateRandomHashCode();
	newCommit->creationDateTime = UContext::GetNow();
	newCommit->author = UContext::GetCurrentUser();

	return newCommit;
}

UDateTime::DateTime* UGit::GetDate(const Commit* commit) {
	return commit->creationDateTime;
}

UUser::User* UGit::GetAuthor(const Commit* commit) {
	return commit->author;
}

string UGit::GetMessage(const Commit* commit) {
	return commit->message;
}

UGit::Commit* UGit::GetParent(const Commit* commit) {
	return commit->parent;
}

string UGit::GetHashCode(const Commit* commit) {
	return commit->hashCode;
}

string UGit::GetShortHashCode(const Commit* commit) {
	string hashCode = GetHashCode(commit);

	return hashCode.substr(0, 8);
}

void UGit::DestroyCommit(Commit* commit) {
	delete commit;
}

string GenerateRandomHashCode() {
	const string characters = "abcdefghijklmnopqrstuvwxyz0123456789";
	const int codeLenght = 40;
	string hashCode;
	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < codeLenght; ++i) {
		int index = rand() % characters.length();
		hashCode += characters[index];
	}
	return hashCode;
}