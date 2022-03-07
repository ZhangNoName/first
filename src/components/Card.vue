<template>
  <div class="container">
    <div class="card-main">
      <a 
        class="card-title" 
        :title="name" 
        :href="path">
        {{name}}
        </a>
      <div class="card-meta">
        <span >
          <i class="icon-time icon"></i>
          <span>created</span>
          <time 
            :datetime="createTime"
            :title="createTime"
            >
            {{createTime}}
            </time>
        </span>
        <span>
          <span class="card-span">|</span>
          <i class="icon-class icon"></i>
          <a 
            class=""
            href="#">
            {{classify}}
          </a>
        </span>
        <span>
          <span class="card-span">|</span>
          <i class="icon-label icon"></i>
          <a 
            class=""
            href="#">
            {{label}}
          </a>
        </span>
      </div>
      <div class="card-describe"> 
        {{describe}}
      </div>
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
    classify : {
      type : String,
      required : true,
    },
    label : {
      type : [String, Array],
      required : true,
    },
    createTime : {
      type : String,
      required : true,
    },
    describe : {
      type : String,
      required : true,
    },
    path : {
      type : String,
      required : true,
    }
  },
  data () {
    return {

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
    height: 280px;
    
    border-radius: 12px 8px 8px 12px;
    transition: all 0.3s;
}
.container:hover{
  box-shadow: 10px 10px 5px #888888;
}
.card-main{
  padding: 0 40px;
}
.card-title{
  margin-bottom: 6px;
}
.card-describe{
  margin-top: 6px;
  color: rgb(133, 133, 133);
}
.card-meta{
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
.icon-time{
  content: url('../assets/cleander.svg');
}
.icon-class{
  content: url("../assets/classify.svg");
}
.icon-label{
  content: url("../assets/label.svg");
}
.card-span{
  margin: 0 6px;
}
</style>