#include <iostream>
#include <string>

#define NUM_CHAR 26

class Trie {
private:
    Trie *characters[NUM_CHAR];
    bool isEnd;

    void displayCharacters(std::ostream& os, const std::string& word) const {
        std::string newWord = word;
        if(this->isEnd) 
            os << word << std::endl;

        for(int i = 0; i < NUM_CHAR; i++) {
            if(this->characters[i]) {
                newWord.append(std::to_string(i+97));
                this->characters[i]->displayCharacters(os, newWord);
            }
        }
    }
public:
    Trie() 
    : isEnd(false) 
    {
        for(int i = 0; i < NUM_CHAR; ++i) {
            this->characters[i] = nullptr;
        }
    }

    ~Trie() {
        for(int i = 0; i < NUM_CHAR; ++i) {
            if(this->characters[i]) delete characters[i];
        }
    }

    bool insert(const std::string& word) {
        Trie *tmp = this;
        const uint length = word.length();

        for(int i = 0; i < length; ++i) {
            if(!tmp->characters[word[i]-97])
                tmp->characters[word[i]-97] = new Trie();
            tmp = tmp->characters[word[i]-97];
        }

        if(tmp->isEnd) {
            return false;
        } else {
            tmp->isEnd = true;
        }

        return true;
    }

    bool search(const std::string& word) {
        Trie *tmp = this;
        const uint length = word.length();

        for(int i = 0; i < NUM_CHAR; ++i) {
            if(!tmp->characters[word[i]-97]) {
                return false;
            }
            tmp = tmp->characters[word[i]-97];
        }

        if(!tmp->isEnd) 
            return false;

        return true;
    }

    void deleteWord(const std::string& word) {
        // Trie* tmp = this;
        // const uint length = word.size();

        // tmp->isEnd = false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Trie& other) {
        other.displayCharacters(os, "");
        return os;
    }

};



int main() {

    return 0;
}