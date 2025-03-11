/*
    Kelley, Hayden

    CS A250
    Project (Part A)
*/

#ifndef COOKIE_H
#define COOKIE_H

#include <string>
#include <set>
#include <vector>


class Cookie
{

    public:
        Cookie() : name("NA"), calories(0), servings(0) {}
        Cookie(const std::string& newName, size_t newCalories,
            size_t newServings, const std::set<std::string>& newIngredients) :
            name(newName), calories(newCalories), servings(newServings), 
            ingredients(newIngredients) {}
        
        // Accessor functions
        std::string getName() const;
        size_t getCalories() const;
        size_t getServings() const;
        std::set<std::string> getIngredients() const;
        Cookie getCookie() const;

        // Mutator functions
        void setName(const std::string& newName);
        void setCalories(size_t newCalories);
        void setServings(size_t newServings);
        void setIngredients(const std::vector<std::string>& newVector);

        // Print functions
        void printRecipe() const;
        void printIngredients() const;
        void printCalories() const;
        
        // Destructor
        ~Cookie() {}
        
    private:
        std::string name;
        size_t calories, servings; // is this fine?
        std::set<std::string> ingredients; 
};





#endif