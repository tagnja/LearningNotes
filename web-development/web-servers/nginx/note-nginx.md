# Note of Nginx

conf

/etc/nginx/conf.d

The same commands can be used to start / stop / restart the nginx server on a Ubuntu Linux:

```shell
`sudo systemctl start nginx  sudo systemctl stop nginx  sudo systemctl restart nginx`
```

OR

```shell
`sudo service nginx start sudo service nginx stop sudo service nginx restart`
```

OR

```shell
`sudo /etc/init.d/nginx start sudo /etc/init.d/nginx stop sudo /etc/init.d/nginx restart`
```



### Configuration

80. reverse_proxy.conf

```
server
{
	listen 80;
	server_name hot.const520.com;
	location / {
			proxy_redirect off;
			proxy_set_header Host $host;
			proxy_set_header X-Real-IP $remote_addr;
			proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
			proxy_pass http://104.225.148.90:8080;
	}
	access_log /var/log/nginx/hot.const520.com.log;
}
```



443. https_reverse_proxy.conf

```
server {
	listen 443;
	server_name example.com;
	ssl_certificate /etc/letsencrypt/live/example.com/fullchain.pem;
	ssl_certificate_key /etc/letsencrypt/live/example.com/privkey.pem;
	ssl on;
	ssl_session_cache builtin:1000 shared:SSL:10m;
	ssl_protocols TLSv1 TLSv1.1 TLSv1.2;
	ssl_ciphers HIGH:!aNULL:!eNULL:!EXPORT:!CAMELLIA:!DES:!MD5:!PSK:!RC4;
	ssl_prefer_server_ciphers on;
	access_log /var/log/nginx/access.log;
	location / {
		proxy_set_header Host $host;
		proxy_set_header X-Real-IP $remote_addr;
		proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
		proxy_set_header X-Forwarded-Proto $scheme;
		proxy_pass http://localhost:8080;
		proxy_read_timeout 90;
		proxy_redirect http://localhost:8080 https://example.com;
	}
}
```

Reference

[Simple guide to configure Nginx reverse proxy with SSL](https://linuxtechlab.com/simple-guide-to-configure-nginx-reverse-proxy-with-ssl/)