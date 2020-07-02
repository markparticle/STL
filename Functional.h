/*
 * @Author       : mark
 * @Date         : 2020-05-26
 * @copyleft Apache 2.0
 */ 

// 作为一元函数对象的基类，只定义了参数和返回值的类型
template<class T>
struct unary_function{
    typedef T argument_type;
    typedef T result_type;
};

//binary_function:作为二元函数基类，只定义了参数和返回值的类型
template<class T>
struct binary_function{
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef T result_type;
};

//用于返回较小值
template<class T>
struct less{
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
    result_type operator()(const first_argument_type& x, const second_argument_type& y){
        return x < y;
    }
}

//判断是否相等
template<class T>
struct equal_to{
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
    result_type operator()(const first_argument_type& x, const second_argument_type& y){
        return x == y;
    }
}

//判断同一性
template <class T>
struct identity: public unary_function<T>{
    //函数调用操作符
    const T& operator()(const T& x) const {return x;}
}

//判断键值，map会用到
template <class T>
struct select1st: public unary_function<T, typename T::first_type>{
    //函数调用操作符
    const typename T::first_type& operator()(const T& x) const {return x.first;}
}