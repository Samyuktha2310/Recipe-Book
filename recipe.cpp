#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recipe class to store recipe details
class Recipe {
private:
    string name;
    string ingredients;
    string instructions;

public:
    // Constructor to initialize a recipe
    Recipe(string n, string ingr, string instr) : name(n), ingredients(ingr), instructions(instr) {}

    // Display the recipe details
    void displayRecipe() const {
        cout << "Recipe Name: " << name << endl;
        cout << "Ingredients: " << ingredients << endl;
        cout << "Instructions: " << instructions << endl;
        cout << "-----------------------------" << endl;
    }

    // Get the name of the recipe (for searching)
    string getName() const {
        return name;
    }
};

// RecipeBook class to manage multiple recipes
class RecipeBook {
private:
    vector<Recipe> recipes;

public:
    // Add a new recipe to the book
    void addRecipe(const Recipe& recipe) {
        recipes.push_back(recipe);
        cout << "Recipe added successfully!" << endl;
    }

    // Display all recipes in the book
    void displayAllRecipes() const {
        if (recipes.empty()) {
            cout << "No recipes available." << endl;
        } else {
            for (const auto& recipe : recipes) {
                recipe.displayRecipe();
            }
        }
    }

    // Search for a recipe by name
    void searchRecipe(const string& recipeName) const {
        bool found = false;
        for (const auto& recipe : recipes) {
            if (recipe.getName() == recipeName) {
                recipe.displayRecipe();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Recipe not found!" << endl;
        }
    }

    // Delete a recipe by name
    void deleteRecipe(const string& recipeName) {
        for (auto it = recipes.begin(); it != recipes.end(); ++it) {
            if (it->getName() == recipeName) {
                recipes.erase(it);
                cout << "Recipe deleted successfully!" << endl;
                return;
            }
        }
        cout << "Recipe not found!" << endl;
    }
};

// Main menu for the recipe book application
void displayMenu() {
    cout << "\nRecipe Book Menu:\n";
    cout << "1. Add a Recipe\n";
    cout << "2. Display All Recipes\n";
    cout << "3. Search for a Recipe\n";
    cout << "4. Delete a Recipe\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    RecipeBook myRecipeBook;
    int choice;
    string name, ingredients, instructions;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Ignore newline character left in the input buffer

        switch (choice) {
        case 1:
            cout << "Enter the recipe name: ";
            getline(cin, name);
            cout << "Enter the ingredients: ";
            getline(cin, ingredients);
            cout << "Enter the instructions: ";
            getline(cin, instructions);
            myRecipeBook.addRecipe(Recipe(name, ingredients, instructions));
            break;

        case 2:
            myRecipeBook.displayAllRecipes();
            break;

        case 3:
            cout << "Enter the recipe name to search: ";
            getline(cin, name);
            myRecipeBook.searchRecipe(name);
            break;

        case 4:
            cout << "Enter the recipe name to delete: ";
            getline(cin, name);
            myRecipeBook.deleteRecipe(name);
            break;

        case 5:
            cout << "Exiting the Recipe Book application." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
