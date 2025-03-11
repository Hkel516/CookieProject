/*
	Kelley, Hayden

	CS A250
	Project (Part A)
*/

#include "Cookie.h"

#include <string>
#include <iostream>
#include <set>

using namespace std;


// accessor functions
string Cookie::getName() const {
	return name;
}

size_t Cookie::getServings() const {
	return servings;
}

size_t Cookie::getCalories() const {
	return calories;
}

set<string> Cookie::getIngredients() const {
	return ingredients;
}
Cookie Cookie::getCookie() const {
	return Cookie();
}

// mutator functions
void Cookie::setName(const string& newName) {
	name = newName;
}

void Cookie::setServings(size_t newServings) {
	servings = newServings;
}


void Cookie::setCalories(size_t newCalories) {
	calories = newCalories;
}

void Cookie::setIngredients(const vector<string>& newIngredients)
{
	for (const string& i : newIngredients) {
		ingredients.insert(i);
	}

}

void Cookie::printCalories() const
{
	cout << "    " << this->name
		<< " (calories: " << calories << ")" << '\n';
}
void Cookie::printRecipe() const
{
	
	cout << "    Recipe for " << name << '\n'
		<< "        Servings: " << servings << '\n';
	this->printIngredients();
}
void Cookie::printIngredients() const
{
	cout << "        Ingredients: ";
	size_t size = ingredients.size() - 1;
	auto iter = ingredients.begin();
	for (size_t i = 0; i < size; i++)
	{	
		cout << *iter << ", ";
		iter++;
	}
	cout << *iter << '\n'; 
}

