# 哥德巴赫猜想研究

哥德巴赫猜想说，一个足够大的偶数可以表示成两个素数之和。



### 关于素数分布的已知规律

#### 素数定理

当$N$趋于无穷时，小于$N$的素数数量，可以近似表示为$\frac{N}{\log(N)}$；对数积分$\operatorname{li}(x)$是对$\pi(x)$的更好的估计。

或者等价地说，$N$附近的素数密度约为$\frac{1}{\log(N)}$。


### 数值结果

任何小于$4\times 10^{18}$的偶数都经过计算机程序验证符合哥德巴赫猜想。

### 猜测

哈代-李特尔伍德猜测说，大整数$N$可以表示成的2个素数之和的方式可以近似表示为
$$2\Pi_2\left(\prod_{p\mid N; p \geq 3}{\frac{p-1}{p-2}}\right) \frac{N}{\left(\log(N)\right)^2}$$
其中$\Pi_2\approx0.6601\dots$是哈代-李特尔伍德的孪生素数常数。

<br/>

从直觉上说，对于一个随机数$x$，若$1\le x\le N$，则$x$是素数的概率约为$\frac{1}{\log(N)}$；$N-x$是素数的概率同样约为$\frac{1}{\log(N)}$；若把这两个事件近似看作独立事件，则它们同时发生的概率约为$\frac{1}{\left(\log(N)\right)^2}$。由此得到$N$表示为2个素数之和的方式，应该约等于$\frac{N}{\left(\log(N)\right)^2}$。这在数量级上，跟哈代-李特尔伍德猜测相吻合。

### 埃拉托斯特尼筛法

埃拉托斯特尼筛法是一种古老的求出$N$以内的所有素数的方法。

它的过程如下
1. 按顺序写下$2$至$N$的整数
2. 划掉$2$的倍数（除了$2$本身）
3. （下一个没有划掉的数是$3$）划掉$3$的倍数（除了$3$本身）
4. （下一个没有划掉的数是$5$）划掉$5$的倍数（除了$5$本身）
5. 重复以上步骤
6. 当进行到$\sqrt{N}$时，剩下的数就已经全都是素数了。


### 埃拉托斯特尼筛法的变形，求哥德巴赫猜想的解的近似数量

1. 写下$2$至$N-2$的整数
2. 划掉所有偶数
3. 划掉所有$3$的倍数；若$N$除以$3$的余数是r，划掉所有$3 k+r$形式的数
4. 划掉所有$5$的倍数；若$N$除以$5$的余数是r，划掉所有$5 k+r$形式的数
5. 划掉所有$7$的倍数；若$N$除以$7$的余数是r，划掉所有$7 k+r$形式的数
6. 划掉所有$11$的倍数；若$N$除以$11$的余数是r，划掉所有$11 k+r$形式的数
7. 重复以上步骤
8. 当进行到$\sqrt{N}$时，剩下的数，一定满足哥德巴赫猜想的条件。

##### 举例

若$N=42$,
则经过步骤2，剩下的数为$3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39$
经过步骤3，剩下的数为$5, 7, 11, 13, 17, 19, 23, 25, 29, 31, 35, 37$
经过步骤4，剩下的数为$11, 13, 19, 23, 29, 31$
下一个素数已经大于$\sqrt{N}$，停止

因为上述过程筛掉了所有的$\sqrt{N}$内的素数的倍数，剩下的必然都是素数
又因为上述过程的对称性，因此对于每一个剩下的数$x$，$N-x$也一定存在其中；

所以剩下的数（如果数量不为0），一定是对于偶数$N$的哥德巴赫猜想的解。

注意，上述过程会筛掉一部分合乎规则的解。比如对于$N=42$，$N$可以表示为$5+37$，而这个解被筛掉了。
故上述方式，可能会低估哥德巴赫问题的解的数量。

##### 估算数量

以上的每一个步骤，都可以用一个简单的方式来估算筛掉的数的数量

1. 一开始的数的数量是$N-3$
2. 划掉所有偶数——划掉的数约为剩下的数的${\frac{1}{2}}$
3. 划掉3的倍数；划掉$3 k + r$形式的数——若$N$是3的倍数，划掉的数约为剩下的数的$\frac{1}{3}$；若$N$不是3的倍数，划掉的数约为剩下的数的$\frac{2}{3}$。
4. 划掉5的倍数；划掉$5 k + r$形式的数——若$N$是5的倍数，划掉的数约为剩下的数的$\frac{1}{5}$；若$N$不是5的倍数，划掉的数约为剩下的数的$\frac{2}{5}$。
…………

由此可以得到一个估算公式
$$\left(\prod_{p \leq \sqrt{N}}(1 - \frac{F(p, N)}{p})\right)(N-3)$$

其中，$F(p, N)$的定义为，“若$p\mid N$，则$F(p, N) = 1$；否则$F(p, N) = 2$”。

比如，当$N$是42时，上述公式给出的估计是$7.8$（上述过程的结果是$6$，真实的解数量为$8$）
当$N$是$10^6$时，上述公式给出的估计是$11541.7$（上述过程的结果是$10764$，真实的解数量为$10804$）



当$N$是奇数时，上述公式给出的估计是0。


##### 估算素数数量

上面的逻辑，也可以用来估算$\pi(N)$。

$$\pi(N) \approx \left(\prod_{p \le \sqrt{N}}{\left( 1 - \frac{1}{p} \right)} \right) N + \pi (\sqrt{N}) $$

当用每一个素数$p$去筛剩余的数时，可以预计剩下的数近似变为$1-\frac{1}{p}$。这个连乘去掉了所有小于$\sqrt{N}$的素数，所以最后加上$\pi(\sqrt{N})$。

比如，当$N=100$时，上述公式给出的结果是$ 26.86 $，而$\pi(100)=25$。
当$N=10^{6}$时,上述公式给出的结果是$ 81133.26 $，而$\pi(10^{6})=78498$。
当$N=10^{8}$时,上述公式给出的结果是$ 6089698.25 $，而$\pi(10^{8})=5761455$。
当$N=10^{10}$时,上述公式给出的结果是$ 487538770.51 $，而$\pi(10^{10})=455052511$。

