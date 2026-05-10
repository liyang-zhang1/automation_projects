#include <stdio.h>
#include <stdlib.h>

/* 宏定义：数据长度、滑动窗口大小、输出数组长度 */
#define DATA_SIZE     20
#define WINDOW_SIZE   3
#define OUTPUT_SIZE   (DATA_SIZE - WINDOW_SIZE + 1)

/*
 * 滑动平均滤波（增量法，O(n)）
 * input:      原始数据数组
 * data_size:  原始数据长度
 * window_size:滑动窗口大小
 * output:     滤波结果数组（长度 = data_size - window_size + 1）
 */
void moving_average(const float *input, int data_size, int window_size, float *output)
{
    int i;
    float sum = 0.0f;

    if (window_size <= 0 || data_size < window_size)   /* 参数合法性检查 */
        return;

    /* 计算首个窗口的累加和 */
    for (i = 0; i < window_size; i++)
        sum += input[i];

    output[0] = sum / window_size;

    /* 滑动窗口：减去旧值，加上新值，无需重复累加 */
    for (i = 1; i <= data_size - window_size; i++)
    {
        sum += input[i + window_size - 1] - input[i - 1];
        output[i] = sum / window_size;
    }
}

int main(void)
{
    system("chcp 65001 > nul");    /* Windows 控制台切换到 UTF-8，避免中文乱码 */

    /* 模拟传感器原始数据（带噪声） */
    const float raw[DATA_SIZE] = {
        25.1f, 25.8f, 24.9f, 26.2f, 25.3f,
        24.7f, 25.5f, 26.0f, 25.0f, 25.4f,
        25.9f, 24.8f, 25.6f, 26.1f, 24.5f,
        25.2f, 25.7f, 24.6f, 26.3f, 25.0f
    };
    float filtered[OUTPUT_SIZE];
    int i;

    moving_average(raw, DATA_SIZE, WINDOW_SIZE, filtered);

    /* 打印原始数据与滤波结果 */
    printf("初始数据：");
    for (i = 0; i < DATA_SIZE; i++)
        printf("%.1f ", raw[i]);
    printf("\n");

    printf("滑动平均（窗口=%d）：", WINDOW_SIZE);
    for (i = 0; i < OUTPUT_SIZE; i++)
        printf("%.2f ", filtered[i]);
    printf("\n");

    return 0;
}
