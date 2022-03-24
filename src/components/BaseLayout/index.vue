<template>
<div class="base">
  <div class="base-main-header">
      <slot name="header"></slot>
    </div>
  <!-- <div class="base-main"> -->
    <div class="base-main-medium">
      <div class="base-main-main">
        <slot name="main"></slot>
      </div>
      <div class="base-main-aside">
        <slot name="aside"></slot>
      </div>
    </div>
    <!-- <div class="base-main-footer">
      <slot name="footer"></slot>
    </div> -->
  <!-- </div> -->
</div>
</template>

<script>
export default {
  
}
</script>

<style  scoped>
.base{
  height: 100%;
  width: 100%;
  overflow: auto;
}
.base-main{
  position: relative;
  overflow-y: scroll;
  display: flex;
  flex-direction: column;
  width: 100%;
  height: 100%;
  /* background-color: #fff; */
  padding: 0;
  margin-top: 30px;
}
.base-main-header{
  /* background-color: blue; */
  height: 60px;
  width: 100%;
  position: fixed;
  top: 0;
  z-index: 999;
}
.base-main-medium {
  position: relative;
  /* width: 100%; */
  height: calc(100% - 60px);
  display: flex;
  /* flex: row; */
  align-items: stretch;
  /* max-width: 1200px; */
  /* padding: 0px 15px; */
  overflow-y: overlay;
  overflow-x: auto;
  margin: 0 auto;
  top: 60px;
  padding: 0 60px 0 40px;
}
.base-main-medium::-webkit-scrollbar{
  /* width: 50px; */
  background-color: red;
  width: 10px;
}
.base-main-aside{
  /* background-color: green; */
}
.base-main-main{
  /* background-color: red; */
  /* margin-left: 46px; */
  flex: 1 1 auto;

  /* width: 100%; */
}
.base-main-footer{
  /* background-color: yellow; */
  min-height: 25px;
  max-height: 100px;
}
</style>