#include "test_header.h"

char* lang[] = {"c++", "c", "python", "ruby", "java", "javascript", "c#", "go", "rust", "haskell", "scala", "erlang", "prolog", "lisp", "clojure", "ocaml", "f#", "swift", "kotlin", "dart", "php", "perl", "bash", "zsh", "fish", "powershell", "c-shell", "korn-shell", "elisp", "scheme", "racket", "lua", "julia", "fortran", "cobol", "pascal", "ada", "basic", "visual-basic", "delphi", "matlab", "octave", "r", "s", "tcl", "awk", "sed", "groovy", "haxe", "nim", "nimrod", "nemerle", "boo", "fantom", "factor", "io", "ioke", "j", "jade", "j"};

void test_hashtable_add(HashTable* ht) {
    srand((unsigned int) time(NULL));
    for (int i = 0; i < 1000; i++) {
        hashtable_add(ht, lang[rand() % 60]);
    }
    hashtable_add(ht, "myLang");
    hashtable_add(ht, "myLang");
    hashtable_print(ht);
    hashtable_remove(ht, "myLang");
    hashtable_remove(ht, "myLang");
    hashtable_print(ht);
}

void test_hashtable_remove(HashTable* ht) {
    int i = 0;
    while (i < 30) {
        for (int j = 0; j < 60; j++) {
            if (i < 30)
                i += hashtable_remove(ht, lang[j]);
        }
    }
    hashtable_print(ht);
}

void test_hashtable() {
    HashTable* ht = ds_new_hashtable();
    test_hashtable_add(ht);
    test_hashtable_remove(ht);
    hashtable_destroy(ht);
    return;
}
