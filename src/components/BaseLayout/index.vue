<template>
  <div class="base-main">
    <div class="base-main-header">
      <slot name="header"></slot>
    </div>
    <div class="base-main-media">
      <slot name="media"></slot>
    </div>
    <div class="base-main-footer">
      <slot name="footer"></slot>
    </div>
  </div>
</template>

<script>
export default {
  
}
</script>

<style scoped>
.base-main{
  display: flex;
  flex-direction: column;
}
.base-main-header{
  background-color: blue;
}
.base-main-media{
  background-color: red;
}
.base-main-footer{
  background-color: yellow;
}
</style>