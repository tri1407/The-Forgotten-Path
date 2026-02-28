#include <bits/stdc++.h>
using namespace std;
class Item {
public:
    string name;
    string id;
};
Item rope;
class Recipe {
public:
    string name;
    map<string, int> ingredients;
    Item result;
};
vector<Recipe> recipes;
class Area {
public:
    string name;
    map<string, int> gathered_resources;
};
Area plains;
class Character {
public:
    string name;
    string id;
    int lvl = 1;
    int total_exp = 11;
    int exp = 0;
    map<string, int> resources = {};
    vector<Item> items = {};
    Area area = plains;
    void add_exp(int added_exp) {
        exp += added_exp;
        while (exp >= total_exp) {
            exp -= total_exp;
            lvl++;
            total_exp = lvl * lvl + 10;
            cout << "Level up! You reached level " << lvl << "." << endl;
        }
    }
    void add_resource(string resource, int amount) {
        if (resources.count(resource)) {
            resources[resource] += amount;
        } else {
            resources.insert({resource, amount});
        }
        cout << "+ " << amount << " " << resource << endl;
    }
    void info() {
        cout << "\nINFO:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "LVL: " << lvl << endl;
        cout << "EXP: " << exp << "/" << total_exp << endl;
    }
    void pack() {
        if ((resources.empty()) && (items.empty())) {
            cout << "You have no item!" << endl;
            return;
        }
        cout << "INVENTORY:" << endl;
        if (!resources.empty()) {
            cout << "Resources:" << endl;
            for (const auto& pair : resources) {
                cout << "- " << pair.first << ": " << pair.second << endl;
            }
        }
        if (!items.empty()) {
            cout << endl;
            cout << "Items:" << endl;
            for (Item item : items) {
                cout << "Name: " << item.name << endl;
                cout << "ID: " << item.id << endl;
                cout << endl;
            }
        }
    }
    void gather() {
        int total = 0;
        for (const auto& pair : area.gathered_resources) {
            total += pair.second;
        }
        int r = rand() % total + 1;
        int cumulative = 0;
        for (const auto& pair : area.gathered_resources) {
            cumulative += pair.second;
            if (r <= cumulative) {
                int r2 = rand() % 5;
                add_resource(pair.first, r2 + 1);
                return;
            }
        }
    }
    void recipe() {
        cout << "RECIPES:" << endl;
        cout << "Rope:" << endl;
        cout << "- leaf: 4" << endl;
    }
    bool canCraft(const Recipe& recipe, int amount) {
        for (auto& pair : recipe.ingredients) {
            string name = pair.first;
            int need = pair.second * amount;
            if (resources[name] < need)
                return false;
        }
        return true;
    }
    void craft() {
        string item_name;
        cout << "Enter item's name: ";
        getline(cin, item_name);
        int amount;
        cout << "Enter item's amount: ";
        cin >> amount;
        for (Recipe recipe : recipes) {
            if (recipe.name == item_name) {
                if (!canCraft(recipe, amount)) {
                    cout << "Not enough resources!" << endl;
                    return;
                }
                for (auto& pair : recipe.ingredients) {
                    string name = pair.first;
                    int need = pair.second * amount;
                    resources[name] -= need;
                }
                cout << "Craft success!" << endl;
                return;
            }
        }
        cout << "This name does not exist!" << endl;
    }
};
class World {
public:
    string name;
    string id;
    vector<Character> characters = {};
    void create_character() {
        Character new_character;
        string name;
        cout << "Enter character's name: ";
        getline(cin, name);
        new_character.name = name;
        string id;
        while (true) {
            cout << "Enter character's ID: ";
            getline(cin, id);
            bool existed = false;
            for (Character character : characters) {
                if (character.id == id) {
                    existed = true;
                    break;
                }
            }
            if (existed) {
                cout << "This ID is not available!" << endl;
            } else {
                new_character.id = id;
                break;
            }
        }
        characters.push_back(new_character);
        cout << "The character was created successfully!" << endl;
    }
    void delete_character() {
        string id;
        cout << "Enter character's ID: ";
        getline(cin, id);
        for (int i = 0; i < characters.size(); i++) {
            if (characters[i].id == id) {
                characters.erase(characters.begin() + i);
                cout << "The character was deleted successfully!" << endl;
                return;
            }
        }
        cout << "This ID does not exist!" << endl;
    }
    void select_character() {
        string id;
        cout << "Enter character's ID: ";
        getline(cin, id);
        for (Character& character : characters) {
            if (character.id == id) {
                Character& cur_character = character;
                cout << "The character was select successfully!" << endl;
                while (true) {
                    string cmd;
                    cout << "> ";
                    getline(cin, cmd);
                    if (cmd == "help") {
                        cout << "\nCOMMANDS:" << endl;
                        cout << "- info" << endl;
                        cout << "- pack" << endl;
                        cout << "- gather" << endl;
                        cout << "- recipe" << endl;
                        cout << "- craft" << endl;
                        cout << "- escape" << endl;
                    } else if (cmd == "info") {
                        cur_character.info();
                    } else if (cmd == "pack") {
                        cur_character.pack();
                    } else if (cmd == "gather") {
                        cur_character.gather();
                    } else if (cmd == "recipe") {
                        cur_character.recipe();
                    } else if (cmd == "craft") {
                        cur_character.craft();
                    } else if (cmd == "escape") {
                        break;
                    } else {
                        cout << "Invalid input! Please try again." << endl;
                    }
                }
                return;
            }
        }
        cout << "This ID does not exist!" << endl;
    }
    void display_all_characters() {
        if (characters.empty()) {
            cout << "You have no character!" << endl;
            return;
        }
        cout << "CHARACTERS:" << endl;
        for (Character character : characters) {
            cout << "Name: " << character.name << endl;
            cout << "ID: " << character.id << endl;
            cout << "LVL: " << character.lvl << endl;
            cout << "EXP: " << character.exp << "/" << character.total_exp << endl;
            cout << endl;
        }
    }
};
class Menu {
public:
    vector<World> worlds = {};
    void create_world() {
        World new_world;
        string name;
        cout << "Enter world's name: ";
        getline(cin, name);
        new_world.name = name;
        string id;
        while (true) {
            cout << "Enter world's ID: ";
            getline(cin, id);
            bool existed = false;
            for (World world : worlds) {
                if (world.id == id) {
                    existed = true;
                    break;
                }
            }
            if (existed) {
                cout << "This ID is not available!" << endl;
            } else {
                new_world.id = id;
                break;
            }
        }
        worlds.push_back(new_world);
        cout << "The world was created successfully!" << endl;
    }
    void delete_world() {
        string id;
        cout << "Enter world's ID: ";
        getline(cin, id);
        for (int i = 0; i < worlds.size(); i++) {
            if (worlds[i].id == id) {
                worlds.erase(worlds.begin() + i);
                cout << "The world was deleted successfully!" << endl;
                return;
            }
        }
        cout << "This ID does not exist!" << endl;
    }
    void enter_world() {
        string id;
        cout << "Enter world's ID: ";
        getline(cin, id);
        for (World& world : worlds) {
            if (world.id == id) {
                World& cur_world = world;
                cout << "The world was entered successfully!" << endl;
                while (true) {
                    string cmd;
                    cout << "> ";
                    getline(cin, cmd);
                    if (cmd == "help") {
                        cout << "COMMANDS:" << endl;
                        cout << "- help" << endl;
                        cout << "- create" << endl;
                        cout << "- delete" << endl;
                        cout << "- select"  << endl;
                        cout << "- display" << endl;
                        cout << "- escape" << endl;
                    } else if (cmd == "create") {
                        cur_world.create_character();
                    } else if (cmd == "delete") {
                        cur_world.delete_character();
                    } else if (cmd == "select") {
                        cur_world.select_character();
                    } else if (cmd == "display") {
                        cur_world.display_all_characters();
                    } else if (cmd == "escape") {
                        break;
                    } else {
                        cout << "Invalid input! Please try again." << endl;
                    }
                }
                return;
            }
        }
        cout << "This ID does not exist!" << endl;
    }
    void display_all_worlds() {
        if (worlds.empty()) {
            cout << "You have no world!" << endl;
            return;
        }
        cout << "\nWORLDS:" << endl;
        for (World world : worlds) {
            cout << "Name: " << world.name << endl;
            cout << "ID: " << world.id << endl;
            cout << endl;
        }
    }
};
int main() {
    srand(time(0));
    Menu menu;
    rope.name = "rope";
    rope.id = "rope";
    Recipe rope_recipe;
    rope_recipe.name = "rope";
    rope_recipe.ingredients = {{"leaf", 4}};
    rope_recipe.result = rope;
    recipes.push_back(rope_recipe);
    plains.name = "Plains";
    plains.gathered_resources = {
        {"leaf", 30},
        {"pebble", 20},
        {"wood", 18},
        {"flower", 12},
        {"berry", 8},
        {"mushroom", 7},
        {"herb", 5}
    };
    cout << "THE FORGOTTEN PATH" << endl;
    cout << "(c) The Syntax 2026. All rights reserved." << endl;
    cout << "Version 0.1" << endl;
    while (true) {
        string cmd;
        cout << "> ";
        getline(cin, cmd);
        if (cmd == "help") {
            cout << "\nCOMMANDS:" << endl;
            cout << "- help" << endl;
            cout << "- create" << endl;
            cout << "- delete" << endl;
            cout << "- display" << endl;
            cout << "- escape" << endl;
        } else if (cmd == "create") {
            menu.create_world();
        } else if (cmd == "delete") {
            menu.delete_world();
        } else if (cmd == "enter") {
            menu.enter_world();
        } else if (cmd == "display") {
            menu.display_all_worlds();
        } else if (cmd == "escape") {
            break;
        } else {
            cout << "Invalid input! Please try again." << endl;
        }
    }
}
