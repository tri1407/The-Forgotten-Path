#include <bits/stdc++.h>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;
bool is_integer(const string& s) {
    if (s.empty()) {
        return false;
    }
    int i = (s[0] == '-') ? 1 : 0;
    if (i == s.size()) {
        return false;
    }
    while (i < s.size()) {
        if (!isdigit(s[i])) {
            return false;
        }
        i++;
    }
    return true;
}
class Area {
public:
    string name;
<<<<<<< HEAD
    string description;
    map<string, string> directions;
    map<string, int> gathered_resources;
    Area() {
        directions = {};
    }
};
unordered_map<string, Area> areas = {};
=======
    static int next_id;
    int id;
    Item(string name_) {
        name = name_;
        id = next_id++;
    }
};
int Item::next_id = 0;
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
class Recipe {
public:
    string name;
    map<string, int> ingredients;
<<<<<<< HEAD
};
unordered_map<string, Recipe> recipes = {};
class Player {
=======
    Recipe(string name_, map<string, int> ingredients_) {
        name = name_;
        ingredients = ingredients_;
    }
};
vector<Recipe> recipes;
class Area {
public:
    string name;
    string description;
    map<string, Area*> directions;
    map<string, int> gathered_resources;
    vector<Item> items;
    Area() {
        directions = {};
        items = {};
    }
};
Area silvergrass_plain;
Area quietbrook;
class Character {
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
public:
    string name;
    string id;
    int lvl;
    int total_exp;
    int exp;
<<<<<<< HEAD
    int health;
    string cur_area;
    int time;
    map<string, int> resources;
    Player(string name_, string id_) {
=======
    vector<pair<string, int>> equipments;
    map<string, int> resources;
    vector<Item> items;
    Area area;
    Character(string name_, string id_) {
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
        name = name_;
        id = id_;
        lvl = 1;
        total_exp = 11;
        exp = 0;
<<<<<<< HEAD
        health = 100;
        cur_area = "silvergrass plain";
        time = 0;
=======
        equipments = {{"Left hand", -1},{"Right hand", -1},{"Armor", -1},{"Accessory", -1}};
        resources = {};
        items = {};
        area = silvergrass_plain;
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
    }
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
<<<<<<< HEAD
    void set_time(int amount) {
        time += amount;
        while (time >= 300) {
            time -= 300;
        }
    }
    void profile() {
        cout << "\nPROFILE" << endl;
=======
    Item find_item(int id) {
        for (Item item : items) {
            if (item.id == id) {
                return item;
            }
        }
    }
    void info(int time) {
        cout << "\nINFO:" << endl;
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Level: " << lvl << endl;
        cout << "EXP: " << exp << "/" << total_exp << endl;
<<<<<<< HEAD
        cout << "Health: " << health << endl;
=======
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
        cout << "Time: ";
        if (time < 25) {
            cout << "Early morning";
        } else if (time < 50) {
            cout << "Mid morning";
        } else if (time < 75) {
            cout << "Late morning";
        } else if (time < 100) {
            cout << "Early noon";
        } else if (time < 125) {
            cout << "Mid noon";
        } else if (time < 150) {
            cout << "Late noon";
        } else if (time < 175) {
            cout << "Early afternoon";
        } else if (time < 200) {
            cout << "Mid afternoon";
        } else if (time < 225) {
            cout << "Late afternoon";
        } else if (time < 250) {
            cout << "Early evening";
        } else if (time < 275) {
            cout << "Mid evening";
        } else {
            cout << "Late evening";
        }
        cout << endl;
<<<<<<< HEAD
=======
    }
    void gear() {
        cout << "\nEQUIPMENTS:" << endl;
        for (const auto& pair : equipments) {
            cout << pair.first << ": ";
            if (pair.second == -1) {
                cout << "None" << endl;
            } else {
                cout << find_item(pair.second).name << endl;
            }
        }
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
    }
    void pack() {
        if (resources.empty()) {
            cout << "You have no resource." << endl;
            return;
        }
<<<<<<< HEAD
        cout << "\nRESOURCES" << endl;
        for (const auto& pair : resources) {
            cout << "- " << pair.first << ": " << pair.second << endl;
=======
        cout << "\nINVENTORY:" << endl;
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
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
        }
    }
    void look() {
        cout << endl;
<<<<<<< HEAD
        Area& area = areas[cur_area];
        cout << area.name << endl;
        cout << area.description << endl;
    }
    void go(string direction) {
        Area& area = areas[cur_area];
        if (area.directions.count(direction)) {
            cur_area = area.directions[direction];
            look();
            return;
        }
        cout << "You can't go that way!" << endl;
=======
        cout << area.name << endl;
        cout << area.description << endl;
    }
    void go() {
        string direction;
        cout << "Enter direction: ";
        getline(cin, direction);
        if (area.directions.find(direction) != area.directions.end()) {
            area = *area.directions[direction];
            return;
        }
        cout << "You can't go this way!" << endl;
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
    }
    void gather() {
        Area& area = areas[cur_area];
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
                set_time(1);
                return;
            }
        }
    }
    void recipes_() {
        cout << "\nRECIPES:" << endl;
        for (const auto& [key, recipe] : recipes) {
            cout << recipe.name << endl;
            for (const auto& [resource, amount] : recipe.ingredients) {
                cout << "- " << resource << ": " << amount << endl;
            }
            cout << endl;
        }
    }
    bool canCraft(const Recipe& recipe, int amount) {
        for (auto& pair : recipe.ingredients) {
            string name = pair.first;
            int need = pair.second * amount;
            if (!resources.count(name) || resources[name] < need)
                return false;
        }
        return true;
    }
<<<<<<< HEAD
    void craft(string name, int amount) {
        if (amount <= 0) {
            cout << "Invalid amount!" << endl;
=======
    void take() {
        int id;
        cout << "Enter item's ID: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < area.items.size(); i++) {
            if (area.items[i].id == id) {
                items.push_back(area.items[i]);
                area.items.erase(area.items.begin() + i);
                cout << "Taken." << endl;
                return;
            }
        }
        cout << "This ID does not exist!" << endl;
    }
    void drop() {
        int id;
        cout << "Enter item's ID: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < items.size(); i++) {
            if (items[i].id == id) {
                area.items.push_back(items[i]);
                items.erase(items.begin() + i);
                cout << "Dropped" << endl;
                return;
            }
        }
        cout << "This ID does not exist!" << endl;
    }
    void craft() {
        string item_name;
        cout << "Enter item's name: ";
        getline(cin, item_name);
        int amount;
        cout << "Enter item's amount: ";
        cin >> amount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (amount <= 0) {
            cout << "Invalid amount!" << endl;
            return;
        }
        for (Recipe& recipe : recipes) {
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
                for (int i = 0; i < amount; i++) {
                    Item new_item(recipe.name);
                    items.push_back(new_item);
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
    int time;
    vector<Character> characters;
    World(string name_, string id_) {
        name = name_;
        id = id_;
        characters = {};
        time = 0;
    }
    void set_time(int amount) {
        time += amount;
        while (time >= 300) {
            time -= 300;
        }
    }
    void create_character() {
        string name;
        cout << "Enter character's name: ";
        getline(cin, name);
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
                return;
            }
            break;
        }
        Character new_character(name, id);
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
                        cout << "- gear" << endl;
                        cout << "- pack" << endl;
                        cout << "- look" << endl;
                        cout << "- go" << endl;
                        cout << "- gather" << endl;
                        cout << "- recipe" << endl;
                        cout << "- take" << endl;
                        cout << "- drop" << endl;
                        cout << "- craft" << endl;
                        cout << "- escape" << endl;
                    } else if (cmd == "info") {
                        cur_character.info(time);
                    } else if (cmd == "gear") {
                        cur_character.gear();
                    } else if (cmd == "pack") {
                        cur_character.pack();
                    } else if (cmd == "look") {
                        cur_character.look();
                    } else if (cmd == "go") {
                        cur_character.go();
                        set_time(1);
                    } else if (cmd == "gather") {
                        cur_character.gather();
                        set_time(1);
                    } else if (cmd == "recipe") {
                        cur_character.recipe();
                    } else if (cmd == "take") {
                        cur_character.take();
                        set_time(1);
                    } else if (cmd == "drop") {
                        cur_character.drop();
                        set_time(1);
                    } else if (cmd == "craft") {
                        cur_character.craft();
                        set_time(1);
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
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
            return;
        }
        if (!recipes.count(name)) {
            cout << "This name does not exist!" << endl;
            return;
        }
        Recipe cur_recipe = recipes[name];
        if (!canCraft(cur_recipe, amount)) {
            cout << "Not enough resources!" << endl;
            return;
        }
        for (auto& pair : cur_recipe.ingredients) {
            string ingredient = pair.first;
            int need = pair.second * amount;
            resources[ingredient] -= need;
        }
        add_resource(name, amount);
        set_time(1);
        cout << "Crafted!" << endl;
    }
};
class Menu {
public:
<<<<<<< HEAD
    vector<Player> players;
    Player cur_player = Player("", "");
    void start() {
        cout << "\nSTART" << endl;
        cout << "The Forgotten Path is a text-based RPG game." << endl;
        cout << "In this game, you can survive, explore or combat." << endl;
        cout << "To do an action, you have to type a command with a fixed syntax. (Enter 'help' for commands list)" << endl;
        cout << "The path is being shaped." << endl;
        cout << "Good luck!" << endl;
    }
    void help() {
        cout << "\nCOMMANDS" << endl;
        cout << "- start" << endl;
        cout << "- help" << endl;
        cout << "- say <text>" << endl;
        cout << "- create <name> <id>" << endl;
        cout << "- destroy <id>" << endl;
        cout << "- display" << endl;
        cout << "- select <id>" << endl;
        cout << "- save" << endl;
        cout << "- profile" << endl;
        cout << "- pack" << endl;
        cout << "- look" << endl;
        cout << "- go <direction>" << endl;
        cout << "- gather" << endl;
        cout << "- recipes" << endl;
        cout << "- craft <name> <amount>" << endl;
        cout << "- escape" << endl;
    }
    void say(string text) {
        cout << text << endl;
    }
    void create(string name, string id) {
        for (int i = 0; i < players.size(); i++) {
            if (players[i].id == id) {
                cout << "This ID is not available!" << endl;
=======
    vector<World> worlds = {};
    void create_world() {
        string name;
        cout << "Enter world's name: ";
        getline(cin, name);
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
            }
            break;
        }
        World new_world(name, id);
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
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
                return;
            }
        }
        Player new_player(name, id);
        players.push_back(new_player);
        cout << "Created." << endl;
    }
    void destroy(string id) {
        for (int i = 0; i < players.size(); i++) {
            if (players[i].id == id) {
                if (cur_player.id == id) {
                    cur_player = Player("", "");
                }
                players.erase(players.begin() + i);
                cout << "Destroyed." << endl;
                return;
            }
        }
        cout << "This ID does not exist!" << endl;
    }
    void display() {
        if (players.empty()) {
            cout << "You have no player!" << endl;
            return;
        }
        cout << "\nPLAYERS" << endl;
        for (int i = 0; i < players.size(); i++) {
            cout << "- " << players[i].name << ": " << players[i].id << endl;
        }
    }
    void select(string id) {
        for (int i = 0; i < players.size(); i++) {
            if (players[i].id == id) {
                cur_player = players[i];
                cout << "Selected." << endl;
                return;
            }
        }
        cout << "This ID does not exist!" << endl;
    }
    void save() {
        if (cur_player.id.empty()) {
            cout << "You haven't selected any player yet!" << endl;
            return;
        }
        json saved_player_data;
        saved_player_data[cur_player.id]["name"] = cur_player.name;
        saved_player_data[cur_player.id]["id"] = cur_player.id;
        saved_player_data[cur_player.id]["lvl"] = cur_player.lvl;
        saved_player_data[cur_player.id]["total exp"] = cur_player.total_exp;
        saved_player_data[cur_player.id]["exp"] = cur_player.exp;
        saved_player_data[cur_player.id]["health"] = cur_player.health;
        saved_player_data[cur_player.id]["cur area"] = cur_player.cur_area;
        saved_player_data[cur_player.id]["time"] = cur_player.time;
        saved_player_data[cur_player.id]["resources"] = cur_player.resources;
        ofstream g("data/players.json");
        g << saved_player_data.dump(4);
        cout << "Saved." << endl;
    }
};
Menu menu;
vector<string> tokenizer(string text) {
    vector<string> tokens;
    string cur;
    bool in_quote = false;
    for (char c : text) {
        if (c == '"') {
            in_quote = !in_quote;
            continue;
        }
        if (c == ' ' && !in_quote) {
            if (!cur.empty()) {
                tokens.push_back(cur);
                cur.clear();
            }
        }
        else {
            cur += c;
        }
    }
    if (!cur.empty()) {
        tokens.push_back(cur);
    }
    return tokens;
}
void parser(string cmd) {
    vector<string> tokens = tokenizer(cmd);
    if (tokens[0] == "start") {
        menu.start();
    } else if (tokens[0] == "help") {
        menu.help();
    } else if (tokens[0] == "say") {
        menu.say(tokens[1]);
    } else if (tokens[0] == "create") {
        menu.create(tokens[1], tokens[2]);
    } else if (tokens[0] == "destroy") {
        menu.destroy(tokens[1]);
    } else if (tokens[0] == "display") {
        menu.display();
    } else if (tokens[0] == "select") {
        menu.select(tokens[1]);
    } else if (tokens[0] == "save") {
        menu.save();
    } else if (!menu.cur_player.id.empty()) {
        if (tokens[0] == "profile") {
            menu.cur_player.profile();
        } else if (tokens[0] == "pack") {
            menu.cur_player.pack();
        } else if (tokens[0] == "look") {
            menu.cur_player.look();
        } else if (tokens[0] == "go") {
            menu.cur_player.go(tokens[1]);
        } else if (tokens[0] == "gather") {
            menu.cur_player.gather();
        } else if (tokens[0] == "recipes") {
            menu.cur_player.recipes_();
        } else if (tokens[0] == "craft") {
            if (!is_integer(tokens[2])) {
                cout << "Invalid number! Please try again." << endl;
                return;
            }
            int amount = stoi(tokens[2]);
            menu.cur_player.craft(tokens[1], amount);
        } else {
            cout << "Invalid input! Please try again." << endl;
        }
    } else {
        cout << "Invalid input! Please try again." << endl;
    }
}
int main() {
<<<<<<< HEAD
    ifstream f1("data/areas.json");
    json areas_data;
    f1 >> areas_data;
    for (auto& [key, area] : areas_data.items()) {
        Area new_area;
        new_area.name = area["name"];
        new_area.description = area["description"];
        new_area.gathered_resources = area["gathered resources"];
        new_area.directions = area["directions"];
        areas[key] = new_area;
    }
    ifstream f2("data/recipes.json");
    json recipes_data;
    f2 >> recipes_data;
    for (auto& [key, recipe] : recipes_data.items()) {
        Recipe new_recipe;
        new_recipe.name = recipe["name"];
        new_recipe.ingredients = recipe["ingredients"];
        recipes[key] = new_recipe;
    }
    ifstream f3("data/players.json");
    if (!(f3.peek() == ifstream::traits_type::eof())) {
        json players_data;
        f3 >> players_data;
        for (auto& [key, player] : players_data.items()) {
            Player new_player(player["name"], player["id"]);
            new_player.lvl = player["lvl"];
            new_player.total_exp = player["total exp"];
            new_player.exp = player["exp"];
            new_player.health = player["health"];
            new_player.cur_area = player["cur area"];
            new_player.time = player["time"];
            new_player.resources = player["resources"];
            menu.players.push_back(new_player);
        }
    }
    cout << "THE FORGOTTEN PATH: Journey Arc" << endl;
=======
    srand(time(0));
    Menu menu;
    Item rope("rope");
    Recipe rope_recipe("rope", {{"leaf", 4}});
    recipes.push_back(rope_recipe);
    silvergrass_plain.name = "Silvergrass Plain";
    silvergrass_plain.description = "The wind moves softly through tall silver grass, bending it like waves across an endless sea. A narrow dirt path cuts through the quiet field, leading toward distant hills. The air is calm, and the world feels wide and still.";
    silvergrass_plain.gathered_resources = {
        {"leaf", 30},
        {"pebble", 20},
        {"wood", 18},
        {"flower", 12},
        {"berry", 8},
        {"mushroom", 7},
        {"herb", 5}
    };
    silvergrass_plain.directions["north"] = &quietbrook;
    quietbrook.name = "Quietbrook";
    quietbrook.description = "A narrow brook flows quietly through the tall grass, its clear water glinting in the light. A small wooden bridge crosses to the other side, worn smooth by time. The gentle sound of running water breaks the silence of the plain.";
    quietbrook.gathered_resources = {
        {"leaf", 30},
        {"pebble", 20},
        {"wood", 18},
        {"flower", 12},
        {"berry", 8},
        {"mushroom", 7},
        {"herb", 5}
    };
    quietbrook.directions["south"] = &silvergrass_plain;
    cout << "THE FORGOTTEN PATH" << endl;
>>>>>>> bd3c4645b28d00091dcada70baeb0818cc5f96e6
    cout << "(c) The Syntax 2026. All rights reserved." << endl;
    cout << "Version 0.3 (Enter 'start' for more information)" << endl;
    while (true) {
        string cmd;
        cout << "> ";
        getline(cin, cmd);
        if (cmd == "escape") {
            break;
        } else {
            parser(cmd);
        }
    }
}
