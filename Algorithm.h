/*
 * @Author       : mark
 * @Date         : 2020-05-26
 * @copyleft Apache 2.0
 */ 

#ifndef ALGORITHM_H
#define ALGORITHM_H

template<class InputIterator, class Distance>
//根据第三参数的不同，使函数形成重载。
//第三参数只是声明型别并未指定参数名称，因为它纯粹只是用来激活重载机制，函数根本不使用该参数。
//而函数的重载过程是发生在编译期，所以函数的运行效率非常高。
void _advance(InputIterator&it, Distance n, input_iterator_tag){
    assert(n >= 0);
    while(n--){
        ++it;
    }
}

void advance(InputIterator& it, Distance n){
    //类似于typeof() 
    typedef typename iterator_traits<InputIterator>::iterator_category iterator_category;
    _advance(it, n, iterator_category());
}

template<class InputIterator>
typename iterator_traits<InputIterator>::difference_type 
_distance(InputIterator first, InputIterator last, input_iterator_tag){
    typename iterator_traits<InputIterator>::difference_type dist = 0;
    while(first++ != last){ //当首地址不等于尾地址
        ++dist;
    }
    return dist;
})

template<class Iterator>
typename iterator_traits<Iterator>::difference_type
distance(Iterator first, Iterator last){
    typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
    return _distance(first, last, iterator_category())
}

#endif ALGORITHM_H