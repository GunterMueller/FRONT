FRONT
 The Compiler Front-end Generation Suite
Forked from http://front.sourceforge.net/

 The Compiler Front-end Generation Suite

Front provides several tools and libraries that greatly ease the development of a compiler front-end, or any other tool that reads a computer language. The suites main tool is Front which, given an EBNF style input file, generates the scanner, parser, AST data structures, AST traversals, symbol table handling, and pretty printer.

The generated code uses the libfront library, which also provides a lot of other functionality for the programmer, such as a command line parser, string manipulation routines, several abstract types, and more.

Error messaging is greatly eased through the use of the error message generator generator, egg. And you can add C preprocessing support to your front-end with the use of libcpp.

Finally you can write simple AST transformations in doggy, the DAG Optimizer Generator, which will generate an AST rewriter from its input.
History
Front was developed in Philips Research by Lex Augusteijn as part of the Elegant project, and has been used there since 1998(?). Around 2000 Front broke free of Elegant, and since then many people within Philips Research have contributed to the tools and libraries. Many parsers have been generated using Front, including itself and a complete ANSI(89) C front-end.
Releases

There is no release yet. If you wish, you can download CFront from the SourceForge git server using:
git clone git://git.code.sf.net/p/front/front
Documentation

    libfront manual (not finished)
    cpp manual
    doggy manual
    egg manual
    Front manual

