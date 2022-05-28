#include <iostream>
#include <string>

#define ALPHABET_SIZE 26

struct TRIE_Node {

    char key;
    bool canBeFinal = false;

    std::string translation;
    TRIE_Node* children[ALPHABET_SIZE + 1];
    bool presenceMap[ALPHABET_SIZE + 1] = {false };

};


TRIE_Node* TRIE_createNode(char key){

    auto* tn = new TRIE_Node;
    tn->key = key;

    return tn;

}

TRIE_Node* TRIE_add(TRIE_Node* root, std::string word, const std::string& translation){

    if(word.empty()){

        root->canBeFinal = true;
        root->translation = translation;

        return root;

    }

    if(!root->presenceMap[word[0] - 'a']){

        root->children[word[0]-'a'] = TRIE_createNode(word[0]);

    }

    root->children[word[0] - 'a'] = TRIE_add(
            root->children[word[0] - 'a'],
            word.substr(1, word.length()),
            translation);
    root->presenceMap[word[0] - 'a'] = true;

    return root;

}

std::string TRIE_translate(TRIE_Node* root, std::string word){

    if(word.empty()){

        if(root->canBeFinal) return root->translation;
        return "-";

    }

    if(root->presenceMap[word[0]-'a'])
        return TRIE_translate(root->children[word[0]-'a'],word.substr(1,word.length()));
    else return "-";

}

void TRIE_prefix(TRIE_Node* root, std::string prefix){

    if(prefix.empty()){

        if(root->canBeFinal){

            std::cout << root->translation << std::endl;

        }

        for(int i = 0; i < ALPHABET_SIZE; i++){

            if(root->presenceMap[i]) TRIE_prefix(root->children[i],prefix);

        }

        return;
    }

    if(root->presenceMap[prefix[0]-'a'])
        TRIE_prefix(root->children[prefix[0]-'a'],prefix.substr(1,prefix.length()));
    else
        return;

}

TRIE_Node* TRIE_cleanup(TRIE_Node* root){

    if(root == nullptr) return root;


    for(int i = 0; i < ALPHABET_SIZE; i++){

        root->children[i] = TRIE_cleanup(root->children[i]);
        delete root->children[i];
    }

    return root;
}



int main() {

    auto* trie = TRIE_createNode(' ');
    trie = TRIE_add(trie, "dog", "pies");
    trie = TRIE_add(trie,"cat","kot");
    trie = TRIE_add(trie,"do","robic");
    trie = TRIE_add(trie,"doggie","piesek");
    trie = TRIE_add(trie,"doggies","pieski");
    trie = TRIE_add(trie,"dolphin","delfin");
    trie = TRIE_add(trie,"ant","mrowka");
    trie = TRIE_add(trie,"zzz","xxx");


    TRIE_prefix(trie,"doggiess");

    trie = TRIE_cleanup(trie);

    return 0;
}
