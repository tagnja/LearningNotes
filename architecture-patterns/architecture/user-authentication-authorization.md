# User Authentication and Authorization

Process

- Identity information  

User input userId and password -> encrypt Info by RSA-> Info send to server by https -> Server  decrypt by RSA -> MD5 client password, check md5 string with database password string.

HTTPS, RSA, MD5, MySQL

- Giving Anthentication

Generating Token or Digital Certificate -> return to client, or save on session, local storage, cookie.

JWT, SSL

- Access System

Client Send Request by token in URL or cookie -> Verify token or digital certificate



References

[1] [Java – Digital Signatures example](https://www.mkyong.com/java/java-digital-signatures-example/)