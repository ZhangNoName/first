<template>
  <go-base-layout>
  <div slot="header">这是头部</div>
  <div slot="media">这是表格</div>
  <div slot="footer">这是下方</div>
  </go-base-layout>
</template>

<script>
import index from './BaseLayout/index.vue'
export default {
  components:{
    "GoBaseLayout":index
  }
  
}
</script>

<style scoped>

</style>