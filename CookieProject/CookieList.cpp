/*
    Kelley, Hayden

    CS A250
    Project (Part B)
*/
#include "Cookie.h"
#include "CookieDB.h"
#include "CookieList.h"
#include "Testing.h"

#include <string>
#include <iostream>
#include <set>

using namespace std;

void CookieList::addCookie(const Cookie& newCookie)
{
    Node* nCookie = new Node(newCookie, nullptr);
    if (count == 0) {
        last = first = nCookie;
    }
    else {
        last->setNext(nCookie);
        last = nCookie;
    }
    count++;
}

void CookieList::addCookie(const string& name, size_t calories, 
            size_t servings, const set<string>& ingredients) {
    addCookie(Cookie(name, calories, servings, ingredients));
}

size_t CookieList::getCount() const {
    return count;
}

Node* CookieList::getCookieLocation(size_t cookieLocation) const
{
    Node* temp = first;
    size_t cookieFinder = cookieLocation - 1;
    for (size_t i = 0; i < cookieFinder; i++)
    {
        temp = temp->getNext();
    }
    return temp;
}

bool CookieList::isEmpty() const {
    return (count == 0);
}

bool CookieList::searchCookie(const string& cookieName) const
{
    Node* temp = first;
    
    while (temp != nullptr)
    {
        if (temp->getCookie().getName() == cookieName)
            return true;
        else {
            temp = temp->getNext();
        }
    }
    return false;
}

void CookieList::printAllCookies() const
{
    if (count == 0) {
        cout << "List is empty";
    }
    else
    {
        Node* temp = first;
        while (temp != nullptr)
        {
            cout << "    " << temp->getCookie().getName() << '\n';
            temp = temp->getNext();
        }
    }
    
}

void CookieList::printCalories(size_t cookieSelection) const
{
    getCookieLocation(cookieSelection)->getCookie().printCalories();
}

void CookieList::printLimitedCalories(size_t setCalories) const
{
    Node* temp = first;
    while (temp != nullptr)
    {
        if (temp->getCookie().getCalories() < setCalories)
            temp->getCookie().printCalories();
        temp = temp->getNext();
    }
}

void CookieList::printCookieSelection()
{
    Node* temp = first;
    for (size_t i = 0; i < count; i++)
    {
        cout << "    " << i + 1 << ". ";
        cout << temp->getCookie().getName() << endl;
        temp = temp->getNext();
    }
}

void CookieList::printRecipe(size_t cookieSelection)
{
    getCookieLocation(cookieSelection)->getCookie().printRecipe();
}

void CookieList::clearList()
{
    last = nullptr;
    Node* temp = first;
    while (temp != nullptr)
    {
        first = temp->getNext();
        delete temp;
        count--;
        temp = first;
    }
    
}

void CookieList::rollThreeCookies()
{
    size_t val1, val2, val3;
    srand(static_cast <unsigned int>(time(0)));
    val1 = val2 = val3 = 0;
    while ((val1 == val2) || (val2 == val3) || (val3 == val1))
    {
        val1 = rand() % count + 1;
        val2 = rand() % count + 1;
        val3 = rand() % count + 1;
    }
    printFullCookie(val1);
    printFullCookie(val2);
    printFullCookie(val3);
}

void CookieList::printFullCookie(size_t cookieSelection)
{
    cout << "    "
        << getCookieLocation(cookieSelection)->
                getCookie().getName()
        << '\n' << string(8, ' ') << "Calories: "
        << getCookieLocation(cookieSelection)->
                getCookie().getCalories()
        << '\n' << string(8, ' ') << "Servings: "
        << getCookieLocation(cookieSelection)->
                getCookie().getServings()
        << endl;
    getCookieLocation(cookieSelection)->
            getCookie().printIngredients();
    cout << endl;
}


CookieList::~CookieList() {
    this->clearList();
}
// copy constructor
CookieList::CookieList(const CookieList& otherList)
{
    Node* temp = otherList.first;
    for (size_t i = 0; i < otherList.count; i++)
    {
        this->addCookie(temp->getCookie());
        temp = temp->getNext();
    }
    
}
// assignment operator
CookieList& CookieList::operator=(const CookieList& otherList)
{
    if (&otherList != this)
    {
        if (!this->isEmpty())
        {
            this->clearList();
        }
        Node* temp = otherList.first;
        for (size_t i = 0; i < otherList.count; i++)
        {
            this->addCookie(temp->getCookie());
            temp = temp->getNext();
        }
    }
    else {
        cerr << "Attempted assignment on self";
    }
    return *this;
}
