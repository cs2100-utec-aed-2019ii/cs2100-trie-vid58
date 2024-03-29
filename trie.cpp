

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
