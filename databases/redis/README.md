# Redis



## Set Password

### using redis-cli

```shell
$ ./redis-cli
$ 127.0.0.1:6379> AUTH PASSWORD
(error) ERR Client sent AUTH, but no password is set
$ 127.0.0.1:6379> CONFIG SET requirepass "<your_password>"
OK
$ 127.0.0.1:6379> AUTH <your_password>
Ok
```

### redis configuration file

```
sudo nano /etc/redis/redis.conf 
```

replace

```php
# requirepass foobared
```

with

```php
requirepass YOURPASSPHRASE
```

restart redis

```shell
$ redis-server restart
```

Verify

```shell
$ ./redis-cli
$ 127.0.0.1:6379> set key1 18
(error) NOAUTH Authentication required.
$ 127.0.0.1:6379> auth <your_passowrd>
OK
```



## Remove Password

### using redis-cli

```shell
$ ./redis-cli
$ 127.0.0.1:6379> CONFIG SET requirepass ""
```

