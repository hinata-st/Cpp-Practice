<h1 style="color:blue;">by Emilia-tan</h1>

# 语句

****

## 简单语句

#### 空语句

```cpp
while(cin >> s && s != sought)
    ;//空语句
```

#### 符合语句（块）

```cpp
while(val < 10)
{
    ++val;
}
```
****

## if语句

## switch语句

```cpp
switch(ch)
{
    case 'a':
        break;
    case 'b':
        break;
}
```

`switch`语句首先对括号里的表达式求值，该表达式紧跟在关键字`switch`后面，可以是一个初始化的变量声明。表达式的值转换成整数类型，然后与每个`case`标签值比较。

`case`关键字和他对应的值一起被称为case标签，case标签必须是整型常量表达式

#### switch内部控制流

如果某个case标签匹配成功，将从该标签开始往后顺序执行所有的case分支，直到switch的结尾才会停下来。   
大多数情况下，在下一个case标签之前应该有一条break语句

**一般不要省略case分支最后的break语句。如果没写break语句，最好加一段注释说清楚程序的逻辑**

#### default标签

如果没有一个case标签能匹配上switch表达式的值，程序将执行紧跟在default标签后面的语句。

****

## 迭代语句

### while语句

```cpp
while(condition)
{
    statement
}
```
`while`的条件部分可以是一个表达式或者是一个带初始化的变量声明。

**定义在while条件部分或者while循环体内的变量每次迭代都经历从创建到销毁的过程**

### 传统的for语句

for语句的语法形式是
```cpp
for(init-statement;condition;expression)
{
    statement;
}
```

`init-statement`必须是以下3种形式中的一种：声明语句、表达式语句或者空语句。   
一般情况下，`intit-statement`负责初始化一个值，只执行一次，这个值将随着循环的进行而改变。   
`expression`负责修改`init-statement`初始化的变量，这是变量正好是`condition`检查的对象，**修改发生在每次循环迭代之后**。   
`statement`可以是一条单独的语句也可以是一条复合语句。   

#### for语句中的多重定义

`inti-statement`也可以定义多个对象，但是只能有一条声明语句，因此，所有变量的基础类型必须相同。

#### 省略for语句头的某些部分

for语句头能省略掉`init-statement,condition,expression`中的任何一个（或者全部）   
如果无须初始化，则我们可以使用一条空语句作为`init-statement`    
**注意，分号必须保留**    
省略`condition`的效果等价于在条件部分写了个`true`

### 范围for语句
```cpp
for(declaration : expression)
    statement
```

`expression`表示的必须是一个序列，比如用花括号括起来的初始值列表、数组、`vector`、`string`等类型的对象，这些类型的共同特点是拥有能返回迭代器的`begin`和`end`成员

`declaration`定义一个变量，序列中的每个元素都能转换成该变量的类型，最简单的方法就是使用`auto`类型说明符，如果需要对序列中的元素执行写操作，循环变量必须声明成引用类型。   

每次迭代都会重新定义循环控制变量，并将其初始化成序列中的下一个值。   
```cpp
vector<int> v = {0,1,2,3,4,5,6,7,8,9};
for(auto &r : v)
{
    r *= 2;
}
```

### do while语句

`do while`语句和`while`语句的唯一区别是，`do while`语句先执行循环体后检查条件     
```cpp
do 
    statement
while(condition);
```
不允许在条件部分定义变量

****
## 跳转语句

### break语句

break语句负责终止离他最近的`while,do while,for,switch`语句，并从这些语句之后的第一条语句开始继续执行

### continue语句

continue语句终止最近的循环中的当前迭代并立刻开始下一次迭代。   
continue语句只能出现在`for、while和do while`循环的内部

### goto语句
goto语句的作用是从goto语句无条件跳转到同一函数内的另一条语句    
**不要在程序中使用goto语句，因为它使得程序既难理解又难修改**
****

## try语句块和异常处理

异常处理机制为程序中异常检测和异常处理这两部分的协作提供支持。     

异常处理包括  
 - throw表达式，异常检测部分使用throw表达式来表示他遇到了无法处理的问题。我们说throw引发(raise)了异常
 - try语句块，异常处理部分使用try语句块处理异常。try语句块以关键字try开始，并以一个或多个catch子句结束，try语句块中代码抛出的异常通常会被某个catch子块处理。
 - 一套异常类，用于在throw表达式和相关的catch子句之间传递异常的具体信息。

### throw表达式

程序的异常检测部分使用throw表达式引发一个异常。throw表达式包括关键字throw和紧随其后的一个表达式，其中表达式的类型就是抛出的异常类型。throw表达式后面通常跟进一个分号，从而构成一条表达式语句。

`throw runtime_error("data must refer to same ISBN");`  
该异常试类型runtime_error的对象。抛出异常将终止当前的函数，并把控制权转移给能处理该异常的代码。

### try语句块

```cpp
try{
    program-statement 
} catch (exception-declaration){
    handler-statement
} catch (exception-declaration){
    hadnler-statement
}//   ....
```

跟在try块之后是一个或多个catch子句。catch子句包括三部分：关键字catch、括号内一个（可能未命名的）对象的声明（异常声明）以及一个块。   
当选中了某个catch子句处理异常之后，执行与之对应的块。catch一旦完成，程序跳转到try语句块最后一个catch子句之后的那条语句继续执行。

try语句中的program-statement组成程序的正常逻辑。

```cpp
#include <iostream>
#include <stdexcept>
using std::cin; using std::cout; using std::endl; using std::runtime_error;

int main(void)
{
    for (int i, j; cout << "Input two integers:\n", cin >> i >> j; )
    {
        try 
        {
            if (j == 0) 
                throw runtime_error("divisor is 0");
            cout << i / j << endl;
        }
        catch (runtime_error err) 
        {
            cout << err.what() << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }

    return 0;
}
```
### 标准异常（P176）




