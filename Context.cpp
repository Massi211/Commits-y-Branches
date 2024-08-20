#include "Context.h"
#include "DateTime.h"
#include "User.h"
#include <iostream>

using UUser::User;
using UDateTime::DateTime;

UUser::User* UContext::GetCurrentUser() {
	static User* currentUser = UUser::CreateUser("User");
	return currentUser;
}

UDateTime::DateTime* UContext::GetNow() {
	return UDateTime::Now();
}

void UContext::DestroyContext() {

	User* currentUser = GetCurrentUser();
	UUser::DestroyUser(currentUser);

	DateTime* now = GetNow();
	UDateTime::DestroyDateTime(now);
}