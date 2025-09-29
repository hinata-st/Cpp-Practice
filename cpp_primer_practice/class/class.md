<h1 style="color:blue;">by Emilia-tan</h1>

# 定义抽象数据类型

#### this指针

`this`指针是C++中的一个**隐式指针**，具有以下特点：

- **定义**：指向调用当前成员函数的对象
- **类型**：`ClassName* const`（指向类对象的常量指针）
- **作用域**：只能在非静态成员函数中使用
- **隐式性**：由编译器自动提供，无需声明

### this指针的本质

```cpp
class MyClass {
    int value;
public:
    void setValue(int v) {
        // 以下两种写法等价
        value = v;        // 隐式使用this
        this->value = v;  // 显式使用this
    }
};

// 编译器实际上将成员函数转换为类似这样的形式：
// void setValue(MyClass* const this, int v) {
//     this->value = v;
// }
```

### this指针的主要用途

#### 1. 解决命名冲突
```cpp
class Student {
    string name;
    int age;
public:
    // 参数名与成员变量名相同时，必须使用this
    void setInfo(string name, int age) {
        this->name = name;  // 区分成员变量和参数
        this->age = age;
    }
};
```

#### 2. 支持链式调用
```cpp
class Calculator {
    int result;
public:
    Calculator& add(int n) {
        result += n;
        return *this;  // 返回当前对象的引用
    }
    
    Calculator& multiply(int n) {
        result *= n;
        return *this;
    }
};

// 使用链式调用
Calculator calc;
calc.add(5).multiply(3).add(2);  // 链式调用
```
`return`语句解引用this指针以获得执行该函数的对象
#### 3. 对象自我比较和识别
```cpp
class Person {
    string name;
public:
    bool isSame(const Person& other) const {
        return this == &other;  // 比较对象地址
    }
    
    Person& operator=(const Person& other) {
        if (this == &other) {   // 防止自赋值
            return *this;
        }
        name = other.name;
        return *this;
    }
};
```

#### 4. 传递当前对象给其他函数
```cpp
class Window {
public:
    void registerCallback() {
        // 将当前对象传递给外部函数
        setCallback(this);
    }
};

void setCallback(Window* w) {
    // 使用窗口对象
}
```

### this指针的特性

#### 1. 常量性
```cpp
class MyClass {
public:
    void func() {
        // this的类型是 MyClass* const
        // this = other_ptr;  // 错误！this不能被重新赋值
    }
    
    void constFunc() const {
        // 在const成员函数中，this的类型是 const MyClass* const
        // this->member = value;  // 错误！不能通过this修改成员
    }
};
```
**常量对象，以及常量对象的引用或指针都只能调用常量成员函数**
#### 2. 作用域限制
```cpp
class MyClass {
    static int staticMember;
public:
    static void staticFunc() {
        // staticMember = 10;     // 正确
        // this->member = 10;     // 错误！静态函数中没有this指针
    }
    
    void normalFunc() {
        this->member = 10;        // 正确
    }
};
```

#### 在类的外部定义成员函数

```cpp
double Sales_data::avg_price() const
{
    ;//定义了avg_price函数，该函数被声明在类Sales_data的作用域内
}
```
***
### 定义类相关的非成员函数

**一般来说，如果非成员函数是类接口的组成部分，则这些函数的声明应该与类在同一个头文件内。**

只要某个非成员函数是类对外功能的一部分，就应该和类声明一起放在同一个头文件里，这样用户只需包含一个头文件就能获得完整的接口。

### 构造函数

- 构造函数的任务是初始化类对象的数据成员，只要类成员被创建，就会执行构造函数。
- 构造函数的名字与类相同，没有返回类型
- 类可包含多个构造函数
- 构造函数不能被声明成const

#### 合成的默认构造函数

类通过一个特殊的构造函数来控制默认初始化过程，这个函数叫做默认构造函数。默认构造函数无须任何实参。

如果我们的类没有显式的定义构造函数，那么编译器就会为我们隐式的定义一个默认构造函数。

编译器创建的构造函数又称为合成的默认构造函数，按照如下规则初始化类的数据成员：
- 如果存在类内的初始值，用它来初始成员。
- 否则，默认初始化该成员。

**如果类包含有内置类型或者复合类型的成员，则只有当这些成员都被赋予了类内的初始值时，这个类才适合于使用合成的默认构造函数**

#### 定义构造函数

`sales_data() = dafault;`
定义这个构造函数的目的是既需要其他形式的构造函数，也需要默认的构造函数。


```cpp
class BankAccount {
    // 为所有内置类型成员提供合理的初始值
    double balance = 0.0;           // 账户余额初始为0
    int accountNumber = -1;         // 无效账号标记
    bool isActive = false;          // 账户默认未激活
    char accountType = 'S';         // 默认储蓄账户
    time_t createdTime = 0;         // 创建时间初始化
    
    // 类类型成员可选择性提供初始值
    std::string ownerName;          // 空字符串（默认构造）
    std::vector<std::string> transactions; // 空vector（默认构造）
    
public:
    // 默认构造函数使用所有类内初始值
    BankAccount() = default;
    
    // 带参构造函数覆盖部分初始值
    BankAccount(int accNum, const std::string& owner, double initialBalance = 0.0)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance), isActive(true) {
        createdTime = std::time(nullptr);  // 设置创建时间
    }
    
    // 显示账户信息
    void displayInfo() const {
        std::cout << "Account: " << accountNumber << std::endl;
        std::cout << "Owner: " << ownerName << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
        std::cout << "Active: " << (isActive ? "Yes" : "No") << std::endl;
        std::cout << "Type: " << accountType << std::endl;
    }
};
```

#### 构造函数初始值列表

构造函数初始值是成员名字的一个列表，每个名字后面紧跟括号括起来的成员初始值。不同成员初始化通过逗号分隔开。

**构造函数不应该轻易覆盖掉类内的初始值，除非新赋的值与原值不同。如果你不能使用类内的初始值，则所有构造函数都应该显式的初始化每个内置类型的成员**


#### 在类的外部定义构造函数

```cpp
Sales_data::Salse_data(std::istream &is)
{
    read(is,*this);
}
```

`Sales_data::Salse_data`的含义是我们定义`Sales_data`类的成员，又因为该成员的名字和类名相同，所以他是一个构造函数。

***

### 拷贝、赋值、和析构

一般来说，编译器生成的版本将对对象的每个成员执行拷贝、赋值和销毁操作。

#### 某些类不能依赖于合成的版本

如果类包含`vector`或`string`成员，则其拷贝、赋值和销魂的合成版本能够正常工作。

## 访问控制与封装

使用访问说明符加强类的封装性：
- 定义在`public`说明符之后的成员在整个程序内可被访问,`public`成员定义类的接口
- 定义在`private`说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，`private`部分封装了类的实现细节

#### 使用class或struct关键字

如果我们使用struct关键字，则定义在第一个访问说明符之前的成员是`public`的；相反，如果我们使用`class`关键字，则这些成员是`private`的。

**使用class和struct定义类唯一的区别就是默认的访问权限**

***
### 友元

类可以允许其他类或者函数访问他的非公有成员，方法是另其他类或者函数成为他的友元，只需增加一条以`friend`关键字开始的函数声明语句

友元声明只能出现在类定义的内部，在类的位置不限。

**最好在类定义开始或结束前的位置集中声明友元**

封装有两个重要的优点
- 确保用户代码不会无意间破坏封装对象的状态
- 被封装的类的具体实现细节可以随时改变，而无需调整用户级别的代码。

友元的声明仅仅指定了访问的权限，而非一个通常意义上的函数声明。通常把友元的声明与类本身放置在同一个头文件中（类的外部）。

***
## 类的其他特性

。。。
### 返回*this的成员函数

#### 从const成员函数返回*this

#### 基于const的重载
***

### 类类型

即使两个类的成员列表完全一致，他们也是不同的类型。对于一个类来说，他的成员和其他任何类的成员都不是一回事。

### 友元

#### 类之间的友元关系

如果一个类指定了友元类，则友元类的成员函数可以访问此类包括非公有成员在内的所有成员。

### 名字查找与类的作用域

名字查找的过程：
- 在名字所在的块中寻找其声明语句，只考虑在名字的使用之前出现的声明。
- 如果没找到，继续查找外层作用域。
- 如果最终没有找到匹配的声明，则程序报错。

### 构造函数初始值列表

如果成员是const、引用，或者属于某种未提供默认构造函数的类类型，我们必须通过构造函数初始值列表为这些成员提供初始值。

#### 成员初始化顺序

最好令构造函数初始值的顺序与成员声明的顺序一致。而且如果可能的话，尽量避免使用某些成员初始化其他成员。

#### 默认实参和构造函数

在实际中，如果定义了其他构造函数，那么最好也提供一个默认构造函数。

***
## 类的静态成员

#### 声明静态成员

在成员的声明之前加上关键字static使其与类关联在一起。

静态成员函数不与任何对象绑定在一起，他们不包含this指针。

#### 定义静态成员

和类的所有成员一样，当我们指向类外部的静态成员时，必须指明成员所属的类名。static关键字则只出现在类内部的声明语句中。

静态成员和普通成员的另外一个区别是我们可以使用静态成员作为默认实参。









