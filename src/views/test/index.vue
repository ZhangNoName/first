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
              <i class="icon-search icon"></i>
            </a>
            <a class="navbar-item" target="_blank" href="#">
              <i class="icon-github icon"></i>
            </a>
            <a class="navbar-item" target="_blank" href="#">
              <i class="icon-csdn icon"></i>
            </a>
            <a class="navbar-item" target="_blank" href="#">
              <i :class="[mode == 'day'?'icon-day':'night','icon']"></i>
            </a>
          </div>
        </div>
      </div>
    </div>
    <div slot="aside" style="width:250px">
      
    </div>
    <div slot="main">
      <card
        name="测试项目"
        createTime="2022-01-01"
        describe="第一个测试卡片"
        path="abc"
        label="数据结构"
        classify="js"
        >
      </card>
      <card
        name="测试项目2"
        createTime="2022-02-01"
        describe="第二个测试卡片"
        path="abc"
        label="数据结构"
        classify="js"
        >
      </card>
      <card
        name="测试项目3"
        createTime="2022-03-01"
        describe="第三个测试卡片"
        path="abc"
        label="数据结构"
        classify="js"
        >
      </card>
      <card
        name="测试项目4"
        createTime="2022-03-01"
        describe="第四个测试卡片"
        path="abc"
        label="数据结构"
        classify="js"
        >
      </card>
    </div>
    <!-- <div slot="footer">这是下方</div> -->
  </base-layout>
</template>

<script>
import Card from '../../components/Card.vue'
export default {
  components: { Card },
  data () {
    return {
      mode : "day"
    }
  },
  created () {

  },


}
</script>

<style scoped>
.baseLayout{
  width: 100%;
  height: 100%;
  position: absolute;
  background-color: rgb(245, 245, 245);
}
.header{
  /* height: 100%; */
  width: 100%;
}

.headerContain{
  height: 60px;
  padding: 0 36px;
  line-height:2;
  display: flex;
  justify-content: center;
  align-items: stretch;
  background-color: #fff;
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
.icon{
  display: inline-block;
  vertical-align: middle;
	background-repeat: no-repeat;
  background-position: center center;
  width:25px;
  height: 25px;
}
.icon-github{
  content: url("../../assets/github.svg");
}
.icon-search{
  content: url("../../assets/search.svg");
}
.icon-csdn{
  content: url("../../assets/csdn.svg");
}
.icon-day{
  content: url("../../assets/day.svg");
}
.icon-night{
  content: url("../../assets/night.svg");
}
/* .text {
  position: absolute;
  z-index: 9999999;
  font-weight: bold;
  user-select: none;
}
@keyframes remove {
  100% {
    opacity: 0;
  }
} */
</style>