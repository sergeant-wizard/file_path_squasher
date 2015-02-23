squashes file pathes that uses "../" notation to refer to the parent directory.
excepted to work as a monkey patch to avoid android crashes when such notation is used.

expected behaviour :
```cpp
{"aaa/bbb/../ccc.html"    , "aaa/ccc.html"} ,
{"aaa/bbb/../../ccc.html" , "ccc.html"}     ,
{"aaa/../ccc.html"        , "ccc.html"}     ,
{"../ccc.html"            , "../ccc.html"}  ,
{"a/b/../d/../ccc.html"   , "a/ccc.html"}   ,
{"a/b/../../../ccc.html"  , "../ccc.html"}  ,
```
