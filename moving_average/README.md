# 滑动平均滤波器

C语言实现，O(n)增量法。每步"减旧值、加新值"，避免窗口内重复累加。

## 文件

```
moving_average.c    # 源代码
```

## 编译运行

```bash
gcc -o moving_average moving_average.c
./moving_average
```

## 可调参数

- `DATA_SIZE`   — 数据长度
- `WINDOW_SIZE` — 滑动窗口大小，输出长度自动适配
