#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "ladder.h"

using namespace std;

int main() {
    set<string> word_list;
    load_words(word_list, "src/words.txt"); 

    string start_word, end_word;
    cout << "Enter start word and end word: ";
    cin >> start_word >> end_word;

    transform(start_word.begin(), start_word.end(), start_word.begin(), ::tolower);
    transform(end_word.begin(), end_word.end(), end_word.begin(), ::tolower);

    if (word_list.find(end_word) == word_list.end()) {
        cerr << "Error: End word '" << end_word << "' is not in the dictionary.\n";
        return 1;
    }

    if (start_word == end_word) {
        cerr << "Error: Start and end words are the same.\n";
        return 1;
    }

    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);

    if (ladder.empty()) {
        cout << "No word ladder found between '" << start_word << "' and '" << end_word << "'.\n";
    } else {
        print_word_ladder(ladder);
    }

    return 0;
}


