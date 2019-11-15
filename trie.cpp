/*
#include <iostream>
#include <map>
using namespace std;

int main(){

    map<string,double>::iterator i;
    map<string, double > personas;
    personas["juan"] = 300.0;
    personas["pedro"] = 400.0;

    for(i = personas.begin(); i != personas.end();i++){
        cout<< i->first <<" : "<<i->second<<endl;
    }
}*/

/*
#include <iostream>
#include <map>
//#include <algorithm>
//#include <memory>
using namespace std;




class Trie {

    struct Node;
    typedef unique_ptr<Node> spNode;

    struct Node {
        map<char, spNode> children;
        bool isLeaf;
        Node() : isLeaf{false} {}
    };

    spNode root;

public:
    Trie():root{nullptr}{};
    void insert(const string& str);
    bool search(const string& str);
};

//Trie::Trie():root{nullptr}{}

void Trie::insert(const string& str) {
    if (root == nullptr) {
        unique_ptr<Node> node(new Node());
        root = move(node);
    }

    Node *temp = root.get();
    for (const char& c : str) {
        if (temp->children.find(c) == temp->children.end()) {//if char not in map
            unique_ptr<Node> node(new Node());
            temp->children[c] = move(node);
        }

        temp = temp->children[c].get();
    }

    temp->isLeaf = true;
}

bool Trie::search(const std::string &str) {
    if (root == nullptr) return false;

    Node *temp = root.get();
    for (const char& c : str) {
        if (temp->children.find(c) == temp->children.end())
            return false;
        temp = temp->children[c].get();
    }
    return (temp->isLeaf);
}

int main (void) {
    string words[] = { "Hello", "hi", "hey", "howdy", "ho"};
    Trie test;

    for (const auto& str : words) {
        test.insert(str);
    }


    if (test.search("Hello"))
        cout << " 'Hello' is found in the trie\n";
    else
        cout <<" 'Hello' is not found in the trie\n";

    if (test.search("yo"))
        cout << " 'yo' is found in the trie\n";
    else
        cout << " 'yo' is not found in the trie\n";


}*/

#include <iostream>
#include <map>
using namespace std;

struct Trie {

    map<char, Trie*> children;
    bool is_node;

};

Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->is_node = false;
    return node;

}

void insert(Trie*& root, const string& str)
{
    if (root == nullptr) {
        root = getNewTrieNode();
    }
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];

        if (temp->children.find(x) == temp->children.end())
            temp->children[x] = getNewTrieNode();

        temp = temp->children[x];
    }

    temp->is_node = true;
}

bool search(Trie* root, const string& str)
{
    if (root == nullptr)
        return false;

    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {

        temp = temp->children[str[i]];

        if (temp == nullptr)
            return false;
    }

    return temp->is_node;
}

void eliminar(Trie* root, const string& str){
    Trie* temp = root;

    for (int i = 0; i < str.length(); i++) {
        char x = str[i];

        if (temp->children.find(x) == temp->children.end())
            return;

        temp = temp->children[x];
    }

    temp->is_node = false;
}

void imprimir(Trie* root, const string str)
{
    Trie* temp=root;
    if(temp->is_node)
        cout << str<< endl;
    for(auto &i:temp->children)
        imprimir(i.second, str+i.first);
}
int main()
{
    Trie* root = nullptr;

    insert(root, "ya");
    cout << search(root, "ya") << " ";

    insert(root, "ye");
    cout << search(root, "ye") << " ";

    insert(root, "yi");
    cout << search(root, "yi") << " ";

    cout << search(root, "yo") << " ";

    insert(root, "yu");
    cout << search(root, "yu") << " ";

    eliminar(root,"yu");
    cout << search(root, "yu") << endl;

    imprimir(root," ");
    return 0;
}
