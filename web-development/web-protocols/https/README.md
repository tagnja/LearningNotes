# HTTPS 



### Using Certbot to get a Free HTTPS Certificate

You can use Certbot to easily obtain and configure a free certificate from Let’s Encrypt, a joint project of EFF, Mozilla, and many other sponsors.

 installing and running Certbot on a server.

we kindly suggest that you use the Certbot packages provided by your package manager (see [certbot.eff.org](https://certbot.eff.org/)). If such packages are not available, we recommend using `certbot-auto`, which automates the process of installing Certbot on your system.

### System Requirements

requires Python 2.7 or 3.4+ running on a UNIX-like operating system.

### Install Process



### Cert location

```
ssl_certificate /etc/letsencrypt/live/example.com/fullchain.pem;
ssl_certificate_key /etc/letsencrypt/live/example.com/privkey.pem;
```



