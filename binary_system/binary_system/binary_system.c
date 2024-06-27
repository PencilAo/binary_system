#define _CRT_SECURE_NO_WARNINGS
//整数的二进制表示有三种
//原码
//反码
//补码
//正整数的原码、反码、补码相同
//负整数的原码、反码、补码要算
//最高位是0表示是正数
//最高位是1表示是负数
// 
// 
//7
//00000000000000000000000000000111 - 原码
//00000000000000000000000000000111 - 反码
//00000000000000000000000000000111 - 补码
// 
//-7
//10000000000000000000000000000111 - 原码
//11111111111111111111111111111000 - 反码   原码的符号位不变，其他位按位取反就是反码
//11111111111111111111111111111001 - 补码   补码 = 反码 + 1
//                                          原码 = 补码取反 + 1
//                                          补码 = 原码取反 + 1
//***************左移右移只针对整形***************
//
//***************整数在内存中存储的是补码***************


//左移
//左移n位就是 *2**n
//int main()
//{
//    int a = 7;
//    int b = a << 1;//b为a向左移动一位的结果
//    printf("%d\n", a);//a不变  //7
//    printf("%d\n", b);         //14
//    //左移操作符 - <<
//    //移动的是二进制位(移动的是内存中的补码)
////  a -     00000000000000000000000000000111
////  b - (-0)0000000000000000000000000000111(+0)    //左移操作符，左边丢弃，右边补0
////  b =     1 * 2 + 1 * 2^2 + 1 * 2^3 = 14
//
//
//
//    int c = -7;
//    int d = c << 1;
//    printf("%d\n", c);
//    printf("%d\n", d);
////  c -     11111111111111111111111111111001
////  d - (-1)1111111111111111111111111111001(+0)    //左移操作符，左边丢弃，右边补0
////  d-1     11111111111111111111111111110001 //反码        反码 = 补码-1 
////  d的     10000000000000000000000000001110  原码
////  d =     -(1 * 2 + 1 * 2**2 + 1 * 2**3) = 14
//    return 0;
//}

//右移
//1.算数移位    //右边丢弃，左边补原符号位 (正数补0，负数补1) 大部分编辑器都是算数移位，算数移位更合理
//2.逻辑移位   //右边丢弃，左边补0
//int main()
//{
//    int a = 7;      //7
//    int b = a >> 1; //3
//    printf("%d\n", a);
//    printf("%d\n", b);
////  a -     00000000000000000000000000000111
////  b -  (+0)0000000000000000000000000000011(-1)        //右边丢弃，左边补原符号位 (正数补0，负数补1)
////  b = 1 + 1 * 2 = 3  
//    int c = -7;
//    int d = c >> 1;
//    printf("%d\n", c);
//    printf("%d\n", d); 
////  c -     11111111111111111111111111111001
////  d -  (+1)1111111111111111111111111111100(-1)     //补码
////  d-1     11111111111111111111111111111011         //反码
////  d       10000000000000000000000000000100         //原码
////  d =     -2 * 2**2 = -4
//    return 0;
//}
//位操作符
// & - 按(2进制)位与       (两个对应的二进制位如果有1则&的结果为0，只有当两个都是1是从&才为1)
// | - 按(2进制)位或       (两个对应的二进制位如果有1则|的结果为1，只有当两个都是0是从|才为0)
// ^ - 按(2进制)位异或     (两个相同为0，相异为1)
//int main()
//{
//    int a = 3;
//    int b = -5;
//    int c = a & b; //c = 3
//    int d = a | b; //d = -5
//    int e = a ^ b; //e = -8
//////  a - 00000000000000000000000000000011  //原码、反码、补码
//////  b - 10000000000000000000000000000101  //原码
//////  b - 11111111111111111111111111111010  //反码
////// 
//////  b - 11111111111111111111111111111011  //补码
//////  a - 00000000000000000000000000000011  //补码
////// 
//////  c - 00000000000000000000000000000011  //补码
////// 
//////  d - 11111111111111111111111111111011  //补码
//////  d - 11111111111111111111111111111010  //反码
//////  d - 10000000000000000000000000000101  //原码
//////
//////  e - 11111111111111111111111111111000  //补码
//////  e - 11111111111111111111111111110111  //反码
//////  e - 10000000000000000000000000001000  //原码
//    printf("%d", e);
//    return 0;
//}
//不用第三个数交换a,b
// 
// 一般情况下都用有第三个数交换的方法
// 
//int main()//差
//{
//    int a = 3;
//    int b = 5;
//    a = a + b;
//    b = a - b;
//    a = a - b;  
//    printf("%d\n", a);
//    printf("%d\n", b);
//    return 0;
//}会有溢出的问题
// 
//不用第三个数交换a,b
// ^ - 符合分配律    3^3^5=3^5^3 
//3^3 = 0     a^a = 0
//011
//011
//000
//0^5 = 5     0^a = a
//000
//101
//101
//int main()//好
//{
//    int a = 3;
//    int b = 5;
//    a = a ^ b; // a = 3^5          
//    b = a ^ b; // b = 3^5^5 = 3   b = a^b^b = a
//    a = a ^ b; // a = 3^5^3 = 5   a = a^b^a = b
//    return 0;
//}
//int main()
//{
//    int a,c;
//    scanf("%d", &a);
//    int i = 1;
//    int count = 0;
//    for (int b = 0; b < 32; b++)
//    {
//        if (a >> b & 1 == 1)
//        {
//            count++;
//        }
//    }
//    或
//    while(a)
//    {
//        a = a & (a - 1);        
//        count++;
//    }
//    printf("%d", count);
//    return 0;
//} 
// 判断一个数是否是2的次方
// 2的次方中二进制位只有一个1
// if(n & (n-1) == 0)
// 那么这个数就是2的次方
// a = a >> 1;或// a >>= 1;
//单目操作符:只有一个操作数
//双目操作符:有两个操作符 如 a + b
// 
// 