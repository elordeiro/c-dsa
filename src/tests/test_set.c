#include "test_header.h"

char* test[] = {"c++", "c", "python", "ruby", "java", "javascript", "c#", "go", "rust", "haskell", "scala", "erlang", "prolog", "lisp", "clojure", "ocaml", "f#", "swift", "kotlin", "dart", "php", "perl", "bash", "zsh", "fish", "powershell", "c-shell", "korn-shell", "elisp", "scheme", "racket", "lua", "julia", "fortran", "cobol", "pascal", "ada", "basic", "visual-basic", "delphi", "matlab", "octave", "r", "s", "tcl", "awk", "sed", "groovy", "haxe", "nim", "nimrod", "nemerle", "boo", "fantom", "factor", "io", "ioke", "j", "jade", "j"};

static void test_add(Set* set) {
    printf("\nCalling set_add_kvpair(...) returns: \n");
    for (int i = 0; i < 60; i++) {
        set_add(set, i, test[i]);
    }
    set_print(set);
    set_print_partial(set);
}

static void test_set_set(Set* set) {
    printf("\nCalling set_add_kvpair(4, my_lang) returns: \n");
    set_add(set, 4, "my_lang");
    set_print_partial(set);
}

static void test_set_remove(Set* set) {
    printf("\nCalling set_remove(4) returns: \n");
    set_remove(set, 4);
    set_print_partial(set);
}

void test_set() {
    Set* set = ds_new_set("bs");

    printf("Testing Set\n");
    test_add(set);
    test_set_set(set);
    test_set_remove(set);
    
    set_destroy(set);
    printf("\n---------------------------------------------------------\n\n");
}
