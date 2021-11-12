<template>
  <div class="base-main">
    <div class="base-main-header">
      <slot name="header"></slot>
    </div>
    <div class="base-main-medium">
      <div class="base-main-aside">
        <slot name="aside"></slot>
      </div>
      <div class="base-main-main">
        <slot name="main"></slot>
      </div>
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
  position: relative;
  overflow: hidden;
  display: flex;
  flex-direction: column;
  width: 100%;
  height: 100%;
  background-color: #fff;
  padding: 0;
}
.base-main-header{
  background-color: blue;
  max-height: 200px;
  min-height: 50px;
}
.base-main-medium {
  width: 100%;
  height: 100%;
  display: flex;
  /* flex: row; */
  align-items: stretch;
}
.base-main-aside{
  background-color: green;
}
.base-main-main{
  background-color: red;
  flex: 1 1 auto;
}
.base-main-footer{
  background-color: yellow;
  min-height: 50px;
  max-height: 200px;
}
</style>