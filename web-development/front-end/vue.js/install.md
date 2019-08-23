# Install of Vue



### Install Vue-cli

1. Remove old vue-cli

   ```shell
   npm uninstall vue-cli -g
   yarn global remove vue-cli
   ```

   

2. Install npm

3. Install yarn

4. Install vue-cli

   ```shell
   npm install -g @vue/cli
   # OR
   yarn global add @vue/cli
   ```

4. Check version of vue-cli

   ```shell
   vue --version
   ```

   

### Install Prototyping

You can rapidly prototype with just a single `*.vue` file with the `vue serve` and `vue build`commands.

#### require an additional global addon to be installed first:

```shell
npm install -g @vue/cli-service-global
# or
yarn global add @vue/cli-service-global
```

#### vue serve

Running vue application.

- Add an App.vue file

```
<template>
  <h1>Hello!</h1>
</template>
```

  - Run

```
vue serve
or 
vue serve MyComponent.vue
```

#### vue build

You can also build the target file into a production bundle for deployment

```
vue build
or
vue build MyComponent.vue
```



### References

[Vue CLI - doc](https://cli.vuejs.org/guide/#components-of-the-system)

