# Sugar2dx

Sweet syntax sugar for cocos2d-x.

This repo is a collection of C++11 syntax sugar for cocos2d-x development. Currently it does not have too much content yet. All contribution is welcomed.

## Setup
We recommend that you add the `Sugar2dx.h` header to your prefix header. For the default template it locates in proj.ios_mac/ios/Prefix.pch

```c
#ifdef __cplusplus
  #include "cocos2d.h"
  #include "Sugar2dx.h"
#endif

```

All the syntax sugar functions are in the `cocos2d::sugar` namespace. There is a macro for using this namespace.
 
```cpp
USING_NS_CC_SUGAR;
```

## Usage

### create

This syntax sugar eliminates the need to write a create function for any cocos2d::Node subclass. 

With this, just write the init(...) method and use the template function to create instances.

For example, with a class like this:

```cpp
class MyNode: public cocos2d::Node {
  bool init(Type1* arg1, Type2* arg2);
};
```

You can create its instances by simply writing:

```cpp
auto myNode = ::create<MyNode>(type1Arg, type2Arg);
```

## License

Sugar2dx is released under the MIT license. See LICENSE for details.