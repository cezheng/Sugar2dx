// Sugar2dx.h
// Copyright (c) 2016 Ce Zheng
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

/**
 *  Syntax sugar to ease the development of cocos2d-x.
 */

#define USING_NS_CC_SUGAR using namespace cocos2d::sugar

namespace cocos2d {
namespace sugar {
/**
 *  No need to write a create function anymore.
 *  Just write init(...) then use this function.
 *
 *  e.g. `MySprite::create(a, b, c);` -> `sugar::create<MySprite>(a, b, c);`
 *  `USING_NS_CC_SUGAR;` if you don't want to write `sugar::`
 *
 *  @param args parameters of init
 *
 *  @return created cocos2d::Ref subclass instance
 */
template <typename T, typename... Args>
typename std::enable_if<std::is_base_of<cocos2d::Ref, T>::value &&
                            std::is_constructible<T>::value,
                        T>::type *
create(Args &&... args) {
  T *ret = new (std::nothrow) T();
  if (ret && ret->init(std::forward<Args>(args)...)) {
    ret->autorelease();
  } else {
    CC_SAFE_DELETE(ret);
  }
  return ret;
}
}
}
