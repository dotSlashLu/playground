#include <stdio.h>
#include <math.h>


/* 2-1:
 * 输出 100 ～ 999 中的 所有 水 仙花 数。
 * 若 3 位数 ABC 满足 ABC ＝ A3 ＋ B3 ＋ C3， 则 称 其为 水 仙花 数。
 * */
void daffodil()
{
        for (int i = 100; i < 1000; i++) {
                int a = i / 100,
                    b = i / 10 % 10,
                    c = i % 10;
                if (i == a * a * a + b * b * b + c * c * c)
                        printf("%d\n", i);
        }
}


/*
 * 2-1:
 * 三人 一排、 五人 一排、 七人 一排 地 变换 队形， 而他 每次 只 掠 一眼 队伍 的 排尾 就 知道 总人数
 * 多行输入，输出带case number
 **/
void hanxin()
{
        freopen("./c2-1.in", "rb", stdin);
        while (1) {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
        }
}

int main(int argc, char **argv)
{
        daffodil();
        return 0;
}
