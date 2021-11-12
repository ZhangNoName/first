<template>
  <base-layout class="baseLayout">
    <div slot="header" class="header">这是头部</div>
    <div slot="aside" style="width:250px">这是侧边栏</div>
    <div slot="main">这是内容</div>
    <div slot="footer">这是下方</div>
  </base-layout>
</template>

<script>
export default {
  
}
</script>

<style scoped>
.baseLayout{
  width: 100%;
  height: 100%;
  position: absolute;
  background-color: black;
}
.header{
  height: 100%;
}
</style>