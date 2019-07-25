#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    map<char, TrieNode*> children;
    bool endofword;
    TrieNode()
    {
        endofword = false;
    }
};

void insert(TrieNode *root, string word) {
    for (int i = 0; i < word.length(); i++) {
        // cout<<ch<<" ";
        char ch = word[i];
        if (root->children.find(ch) == root->children.end()) {
            root->children[ch] = new TrieNode();
        }
        root = root->children[ch];
    }
    // cout<<endl;
    root->endofword = true;
}

bool prefixSearch(TrieNode *root, string word) {
    
  for (int i = 0; i < word.length(); i++) {
      char ch = word[i];
        //  cout<<ch<<" ";
        if (root->children.find(ch) != root->children.end()) {
            root = root->children[ch];
        }
        else {
            return false;
        }
    }
    return true;
}

TrieNode *getPrefixNode(TrieNode *root, string word) {
      for (int i = 0; i < word.length(); i++) {
        char ch = word[i];
        if (root->children.find(ch) != root->children.end()) {
            root = root->children[ch];
        }
        else {
            break;
        } 
    }
    return root;
}

void getAllSuggestions(TrieNode *root, string suggestion, vector<string> &ans) {
    if (root->endofword) {
        ans.push_back(suggestion);
        return;
    }

    for (auto node:root->children) {
        suggestion.push_back(node.first);
        getAllSuggestions(node.second, suggestion, ans);
        suggestion.pop_back();
    }

    return;
}

int main()
{
    string s[] = {
        "Hi",
        "This",
        "First",
        "Auto",
        "Suggestions",
        "System",
        "AutoConnected"
    };

    TrieNode *root = new TrieNode();

    for (int i = 0; i < 7; i++) {
        insert(root, s[i]);
    }

    string word = "Aut";
    bool found = prefixSearch(root, word);
    if (found)
    cout<<"Aut found\n";
    else
    cout<<"Not found\n";

    vector<string>suggestions;
    TrieNode *node = getPrefixNode(root, word);
                
    getAllSuggestions(node, "", suggestions);

    if (suggestions.size()) cout<<"Here are your suggestions\n";
    else cout<<"No suggestions\n";

    for (auto suggesstion:suggestions) {
        cout<<word + suggesstion<<"\n";
    }

}