# My Understand of Docker 

### Content

- Basic Concepts
- Dockerfile
- Docker Commands



## I. Basic Concepts

**Dockerfile**: Source code.

**Image**: Binary of compiling and building Dockerfile.

**Container**: Running instance of an image. A process of operating system.

**Docker Host**: A machine running the Docker engine. Images are cached and containers are run by Docker host.

**Registry**: Image are stored in a registry. like a repository for package managers such as `apt`, `npm`. Docker official offers a public registry that anyone can use to store images.



## II. Learning Dockerfile

```
FROM java:8
VOLUME /tmp
ADD build/libs/spring-redis-docker-example.jar spring-redis-docker-example.jar
RUN bash -c 'touch /spring-redis-docker-example.jar'
EXPOSE 8080
ENTRYPOINT ["java","-Djava.security.egd=file:/dev/./urandom","-jar","/spring-redis-docker-example.jar"]
```



## III. Docker Commands

Common Commands

```
docker -v

# build image
docker build -t <your_image_name> .
docker image ls
docker image rm <your_image_name/image_id>
docker images purge

# run with container
docker run -p 8080:8080 <your_image_name/image_id>
docker container ls
docker container stop/kill/rm <container_id>
docker ps -a -f status=exited
docker rm $(docker ps -a -f status=exited -q)

# clean up any resources — images, containers, volumes, and networks
docker system prune
```



### Basic Docker Commands

Docker Info

```
docker --version
docker version
docker info
```

Running Hello-World for test

```
docker run hello-world
```



### Core Docker Commands

Creating a Dockerfile

```
FROM ubuntu
RUN echo "My first Docker image"
```



Build an image from a Dockerfile

```
docker build .
docker build -t <image_tag> .  # Create image using this directory's Dockerfile
```



Running image

```
docker run <image_tag>
docker run <hash>
docker run -p 4000:80 friendlyhello  # Run "friendlyhello" mapping port 4000 to 80
docker run -d -p 4000:80 friendlyhello         # Same thing, but in detached mode
```



### Others Docker Commands

#### Docker Registry

```
docker login             # Log in this CLI session using your Docker credentials
docker tag <image> username/repository:tag  # Tag <image> for upload to registry
docker push username/repository:tag            # Upload tagged image to registry
docker run username/repository:tag                   # Run image from a registry
```

#### Managing image 

List all images in Docker host

```
$ docker images
$ docker image ls
```

Remove 

```
docker image rm <image id>            # Remove specified image from this machine
docker image rm $(docker image ls -a -q)   # Remove all images from this machine
```



#### Managing Container

List all container in Docker Host

```
# running
$ docker container ls
# all
$ docker container ls --all
# all in quiet mode
$ docker container ls -aq
```

Stop

```
docker container stop <hash>           # Gracefully stop the specified container
```

Force shutdown

```
docker container kill <hash>         # Force shutdown of the specified container
```

Remove container from Docker Host

```
docker container rm <hash>        # Remove specified container from this machine
docker container rm $(docker container ls -a -q)         # Remove all containers
```









### References

[1] [Understanding Docker without losing your shit](https://blog.hipolabs.com/understanding-docker-without-losing-your-shit-cf2b30307c63)