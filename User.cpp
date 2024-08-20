#include "User.h"
#include <iostream>
#include <string>

using std::string;

struct UUser::User {
	string nickname;
	string name;
	string lastName;
};

UUser::User* UUser::CreateUser(string nickname) {
	User* newUser = new User;
	newUser->nickname = nickname;
	newUser->name = "";
	newUser->lastName = "";

	return newUser;
}

string UUser::GetNickName(const User* user) {
		return user->nickname;
}

string UUser::GetLastName(const User* user) {
	return user->lastName;
}

string UUser::GetName(const User* user) {
	return user->name;
}

void UUser::SetName(User* user, string name) {
	user->name = name;
}

void UUser::SetLastName(User* user, string lastName) {
	user->lastName = lastName;
}

void UUser::DestroyUser(User* user) {
	delete user;
}
