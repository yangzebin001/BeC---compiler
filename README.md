# BeC-- compiler

BeC-- is a small compiler for the C programming language(`subset`), compile  assembly code and run on Raspbery4B/ARMv7 32bits. It's intended to support most C11 language features while keeping the code as small and simple as possible.


## Environment
```bash
flex 2.6.0
bison 3.0.4
clang 3.8.0
```


## Current feature set

* positive integers (no other types yet)
* local variables
* array support
* integer or array constants
* variable assignment
* arithmetic expressions (`foo + bar` `foo - bar` `foo * bar` `foo / bar`)
* rel expressions (`foo == bar`, `foo != bar`, `foo < bar`, `foo <= bar`, `foo > bar`, `foo >= bar`)
* logical expression (`foo && bar`, `foo || bar`)
* unary op expresions (`+FOO`, `-FOO`, `!FOO`)
* Comments (`// foo` and `/* foo */`)
* sequences of statements (`foo; bar`)
* if statements (`if (foo) { bar }` and `else if (foo) {bar} else {bar}`)
* while loops (`while (foo) { bar }`)
* return statement
* break statement
* continue statement
* function definitions and calls
* multilevel block


### Front end
use flex for lexical analysis and bison to build AST(abstract syntax tree).

### Back end
BeC-- generates code from AST directly. The algorithm is 1-TOSCA (top of stack caching). It is far from generating efficient code, but at least it works and generates code efficently.

### build
```
cd src
make
```

### test
```bash

cd src

// test all
sh testall.sh ../testcase/functional_test

// test one
./compiler -S -o testcase.s ../testcase/functional_test/00_main.sy
```

### clean
```bash
make clean
```


### Reference

##### lex&&yacc

a simple toturial for lex&yacc
https://www.epaperpress.com/lexandyacc/index.html

Flex doc
http://dinosaur.compilertools.net/flex/index.html

Bison doc
https://www.gnu.org/software/bison/manual/html_node/index.html

