## Usage

运行ANNS Demo
```
g++ anns-demo.cpp -o demo
./demo < ../testcase/10k.in > 10k.out
```

测试算法准确率
```
g++ checker.cpp -o checker
./checker ../testcase/10k.in 10k.out ../testcase/10k.ans
```
