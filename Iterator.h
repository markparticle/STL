/*
 * @Author       : mark
 * @Date         : 2020-05-12
 * @copyleft Apache 2.0
 */ 
#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstddef>

//STL萃取器的泛化版本

/*迭代器分类标签可以用以标示某个迭代器的分类，
可以根据这一分类所要求的特性来选择最优算法。*/

//返回输入迭代器
struct input_iterator_tag{};
//返回输出迭代器
struct output_iterator_tag{};
//返回前向迭代器
struct forward_iterator_tag: public input_iterator_tag{};
//返回双向迭代器
struct bidirectional_iterator_tag: public forward_iterator_tag{};
//返回随机迭代器
struct random_access_iterator_tag: public bidirectional_iterator_tag{};


//输入迭代器：单步向前迭代元素
templage<class T, class Distance>
struct input_iterator{
    //返回类型
    typedef input_iterator_tag iterator_category; 
    //迭代器间距类型
    typedef Distance difference_type;
    //所指对象类型
    typedef T value_type;
    //操作结果类型
    typedef T* pointer;
    //解引用操作结果类型
    typedef T& reference;
}
/*
 * @Author       : mark
 * @Date         : 2020-05-26
 * @copyleft Apache 2.0
 */ 

//输出迭代器：只有写的权利，通常用于返回地址
struct output_iterator{
    typedef output_iterator_tag iterator_category;
    typedef void difference_type;
    typedef void value_type;
    typedef void pointer;
    typedef void reference;
}

/*前向迭代器：可以在一个正确的区间进行读写，单步向前迭代，通常用于遍历
拥有输入迭代器的所有特性，输出迭代器的部分特性*/
temp <class T, class Distance> 
struct forward_iterator{
    typedef forward_iterator_tag iterator_category;
    typedef Distance difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
}

//双向迭代器：向前迭代器 + 单步向后迭代元素
temp <class T, class Distance> 
struct bidirectional_iterator{
    typedef bidirectional_iterator_tag iterator_category;
    typedef Distance difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
}

//随机迭代器：能完成上面所有迭代器的工作，独特特性：可以像指针一样进行算术计算
temp <class T, class Distance> 
struct random_access_iterator{
    typedef random_access_iterator_tag iterator_category;
    typedef Distance difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
}


#endif ITERATOR_H