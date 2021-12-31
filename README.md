# PHP C扩展 php-utils

> 这是一个DEMO <br>
> 要求php版本8.1

## 安装扩展
```bash
✔> /usr/local/php81/bin/phpize
Configuring for:
PHP Api Version:         20210902
Zend Module Api No:      20210902
Zend Extension Api No:   420210902
autoconf: warning: both `configure.ac' and `configure.in' are present.
autoconf: warning: proceeding with `configure.ac'.
autoheader: 'configure.ac' and 'configure.in' both present.
autoheader: proceeding with 'configure.ac'

✔> ./configure --with-php-config=/usr/local/php81/bin/php-config
checking for grep that handles long lines and -e... /usr/bin/grep
checking for egrep... /usr/bin/grep -E
checking for a sed that does not truncate output... /usr/bin/sed
checking for pkg-config... /usr/bin/pkg-config
checking pkg-config is at least version 0.9.0... yes
checking for cc... cc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables... 
...
creating libtool
appending configuration tag "CXX" to libtool
configure: patching config.h.in
configure: creating ./config.status
config.status: creating config.h

[18:38:56] jsx@mjq-xiaoneng-xingzheng-test /data/www/jsx/utils/.ext
✔> make
/bin/sh /data/www/jsx/utils/.ext/libtool --mode=install cp ./utils.la /data/www/jsx/utils/.ext/modules
cp ./.libs/utils.so /data/www/jsx/utils/.ext/modules/utils.so
cp ./.libs/utils.lai /data/www/jsx/utils/.ext/modules/utils.la
libtool: install: warning: remember to run `libtool --finish /data/www/jsx/utils/ext/modules'

Build complete.
Don't forget to run 'make test'.

[18:39:03] jsx@mjq-xiaoneng-xingzheng-test /data/www/jsx/utils/.ext
✔> sudo make install
/bin/sh /data/www/jsx/utils/.ext/libtool --mode=install cp ./utils.la /data/www/jsx/utils/.ext/modules
cp ./.libs/utils.so /data/www/jsx/utils/.ext/modules/utils.so
cp ./.libs/utils.lai /data/www/jsx/utils/.ext/modules/utils.la
libtool: install: warning: remember to run `libtool --finish /data/www/jsx/utils/ext/modules'
Installing shared extensions:     /usr/local/php81/lib/php/extensions/no-debug-non-zts-20210902/
Installing header files:          /usr/local/php81/include/php/

# 添加 extension=utils 到 php.ini
```

## PHP调用扩展,测试结果
```php
/**
 * 调用扩展方法
 * IntToChr(int $num)
 * 数字转字母 
 */
echo Utils\Convert::IntToChr(0).PHP_EOL;
echo Utils\Convert::IntToChr(1);
# 输出
A
B
```
