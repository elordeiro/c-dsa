#include "test_header.h"

char* test[] = {"c++", "c", "python", "ruby", "java", "javascript", "c#", "go", "rust", "haskell", "scala", "erlang", "prolog", "lisp", "clojure", "ocaml", "f#", "swift", "kotlin", "dart", "php", "perl", "bash", "zsh", "fish", "powershell", "c-shell", "korn-shell", "elisp", "scheme", "racket", "lua", "julia", "fortran", "cobol", "pascal", "ada", "basic", "visual-basic", "delphi", "matlab", "octave", "r", "s", "tcl", "awk", "sed", "groovy", "haxe", "nim", "nimrod", "nemerle", "boo", "fantom", "factor", "io", "ioke", "j", "jade", "j"};

static void test_ds_add_kvpair(Set* set) {
    printf("\nCalling ds_set_add_kvpair(...) returns: \n");
    for (int i = 0; i < 60; i++) {
        ds_set_add_kvpair(set, i, test[i]);
    }
    ds_set_print(set);
    ds_set_print_partial(set);
}

static void test_ds_set_set(Set* set) {
    printf("\nCalling ds_set_add_kvpair(4, my_lang) returns: \n");
    ds_set_add_kvpair(set, 4, "my_lang");
    ds_set_print_partial(set);
}

static void test_ds_set_remove(Set* set) {
    printf("\nCalling ds_set_remove(4) returns: \n");
    ds_set_remove(set, 4);
    ds_set_print_partial(set);
}

void test_set() {
    Set* set = ds_set_new_Set();

    printf("Testing Set\n");
    test_ds_add_kvpair(set);
    test_ds_set_set(set);
    test_ds_set_remove(set);
    
    ds_set_destroy(set);
    printf("\n---------------------------------------------------------\n\n");
}
