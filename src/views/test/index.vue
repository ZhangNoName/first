<template>
  <base-layout class="baseLayout">
    <div slot="header" class="header">
      <div class="headerContain">
        <div class="navbar-menu">
          <a class="navbar-item navbar-logo" href="#">Wellcom to my blog ~~</a>
          <div class="navbar-start">
            <a class="navbar-item" href="#">首页</a>
            <a class="navbar-item" href="#">Vue</a>
            <a class="navbar-item" href="#">React</a>
            <a class="navbar-item" href="#">Java</a>
            <a class="navbar-item" href="#">C/C++</a>
            <a class="navbar-item" href="#">MySQL</a>
            <a class="navbar-item" href="#">留言</a>
            <a class="navbar-item" href="#">关于</a>
          </div>
          <div class="navbar-end">
            <a class="navbar-item" target="_blank" href="#">
              <i class="el-icon-search"></i>
            </a>
            <a class="navbar-item" target="_blank" href="#">
              <i class="icon-github"></i>
            </a>
            <a class="navbar-item" target="_blank" href="#">关于</a>
            <a class="navbar-item" target="_blank" href="#">
              <i :class="[mode == 'day'?'el-icon-sunny':'el-icon-moon']"></i>
            </a>
          </div>
        </div>
      </div>
    </div>
    <!-- <div slot="aside" style="width:250px">这是侧边栏</div> -->
    <div slot="main">这是内容</div>
    <div slot="footer">这是下方</div>
  </base-layout>
</template>

<script>
export default {
  data(){
    return {
      mode : "day"
    }
  }
}
</script>

<style scoped>
.baseLayout{
  width: 100%;
  height: 100%;
  position: absolute;
  background-color: white;
}
.header{
  height: 100%;
}
.headerContain{
  height: 60px;
  padding: 0 36px;
  line-height:2;
  display: flex;
  /* justify-content: center; */
  align-items: stretch;
}
.el-menu-item{
  border: 0px;
}
.el-menu.el-menu--horizontal{
  border: 0px;
}
.navbar-menu{
  flex-grow: 1;
  flex-shrink: 0;
  overflow-x: auto;
}
.navbar-logo{
  max-height: 1.75rem;
}
.navbar-menu,.navbar-start,.navbar-end{
    align-items: stretch;
    display: flex;
    padding: 0;
    flex-shrink: 0;
}
.navbar-start{
    justify-content: flex-end;
    margin-right: auto;
}
.navbar-end{
    justify-content: flex-start;
    margin-left: auto;
}
.navbar-item{
    display: flex;
    align-items: center;
    padding: 1.25rem .75rem;
    margin: 0 0;
}
.icon-github{
  content: url("../../assets/github.svg");
  display: inline-block;
  vertical-align: middle;
  
	background-repeat: no-repeat;
  background-position: center center;
  width: 14px;
  height: 14px;
}
</style>