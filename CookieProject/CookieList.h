/*
	Kelley, Hayden

	CS A250
	Project (Part B)
*/
#ifndef COOKIELIST_H
#define COOKIELIST_H

#include "Cookie.h"

class Node
{
public:
	Node() : cookie(), next(nullptr) {}
	Node(const Cookie& newCookie, Node* newNext)
		: cookie(newCookie), next(newNext) {}
	Cookie& getCookie() { return cookie; }
	Node* getNext() const { return next; }
	void setCookie(const Cookie& newCookie) { cookie = newCookie; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	Cookie cookie;
	Node* next;
};

class CookieList
{
public:
	// Default constructor
	CookieList() : first(nullptr), last(nullptr), count(0) {}
	
	// Functions addCookie
	void addCookie(const Cookie& newCookie);

	// Overloaded ver.
	void addCookie(const std::string& name, size_t calories, 
		size_t servings, const std::set<std::string>& ingredients);

	// Accessor function
	size_t getCount() const;
	
	// Boolean Functions
	bool isEmpty() const;
	bool searchCookie(const std::string& cookieName) const;

	// Print Functions
	void printAllCookies() const;
	void printCalories(size_t cookieSelection) const;
	void printLimitedCalories(size_t calories) const;
	void printCookieSelection();
	void printRecipe(size_t cookieSelection);
	void printFullCookie(size_t cookieSelection);

	// Random Function
	void rollThreeCookies();

	// Function clearList
	void clearList();

	// The Big Three

	// Destructor
	~CookieList();

	// Copy Constructor
	CookieList(const CookieList&);

	// Overloaded Assignment Operator
	CookieList& operator=(const CookieList&);

private:
	Node* getCookieLocation(size_t cookieLocation) const;
	Node* first;
	Node* last;
	size_t count;
};

#endif

