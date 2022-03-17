<template>
  <div class="container">
    <div class="base-info">
      <img 
        class="info-img"
        :src="imagePath"
        alt="头像"
        >
      <div class="info-name">{{name}}</div>
      <div class="info-intro">{{introduce}}</div>
    </div>
    <div class="info-data">
      <div class="info-data-item">
        <a href="#">
          <div class="info-data-title">Articles</div>
          <div class="info-data-num">5</div>
        </a>
      </div>
      <div class="info-data-item">
        <a href="#">
          <div class="info-data-title">Tags</div>
          <div class="info-data-num">3</div>
        </a>
      </div>
      <div class="info-data-item">
        <a href="#">
          <div class="info-data-title">Categories</div>
          <div class="info-data-num">15</div>
        </a>
      </div>
    </div>
    <a class="hvr-bounce-to-right info-github" target="_blank" href="#">
       <i id="icon-github" class="info-github-icon">
          点我！！！
       </i>
    </a>
    <div class="info-social-icon">
      <i class="icon-github icon"></i>
      <i class="icon-email icon"></i>
      <i class="icon-qq icon"></i>
      <i class="icon-weChat icon"></i>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    name : {
      type : String,
      required : true,
    },
    headPortrait : {
      type : String,
      required : true,
    },
    github : {
      type : [String, Array],
      required : true,
    },
    email : {
      type : String,
      required : true,
    },
    qq : {
      type : String,
      required : true,
    },
    weChat : {
      type : String,
      required : true,
    },
    introduce : {
      type : String,
      required : true,
    },
    articlesNum : {
      type : Number,
      required : true,
    },
    tagsNum : {
      type : Number,
      required : true,
    },
    categoriesNum : {
      type : Number,
      required : true,
    },
    
  },
  data () {
    return {

    }
  },
  computed : {
    imagePath () {
      return require('../icons/jpg/headImg.jpg')
    }
  },
  methods: {

  }
}
</script>

<style scoped>
a{
  display: inline-block;
}

.container{
    background-color: white;
    font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', 'Helvetica Neue', Lato, Roboto, 'PingFang SC', 'Microsoft YaHei', sans-serif;
    line-height: 2;
    -webkit-tap-highlight-color: rgba(0,0,0,0);
    box-sizing: border-box;
    display: flex;
    -webkit-box-orient: horizontal;
    flex-direction: column;
    -webkit-box-align: center;
    align-items: center;
    height: 400px;
    width: 280px;
    border-radius: 12px 8px 8px 12px;
    transition: all 0.3s;
    margin-top: 20px;
    padding: 20px 24px;
}
.container:hover{
  box-shadow: 10px 10px 5px #888888;
}
.base-info{
  height: 200px;
  width: 100%;
  display: flex;
  align-items: center;
  flex-direction: column;

}
.info-img{
  -webkit-tap-highlight-color: rgba(0,0,0,0);
  text-align: center;
  box-sizing: border-box;
  border-width: initial;
  border-color: initial;
  border-image: initial;
  border-style: none;
  max-width: 100%;
  width: 110px;
  height: 110px;
  transition: all 0.5s;
  border-radius: 50%;
  /* border-color: blue;
  border-style: solid; */
  
}
.info-img:hover{
  -webkit-transform: rotate(180deg);
  transform: rotate(180deg);
}
.info-name{
  justify-content: center;
  font-weight: 500;
  font-size: 21px;
}
.info-intro{
  margin-top: 6px;
  color: rgb(133, 133, 133);
}
.info-data{
  width: 100%;
  display: flex;
  flex-direction: row;
  justify-content: space-around;
  color: rgb(133, 133, 133);
  color: black;
}
.info-data-item{

}
.info-data-title{

}
.info-data-num{
  text-align: center;
}
.info-github{
    position: relative;
    z-index: 1;
    transition: color 1s;
    display: flex;
    margin-top: 0.7rem;
    text-align: center;
    height: 20px;
    width: 100%;
    height: 25px;
    align-items: center;
    margin: 5px 0;
    justify-content: center;
}
#icon-github::before{
  background-image: url('../icons/svg/github.svg');
  background-size: 15px 15px;
  background-repeat: no-repeat;
  z-index: 100;
  width: 15px;
  height: 15px;
  content: '';
  display: flex;
}
.info-github-icon {
  display: flex ;
  align-items: center;
  /* line-height: 25px ; */
}
.info-social-icon{
  margin-top: 6px;
  width: 100%;
  display: flex;
  flex-direction: row;
  justify-content: space-around;
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
  content: url('../icons/svg/github.svg');
}
.icon-email{
  content: url("../icons/svg/email.svg");
}
.icon-qq{
  content: url("../icons/svg/qq.svg");
}
.icon-weChat{
  content: url("../icons/svg/weChat.svg");
}
/* 悬浮动画 */
.hvr-bounce-to-right {
  /* display: inline-block;
  vertical-align: middle; */
  -webkit-transform: perspective(1px) translateZ(0);
  transform: perspective(1px) translateZ(0);
  box-shadow: 0 0 1px rgba(0, 0, 0, 0);
  position: relative;
  -webkit-transition-property: color;
  transition-property: color;
  -webkit-transition-duration: 0.5s;
  transition-duration: 0.5s;
  background-color: rgb(73, 177, 245);
}
.hvr-bounce-to-right:before {
  content: "";
  position: absolute;
  z-index: -1;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background: #ff7242;
  -webkit-transform: scaleX(0);
  transform: scaleX(0);
  -webkit-transform-origin: 0 50%;
  transform-origin: 0 50%;
  -webkit-transition-property: transform;
  transition-property: transform;
  -webkit-transition-duration: 0.5s;
  transition-duration: 0.5s;
  -webkit-transition-timing-function: ease-out;
  transition-timing-function: ease-out;
}
.hvr-bounce-to-right:hover, .hvr-bounce-to-right:focus, .hvr-bounce-to-right:active {
  color: white;
}
.hvr-bounce-to-right:hover:before, .hvr-bounce-to-right:focus:before, .hvr-bounce-to-right:active:before {
  -webkit-transform: scaleX(1);
  transform: scaleX(1);
  -webkit-transition-timing-function: cubic-bezier(0.52, 1.64, 0.37, 0.66);
  transition-timing-function: cubic-bezier(0.52, 1.64, 0.37, 0.66);
}



</style>