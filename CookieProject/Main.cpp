/*
	Kelley, Hayden

	CS A250
	Project (Part Final)
*/
#include "Cookie.h"
#include "CookieList.h"
#include "CookieDB.h"
#include "Testing.h"
#include "Interface.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
	
	CookieList cookies;
	createCookieList(cookies);
	displayMenu();
	processChoice(cookies);
	
	system("Pause");

	return 0;
}