# compiler

### website
http://compiler.educg.net/

### SysY definition
https://gitlab.eduxiji.net/nscscc/docs/-/blob/master/SysY%E8%AF%AD%E8%A8%80%E5%AE%9A%E4%B9%89.pdf

### sysyruntime
https://gitlab.eduxiji.net/windcome/sysyruntimelibrary

### build
```
cd src
make
```

### test
```
sh testall.sh ../testcase/functional_test

./compiler  -S -o testcase.s ../testcase/functional_test/00_main.sy
```

### clean
```
make clean
```

### Todo

- gobal array func param
- many gobal const var
- secondhand array as funcparam
- or expression
- large number to register
- stackoverflow


### Reference

##### lex&&yacc

a simple toturial for lex&yacc
https://www.epaperpress.com/lexandyacc/index.html

Flex doc
http://dinosaur.compilertools.net/flex/index.html

Bison doc
https://www.gnu.org/software/bison/manual/html_node/index.html

