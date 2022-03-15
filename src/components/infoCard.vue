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
    <a class="info-github" target="_blank" href="#">
      <i :class="['icon','info-github-icon']"></i>
    </a>
    <div class="info-social-icon">
      <i class="icon-class icon"></i>
      <i class="icon-class icon"></i>
      <i class="icon-class icon"></i>
      <i class="icon-class icon"></i>
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
      return require('@/assets/headImg.jpg')
    }
  },
  methods: {

  }
}
</script>

<style scoped>
a{
  display: block;
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
  width: 80%;
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
.icon{
  display: inline-block;
  vertical-align: middle;
	background-repeat: no-repeat;
  background-position: center center;
  width:15px;
  height: 15px;
}
.info-github-icon{
    content: url('/assets/github.svg');
}
.info-span{
  margin: 0 6px;
}

</style>