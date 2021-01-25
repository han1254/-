# 2.1 基本概念

## 1. 引论

一个设计语言是一个**记号系统**，他的完整定义应该包括**语法**和**语义**两个方面。

目前广泛使用的手段是**上下文无关文法**，即使用上下文无关文法作为程序设计语言语法的描述工具。

程序设计语言的语义常常分为两类：**静态语义**和**动态语义**。

## 2. 文法的直观概念

文法是以有穷的集合刻画无穷的集合的一个工具

## 3. 符号和符号串

+ 考虑一个有穷<font color=red>**字母表**</font>$\sum$ 字符集
+ 其中的每一个元素称为一个<font color=red>**字符**</font>
+ $\sum$上的<font color=red>**字**</font>（也叫<font color=red>**字符串**</font>）是指由$\sum$中的字符所构成的一个有穷序列
+ 不包含任何字符的序列称为<font color=red>**空字**</font>，记为$\varepsilon$ 
+ 用$\sum^*$表示$\sum$上的<font color=red>**所有字的全体**</font>，包含空字$\varepsilon$

例如设$\sum$ = {a, b}，则

$\sum^*$ = {$\varepsilon$, a, b, aa, ab, bb, aaa, ...}

$\sum^*$称为$\sum$的**闭包**

$\sum^+$ = {a, b, aa, ab, bb, aaa, ...}

$\sum^+$称为$\sum$的**正闭包**

若$\sum$中没有$\varepsilon$，则$\sum^*$比$\sum^+$多了一个$\varepsilon$

若$\sum$中有$\varepsilon$，则$\sum^*$与$\sum^+$相等



### 3.1 符号串的头尾

### 3.2 符号的链接

### 3.3 符号串的方幂

##  5. 文法的类型

