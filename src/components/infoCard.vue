<template>
  <div class="container">
    <div class="base-info">
      <img 
        class="info-img"
        :src="headPortrait"
        alt="头像"
        >
      <div class="info-name">{{name}}</div>
      <div class="info-intro">{{introduce}}</div>
    </div>
    <div class="info-data">
    </div>
    <a href="#"></a>
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
    flex-direction: row;
    -webkit-box-align: center;
    align-items: center;
    height: 400px;
    max-width: 380px;
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
  width: 110px;
  height: 110px;
}
.info-main{
  padding: 0 40px;
}
.info-title{
  margin-bottom: 6px;
}
.info-describe{
  margin-top: 6px;
  color: rgb(133, 133, 133);
}
.info-meta{
  display: flex;
  color: rgb(133, 133, 133);
}

.icon{
  display: inline-block;
  vertical-align: middle;
	background-repeat: no-repeat;
  background-position: center center;
  width:15px;
  height: 15px;
}
.info-span{
  margin: 0 6px;
}

</style>