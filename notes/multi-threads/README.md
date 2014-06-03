Multi-Thread Programming
=========================

Notes 
------------------------
1. 要加多线程编译标志 -lpthread, 实例： 
```
gcc create_thread.c -o create_thread -lpthread
```

Q & A
-----------------------
### Q1. 编译报warning, 这个是什么情况？  
```
警告： 格式 ‘%u’ expects argument of type ‘unsigned int’, but argument 2 has type ‘pthread_t’ [-Wformat]
```

### A1:
将```%u```改成```%lu```, 参考[线程ID的输出格式](http://edsionte.com/techblog/archives/819)


Reference
------------------------
1. 《Linux C 编程实战》第八章 线程控制 (P204-P219) 
