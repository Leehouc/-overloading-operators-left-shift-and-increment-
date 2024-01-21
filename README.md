(1)报错形式：{Error Message:}
    1.在对"<<"与"++(后置)"进行运算符重载时，会出现no match for 'operator<<' (operandtypesare'std::ostream' {aka 'std::basic_ostream `<char>`'}and 'ppp')的提示在cout << p1++ << endl;一句。
    English：{When overloading operators "<<" and "++(postfix)," you will encounter the error message "no match for 'operator<<' (operand types are 'std::ostream' {aka 'std::basic_ostream <char>'} and 'ppp') during the statement cout << p1++ << endl;."}

    2.若使用visual studio 产品会显示：
    E0349	没有与这些操作数匹配的 "<<" 运算符
    C2679	二元“<<”: 没有找到接受“ppp”类型的右操作数的运符(或没有可接受的转换)
    这两条错误。
    English：{If using Visual Studio products, the errors displayed are:
        E0349: "no '<<' operator matches these operands"
        C2679: "binary '<<': no operator found that takes a right-hand operand of type 'ppp' (or there is no acceptable conversion)."}

(2)报错原因：{ Reason for Errors:}
    其原因为"p++"返回的是一个临时对象，临时对象属于纯右值，它不能绑定到左值引用，需要用常值左值引用或者右值用来绑定。
    English：{The reason is that "p++" returns a temporary object, which is a pure rvalue. It cannot bind to an lvalue reference and requires a const lvalue reference or an rvalue to bind.}

(3)错误分析：{Error Analysis:}
    修改"<<"与"++(后置)"的重载函数。
    English：{Modify the overloaded functions for "<<" and "++(postfix)."}

(4)修改方式：

    1.methord1

```
ostream& operator<<(ostream& out, ppp p)
ppp& operator++(int)
```

    2.methord2

```
ostream& operator<<(ostream& out, const ppp& p)
ppp operator++(int)
```

    3.methord3

```
ostream& operator<<(ostream& out, ppp p)
ppp operator++(int)

```

(5)谢谢{Thank you for watching.}
